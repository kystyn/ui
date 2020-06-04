#include <cmath>

#include "ICompact.h"
#include "IVector.h"

// TODO : ~iterator, doStep

namespace
{
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
         theLeft(left), theRight(right), dim(left->getDim()), logger(logger)
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
            logger->log("isContains: null param", RESULT_CODE::BAD_REFERENCE);
            return RESULT_CODE::BAD_REFERENCE;
        }

        if (vec->getDim() != getDim())
        {
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
            logger->log("isSubset: bad this->getBegin() (?!)", RESULT_CODE::BAD_REFERENCE);
            return rc;
        }

        if (iscontains)
        {
            rc = isContains(other->getEnd(), iscontains);
            if (rc != RESULT_CODE::SUCCESS)
            {
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
        return new CompactImpl(theLeft, theRight, logger);
    }

    iterator * begin(IVector const* const step = nullptr) override
    {
        return new iterator(this, step, logger);
    }

    iterator * end(IVector const* const step = nullptr) override
    {
        return new iterator(this, step, logger, true);
    }

    class iterator : public ICompact::iterator
    {
        friend class CompactImpl;
    public:
        iterator( ICompact const *compact, IVector const *step,
                  ILogger *logger, bool reverse = false ) :
            reverse(reverse),
            compact(compact->clone()), current(compact->getBegin()->clone()),
            logger(logger)
        {
            if (step == nullptr)
                this->step = nullptr;
            this->step = step->clone();

            auto dim = compact->getDim();
            double *data = new double[dim];

            for (size_t i = 0; i < dim; i++)
                data[i] = i;
            dir = IVector::createVector(compact->getDim(), data, logger);
        }

        //adds step to current value in iterator
        //+step
        RESULT_CODE doStep() override
        {
            // redo!
            auto v = IVector::add(current, step, logger);

            if (v == nullptr)
            {
                logger->log("doStep: bad current or step vector", RESULT_CODE::WRONG_ARGUMENT);
                return RESULT_CODE::WRONG_ARGUMENT;
            }

            bool contains;
            auto rc = compact->isContains(v, contains);
            if (rc != RESULT_CODE::SUCCESS)
            {
                logger->log("doStep: bad current or step vector", rc);
                delete v;
                return rc;
            }

            if (contains) // no mem leaks!
            {
                for (size_t i = 0; i < current->getDim(); i++)
                {
                    rc = current->setCoord(i, v->getCoord(i));
                    if (rc != RESULT_CODE::SUCCESS)
                    {
                        logger->log("doStep: setCoord went wrong", rc);
                        delete v;
                        return rc;
                    }
                }
                delete v;
            }

            return RESULT_CODE::SUCCESS;
        }

        IVector* getPoint() const override
        {
            return current;
        }

        //change order of step
        RESULT_CODE setDirection(IVector const* const dir) override
        {
            const double tolerance = 1e-6;
            if (dir->getDim() != compact->getDim())
            {
                logger->log("setDirection: dimension mismatch", RESULT_CODE::WRONG_DIM);
                return RESULT_CODE::WRONG_DIM;
            }

            for (size_t i = 0; i < compact->getDim(); i++)
            {
                auto coord = dir->getCoord(i);
                if (std::abs(coord - std::round(coord)) > tolerance)
                {
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

ICompact * createCompact(IVector const* const begin, IVector const* const end, ILogger*logger)
{
    if (logger == nullptr)
	std::cerr << "No logger mentioned\n";

    if (!isValidData(begin, end))
    {
        logger->log("createCompact: null param or vector dimension mismatch", RESULT_CODE::BAD_REFERENCE);
        return nullptr;
    }

    auto lessBegEnd = isLess(begin, end);
    if (!lessBegEnd && !isLess(end, begin))
    {
        logger->log("createCompact: bounds are not comparable", RESULT_CODE::WRONG_ARGUMENT);
        return nullptr;
    }

    // always should: begin < end!
    if (lessBegEnd)
        return new (std::nothrow) CompactImpl(const_cast<IVector *>(begin), const_cast<IVector *>(end), logger);
    return new (std::nothrow) CompactImpl(const_cast<IVector *>(end), const_cast<IVector *>(begin), logger);
}

ICompact * intersection(ICompact const* const left, ICompact const* const right, ILogger* logger)
{
    if (!isValidData(left, right))
    {
        logger->log("intersection: null param or dimension mismatch", RESULT_CODE::BAD_REFERENCE);
        return nullptr;
    }

    bool inters;
    auto rc = left->isIntersects(right, inters);

    if (rc != RESULT_CODE::SUCCESS)
    {
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

    logger->log("intersection: cannot intersect", RESULT_CODE::WRONG_ARGUMENT);
    return nullptr;
}

//union
ICompact* add(ICompact const* const left, ICompact const* const right, ILogger*logger)
{
    if (!isValidData(left, right) || logger == nullptr)
    {
        logger->log("add: null param or dimension mismatch", RESULT_CODE::BAD_REFERENCE);
        return nullptr;
    }

    // not connected => nullptr
    if (isLess(left->getEnd(), right->getBegin()) ||
        isLess(right->getEnd(), left->getBegin()))
        return nullptr;

    auto compactIsInCompact = []( ICompact const * const lhs, ICompact const * const rhs )
    {
        return
                isLess(lhs->getBegin(), rhs->getBegin()) &&
                isLess(lhs->getEnd(), rhs->getEnd());
    };

    if (compactIsInCompact(left, right))
        return right->clone();
    if (compactIsInCompact(right, left))
        return left->clone();

    auto dbegin = IVector::sub(left->getBegin(), right->getBegin(), logger);

    if (dbegin == nullptr)
    {
        logger->log("add: nonconsistent begin", RESULT_CODE::WRONG_ARGUMENT);
        return nullptr;
    }

    // we check here that vector v is parallel to any axis
    auto checkParallel = []( IVector const * const v )
    {
        const double tolerance = 1e-6;
        int nonZeroCount = 0;
        double nrm = v->norm(IVector::NORM::NORM_INF);
        for (size_t i = 0; i < v->getDim() && nonZeroCount < 2; i++)
            if (std::abs(v->getCoord(i) / nrm) < tolerance)
                nonZeroCount++;

        if (nonZeroCount >= 2)
            return false;

        return true;
    };

    if (checkParallel(dbegin))
    {
        auto dend = IVector::sub(left->getEnd(), right->getEnd(), logger);

        if (dend == nullptr)
        {
            logger->log("add: nonconsistent end", RESULT_CODE::WRONG_ARGUMENT);
            return nullptr;
        }

        if (checkParallel(dend))
            return createCompact(min(left->getBegin(), right->getBegin()),
                                 max(left->getEnd(), right->getEnd()), logger);
    }

    logger->log("add: cannot create convex union. Try makeConvex instead", RESULT_CODE::WRONG_ARGUMENT);
    return nullptr;
}

ICompact* makeConvex(ICompact const* const left, ICompact const* const right, ILogger*logger)
{
    if (!isValidData(left, right) || logger == nullptr)
    {
        logger->log("makeConvex: null param or dimension mismatch", RESULT_CODE::BAD_REFERENCE);
        return nullptr;
    }

    return createCompact(min(left->getBegin(), right->getBegin()),
                         max(left->getEnd(), right->getEnd()), logger);
}
