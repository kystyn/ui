#include <cmath>
#include <cstdlib>
#include <new>
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
        return theLeft;
    }

    IVector* getEnd() const override
    {
        return theRight;
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
            // redo!
            IVector *v = current->clone();
            bool done = false;

            auto
                    begin = compact->getBegin(),
                    end = compact->getEnd();
            auto dim = compact->getDim();
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

                // reverse is true => 2 * !reverse - 1 == -1
                // reverse is false => 2 * !reverse -1 == 1
                v->setCoord(idx, v->getCoord(idx) + (2 * !reverse - 1) * step->getCoord(idx));

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
            return current;
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
    if (!lessBegEnd && !isLess(end, begin))
    {
        if (logger != nullptr)
            logger->log("createCompact: bounds are not comparable", RESULT_CODE::WRONG_ARGUMENT);
        return nullptr;
    }

    // always should: begin < end!
    if (lessBegEnd)
        return new (std::nothrow) CompactImpl(const_cast<IVector *>(begin), const_cast<IVector *>(end), logger);
    return new (std::nothrow) CompactImpl(const_cast<IVector *>(end), const_cast<IVector *>(begin), logger);
}

ICompact * ICompact::intersection(ICompact const* const left, ICompact const* const right, ILogger* logger)
{
    if (!isValidData(left, right))
    {
        if (logger != nullptr)
            logger->log("intersection: null param or dimension mismatch", RESULT_CODE::BAD_REFERENCE);
        return nullptr;
    }

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
        auto
                l = max(left->getBegin(), right->getBegin()),
                r = min(left->getEnd(), right->getEnd());
        return createCompact(l, r, logger);
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
    if (isLess(left->getEnd(), right->getBegin()) ||
        isLess(right->getEnd(), left->getBegin()))
        return nullptr;

    // right in left!!!
    auto compactIsInCompact = []( ICompact const * const lhs, ICompact const * const rhs )
    {
        return
                isLess(lhs->getBegin(), rhs->getBegin()) &&
                isLess(rhs->getEnd(), lhs->getEnd());
    };

    if (compactIsInCompact(left, right))
        return left->clone();
    if (compactIsInCompact(right, left))
        return right->clone();

    auto dbegin = IVector::sub(left->getBegin(), right->getBegin(), logger);

    if (dbegin == nullptr)
    {
        if (logger != nullptr)
            logger->log("add: nonconsistent begin", RESULT_CODE::WRONG_ARGUMENT);
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
        auto dend = IVector::sub(left->getEnd(), right->getEnd(), logger);

        if (dend == nullptr)
        {
            if (logger != nullptr)
                logger->log("add: nonconsistent end", RESULT_CODE::WRONG_ARGUMENT);
            return nullptr;
        }

        if (checkParallel(dend, axisNoEnd))
            if (axisNoBeg == axisNoEnd)
                return createCompact(min(left->getBegin(), right->getBegin()),
                                     max(left->getEnd(), right->getEnd()), logger);
    }

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

    return createCompact(min(left->getBegin(), right->getBegin()),
                         max(left->getEnd(), right->getEnd()), logger);
}
