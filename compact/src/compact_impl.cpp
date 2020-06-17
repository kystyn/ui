#include <cmath>
#include <cstdlib>
#include <new>
#include <algorithm>
//#include <iostream>

#include "../include/ICompact.h"
#include "../include/IVector.h"

namespace
{
const double tolerance = 1e-6;

bool isLess( IVector const *lhs, IVector const *rhs )
{
    if (lhs->getDim() != rhs->getDim())
        return false;

    for (size_t i = 0; i < lhs->getDim(); i++)
        if (lhs->getCoord(i) > rhs->getCoord(i))
            return false;

    return true;
}

IVector const * min( IVector const *lhs, IVector const *rhs )
{
    if (isLess(lhs, rhs))
        return lhs;
    return rhs;
}

IVector const * max( IVector const *lhs, IVector const *rhs )
{
    if (isLess(lhs, rhs))
        return rhs;
    return lhs;
}

bool isValidData( IVector const * const begin, IVector const * const end )
{
    if (begin == nullptr || end == nullptr)
        return false;

    if (begin->getDim() != end->getDim())
        return false;

    return true;
}

bool isValidData( ICompact const * const begin, ICompact const * const end )
{
    if (begin == nullptr || end == nullptr)
        return false;

    if (begin->getDim() != end->getDim())
        return false;

    return true;
}


class CompactImpl : public ICompact
{
public:
    //class iterator;

    CompactImpl( IVector *left, IVector *right, ILogger *logger ) :
         theLeft(left->clone()), theRight(right->clone()), dim(left->getDim()), logger(logger)
    {
    }

    IVector * getBegin() const override
    {
        return theLeft->clone();
    }

    IVector* getEnd() const override
    {
        return theRight->clone();
    }

    RESULT_CODE isContains(IVector const* const vec, bool& result) const override
    {
        if (vec == nullptr)
        {
            if (logger != nullptr)
                logger->log("isContains: null param", RESULT_CODE::BAD_REFERENCE);
            return RESULT_CODE::BAD_REFERENCE;
        }

        if (vec->getDim() != getDim())
        {
            if (logger != nullptr)
                logger->log("isContains: dimension mismatch", RESULT_CODE::WRONG_DIM);
            return RESULT_CODE::WRONG_DIM;
        }

        result = isLess(theLeft, vec) && isLess(vec, theRight);
        return RESULT_CODE::SUCCESS;
    }

    RESULT_CODE isSubSet(ICompact const* const other, bool& result) const override
    {
        if (!isValidData(this, other))
        {
            logger->log("isSubset: inconsistent <other> param", RESULT_CODE::BAD_REFERENCE);
            return RESULT_CODE::BAD_REFERENCE;
        }

        bool iscontains;
        auto rc = isContains(other->getBegin(), iscontains);
        if (rc != RESULT_CODE::SUCCESS)
        {
            if (logger != nullptr)
                logger->log("isSubset: bad this->getBegin() (?!)", RESULT_CODE::BAD_REFERENCE);
            return rc;
        }

        if (iscontains)
        {
            rc = isContains(other->getEnd(), iscontains);
            if (rc != RESULT_CODE::SUCCESS)
            {
                if (logger != nullptr)
                    logger->log("isSubset: bad this->getEnd() (?!)", RESULT_CODE::BAD_REFERENCE);
                return rc;
            }

            result = iscontains;
        }

        return RESULT_CODE::SUCCESS;
    }

    RESULT_CODE isIntersects(ICompact const* const other, bool& result) const override
    {
        if (!isValidData(this, other))
        {
            if (logger != nullptr)
                logger->log("isIntersects: null param or dimension mismatch", RESULT_CODE::BAD_REFERENCE);
            return RESULT_CODE::BAD_REFERENCE;
        }

        auto
                l = max(theLeft, other->getBegin()),
                r = min(theRight, other->getEnd());

        result = isLess(l, r);
        return RESULT_CODE::SUCCESS;
    }

    size_t getDim() const override
    {
        return dim;
    }

    ICompact* clone() const override
    {
        auto c = new (std::nothrow) CompactImpl(theLeft, theRight, logger);
        if (c == nullptr)
        {
            if (logger != nullptr)
                logger->log("clone: no memory", RESULT_CODE::OUT_OF_MEMORY);
        }
        return c;
    }

    iterator * begin(IVector const* const step = nullptr) override
    {
        auto res = isCorrectStep(step, false);

        if (!res)
        {
            if (logger != nullptr)
                logger->log("begin: incorrect step", RESULT_CODE::WRONG_ARGUMENT);
            return nullptr;
        }

        auto it = new (std::nothrow) iterator(this, step, logger);
        if (it == nullptr)
        {
            if (logger != nullptr)
                logger->log("begin: no memory", RESULT_CODE::OUT_OF_MEMORY);
        }
        return it;
    }

    iterator * end(IVector const* const step = nullptr) override
    {
        auto res = isCorrectStep(step, true);

        if (!res)
        {
            if (logger != nullptr)
                logger->log("begin: incorrect step", RESULT_CODE::WRONG_ARGUMENT);
            return nullptr;
        }

        auto it = new (std::nothrow) iterator(this, step, logger, true);
        if (it == nullptr)
        {
            if (logger != nullptr)
                logger->log("end: no memory", RESULT_CODE::OUT_OF_MEMORY);
        }
        return it;
    }

    ~CompactImpl() override
    {
        delete theLeft;
        delete theRight;
    }

private:
    bool isCorrectStep( IVector const * const step, bool reverse )
    {
        if (step == nullptr)
            return false;

        if (step->getDim() != getDim())
            return false;

        for (size_t i = 0; i < dim; i++)
        {
            if (std::isnan(step->getCoord(i)))
                return false;

            auto crd = step->getCoord(i);
            if (crd < 0 && !reverse ||
                crd > 0 && reverse ||
                std::abs(crd) < tolerance)
                return false;
        }
        return true;
    }

public:
    class iterator : public ICompact::iterator
    {
        friend class CompactImpl;
    public:
        // compact - always available
        iterator( ICompact const *compact, IVector const *step,
                  ILogger *logger, bool reverse = false ) :
            reverse(reverse),
            compact(compact->clone()),
            current(!reverse ? compact->getBegin()->clone() : compact->getEnd()->clone()),
            logger(logger)
        {
            const double stp = tolerance * 10;
            auto dim = compact->getDim();
            double *data = new double[dim];

            if (step == nullptr)
                for (size_t i = 0; i < dim; i++)
                    data[i] = stp;

            this->step = step->clone();

            for (size_t i = 0; i < dim; i++)
                data[i] = i;
            dir = IVector::createVector(compact->getDim(), data, logger);
            delete []data;
        }

        //adds step to current value in iterator
        RESULT_CODE doStep() override
        {
            bool done = false;

            auto
                    begin = compact->getBegin(),
                    end = compact->getEnd();

            bool eq;
            auto rc = !reverse ? IVector::equals(end, current, IVector::NORM::NORM_2, tolerance, &eq, logger) :
                                 IVector::equals(begin, current, IVector::NORM::NORM_2, tolerance, &eq, logger);

            if (eq || rc != RESULT_CODE::SUCCESS)
            {
                delete begin;
                delete end;
                return RESULT_CODE::OUT_OF_BOUNDS;
            }

            IVector *v = current->clone();

            auto dim = compact->getDim();

            // the goal idea:
            // check if it is available to do step along the axis number dir[0]
            // (current[dir[0]] += step[dir[0]])
            // if it is possible - step is done
            // if it it not possible (comapct does not contain such point) -
            //    if current[dir[0]] is end[dir[0]] - try axis dir[1] and so on until
            //    step is done
            //    if current[dir[0]] is not end[dir[0]] - set current[dir[0]] := end[dir[0]]
            // if step was not done - current == end

            for (size_t i = 0; i < dim && !done; i++)
            {
                size_t idx = static_cast<size_t>(std::round(dir->getCoord(i)));

                // we stayed at bound, so go to begin
                if (!reverse)
                {
                    if (std::abs(v->getCoord(idx) - end->getCoord(idx)) < tolerance)
                    {
                        v->setCoord(idx, begin->getCoord(idx));
                        continue;
                    }
                }
                else
                {
                    if (std::abs(v->getCoord(idx) - begin->getCoord(idx)) < tolerance)
                    {
                        v->setCoord(idx, end->getCoord(idx));
                        continue;
                    }
                }

                v->setCoord(idx, v->getCoord(idx) + step->getCoord(idx));

                bool contains;
                auto rc = compact->isContains(v, contains);

                if (rc != RESULT_CODE::SUCCESS)
                {
                    if (logger != nullptr)
                        logger->log("doStep: bad current or step vector", rc);
                    delete v;
                    return rc;
                }

                if (!contains)
                {
                    if (!reverse)
                        v->setCoord(idx, end->getCoord(idx));
                    else
                        v->setCoord(idx, begin->getCoord(idx));
                }

                done = true;
            }

            if (done)
                for (size_t i = 0; i < dim; i++)
                    current->setCoord(i, v->getCoord(i));
            delete v;

            return RESULT_CODE::SUCCESS;
        }

        IVector* getPoint() const override
        {
            return current->clone();
        }

        //change order of step
        RESULT_CODE setDirection(IVector const* const dir) override
        {
            if (dir->getDim() != compact->getDim())
            {
                if (logger != nullptr)
                    logger->log("setDirection: dimension mismatch", RESULT_CODE::WRONG_DIM);
                return RESULT_CODE::WRONG_DIM;
            }

            auto dim = dir ->getDim();

            auto checkUnique = [dir, dim]( size_t idx )
            {
                auto coord = dir->getCoord(idx);
                if (coord < 0 || coord > dim - 1)
                    return false;
                for (size_t i = 0; i < dim; i++)
                {
                    if (i == idx)
                        continue;
                    if (std::abs(dir->getCoord(i) - coord) < tolerance)
                        return false;
                }
                return true;
            };

            for (size_t i = 0; i < dim; i++)
                if (!checkUnique(i))
                {
                    if (logger != nullptr)
                        logger->log("setDirection: direction with repeated coordinates", RESULT_CODE::WRONG_ARGUMENT);
                    return RESULT_CODE::WRONG_ARGUMENT;
                }

            for (size_t i = 0; i < compact->getDim(); i++)
            {
                auto coord = dir->getCoord(i);
                if (std::abs(coord - std::round(coord)) > tolerance)
                {
                    if (logger != nullptr)
                        logger->log("setDirection: direction is integer vector mention order to pass compact",
                                RESULT_CODE::WRONG_ARGUMENT);

                    return RESULT_CODE::WRONG_ARGUMENT;
                }
                this->dir->setCoord(i, dir->getCoord(i));
            }

            delete current;
            current = !reverse ? compact->getBegin() : compact->getEnd();

            return RESULT_CODE::SUCCESS;
        }

        /*dtor*/
        ~iterator() override
        {
            delete dir;
            delete step;
            delete current;
            delete compact;
        }
    private:
        bool reverse;
        ICompact const *compact;
        IVector *current;
        IVector const *step;
        IVector *dir;
        ILogger *logger;
    };

private:
    // begin is always left, end - right
    IVector *theLeft, *theRight;
    size_t dim;
    ILogger *logger;
};
}

ICompact * ICompact::createCompact(IVector const* const begin, IVector const* const end, ILogger* logger)
{
    if (!isValidData(begin, end))
    {
        if (logger != nullptr)
            logger->log("createCompact: null param or vector dimension mismatch", RESULT_CODE::BAD_REFERENCE);
        return nullptr;
    }

    auto lessBegEnd = isLess(begin, end);
    if (!lessBegEnd)
    {
        if (logger != nullptr)
            logger->log("createCompact: bounds are not comparable", RESULT_CODE::WRONG_ARGUMENT);
        return nullptr;
    }

    // always should: begin < end!
    return new (std::nothrow) CompactImpl(const_cast<IVector *>(begin), const_cast<IVector *>(end), logger);
}

ICompact * ICompact::intersection(ICompact const* const left, ICompact const* const right, ILogger* logger)
{
    if (!isValidData(left, right))
    {
        if (logger != nullptr)
            logger->log("intersection: null param or dimension mismatch", RESULT_CODE::BAD_REFERENCE);
        return nullptr;
    }

    auto dim = left->getDim();

    bool inters;
    auto rc = left->isIntersects(right, inters);

    if (rc != RESULT_CODE::SUCCESS)
    {
        if (logger != nullptr)
            logger->log("intersection: smth went wrong", RESULT_CODE::BAD_REFERENCE);
        return nullptr;
    }

    if (inters)
    {
        auto *data = new (std::nothrow) double[dim]{0};
        if (data == nullptr)
        {
            if (logger != nullptr)
                logger->log("intersection: out of memory", RESULT_CODE::OUT_OF_MEMORY);
            return nullptr;
        }
        auto
                l = IVector::createVector(dim, data, logger),
                r = IVector::createVector(dim, data, logger);

	delete []data;

        auto
                lbeg = left->getBegin(),
                rbeg = right->getBegin(),
                lend = left->getEnd(),
                rend = right->getEnd();

        for (size_t i = 0; i < dim; i++)
        {
            l->setCoord(i, std::max(lbeg->getCoord(i), rbeg->getCoord(i)));
            r->setCoord(i, std::min(lend->getCoord(i), rend->getCoord(i)));
        }
        delete lbeg;
        delete lend;
        delete rbeg;
        delete rend;

        auto c = createCompact(l, r, logger);

        delete l;
        delete r;

        return c;
    }

    if (logger != nullptr)
        logger->log("intersecton: cannot intersect", RESULT_CODE::WRONG_ARGUMENT);
    return nullptr;
}

//union
ICompact* ICompact::add(ICompact const* const left, ICompact const* const right, ILogger*logger)
{
    if (!isValidData(left, right) || logger == nullptr)
    {
        if (logger != nullptr)
            logger->log("add: null param or dimension mismatch", RESULT_CODE::BAD_REFERENCE);
        return nullptr;
    }

    // not connected => nullptr
    auto
            lbeg = left->getBegin(),
            rbeg = right->getBegin(),
            lend = left->getEnd(),
            rend = right->getEnd();

    if (isLess(lend, rbeg) || isLess(rend, lbeg))
    {
        delete lbeg;
        delete rbeg;
        delete lend;
        delete rend;
        return nullptr;
    }

    // right in left!!!
    auto compactIsInCompact = []( ICompact const * const lhs, ICompact const * const rhs )
    {
        auto
                lbeg = lhs->getBegin(),
                rbeg = rhs->getBegin(),
                lend = lhs->getEnd(),
                rend = rhs->getEnd();
        bool res =
                isLess(lbeg, rbeg) &&
                isLess(rend, lend);

        delete lbeg;
        delete rbeg;
        delete lend;
        delete rend;

        return res;
    };

    if (compactIsInCompact(left, right))
    {
        delete lbeg;
        delete rbeg;
        delete lend;
        delete rend;

        return left->clone();
    }

    if (compactIsInCompact(right, left))
    {
        delete lbeg;
        delete rbeg;
        delete lend;
        delete rend;

        return right->clone();
    }

    auto dbegin = IVector::sub(lbeg, rbeg, logger);

    if (dbegin == nullptr)
    {
        if (logger != nullptr)
            logger->log("add: nonconsistent begin", RESULT_CODE::WRONG_ARGUMENT);

        delete lbeg;
        delete rbeg;
        delete lend;
        delete rend;

        return nullptr;
    }

    // we check here that vector v is parallel to any axis
    auto checkParallel = []( IVector const * const v , int &axisNo )
    {
        int nonZeroCount = 0;
        double nrm = v->norm(IVector::NORM::NORM_INF);
        for (size_t i = 0; i < v->getDim() && nonZeroCount < 2; i++)
            if (std::abs(v->getCoord(i) / nrm) > tolerance)
            {
                axisNo = i;
                nonZeroCount++;
            }

        if (nonZeroCount > 1)
            return false;

        return true;
    };

    int axisNoBeg, axisNoEnd;
    if (checkParallel(dbegin, axisNoBeg))
    {
        auto dend = IVector::sub(lend, rend, logger);

        if (dend == nullptr)
        {
            if (logger != nullptr)
                logger->log("add: nonconsistent end", RESULT_CODE::WRONG_ARGUMENT);

            delete lbeg;
            delete rbeg;
            delete lend;
            delete rend;

            return nullptr;
        }

        if (checkParallel(dend, axisNoEnd))
            if (axisNoBeg == axisNoEnd)
            {
                delete dbegin;
                delete dend;
                auto c = createCompact(min(lbeg, rbeg), max(lend, rend), logger);

                delete lbeg;
                delete rbeg;
                delete lend;
                delete rend;

                return c;
            }
        delete dend;
    }

    delete dbegin;

    delete lbeg;
    delete rbeg;
    delete lend;
    delete rend;

    if (logger != nullptr)
        logger->log("add: cannot create convex union. Try makeConvex instead", RESULT_CODE::WRONG_ARGUMENT);
    return nullptr;
}

ICompact * ICompact::makeConvex(ICompact const* const left, ICompact const* const right, ILogger*logger)
{
    if (!isValidData(left, right) || logger == nullptr)
    {
        if (logger != nullptr)
            logger->log("makeConvex: null param or dimension mismatch", RESULT_CODE::BAD_REFERENCE);
        return nullptr;
    }

    auto
            lbeg = left->getBegin(),
            rbeg = right->getBegin(),
            lend = left->getEnd(),
            rend = right->getEnd();

    auto c = createCompact(min(lbeg, rbeg),
                         max(lend, rend), logger);

    delete lbeg;
    delete lend;
    delete rbeg;
    delete rend;

    return c;
}
