#include <algorithm>
#include <new>
#include <cmath>
#include <vector>
#include "../include/ISet.h"

namespace
{
class SetImpl : public ISet
{
public:
    SetImpl( ILogger *logger ) : logger(logger)
    {}

    ~SetImpl() override
    {
        clear();
    }

    RESULT_CODE insert( const IVector* pVector, IVector::NORM norm, double tolerance ) override
    {
        IVector *diff;

	if (std::isnan(tolerance) || tolerance < 0)
	{
	    if (logger != nullptr)
		logger->log("In set::insert: NAN tolerance", RESULT_CODE::NAN_VALUE);
	    return RESULT_CODE::NAN_VALUE;
	}

        if (pVector == nullptr)
        {
            if (logger != nullptr)
                logger->log("In Set::insert: null param", RESULT_CODE::BAD_REFERENCE);
            return RESULT_CODE::BAD_REFERENCE;
        }

        if (!elements.empty())
            if (pVector->getDim() != getDim())
            {
                if (logger != nullptr)
                    logger->log("In Set::insert", RESULT_CODE::WRONG_DIM);
                return RESULT_CODE::WRONG_DIM;
            }

        for (auto elem: elements)
        {
            diff = IVector::sub(pVector, elem, logger);
            if (diff == nullptr)
                continue;
            if (diff->norm(norm) < tolerance)
            {
                if (logger != nullptr)
                    logger->log("In Set::insert", RESULT_CODE::MULTIPLE_DEFINITION);
                delete diff;
                return RESULT_CODE::MULTIPLE_DEFINITION;
            }
            delete diff;
        }

        elements.push_back(pVector->clone());
        return RESULT_CODE::SUCCESS;
    }

    RESULT_CODE get( IVector*& pVector, size_t index ) const override
    {
        if (index >= elements.size())
        {
            if (logger != nullptr)
                logger->log("In Set::get", RESULT_CODE::OUT_OF_BOUNDS);
            return RESULT_CODE::OUT_OF_BOUNDS;
        }

        pVector = const_cast<IVector *>(elements[index]->clone());
        return RESULT_CODE::SUCCESS;
    }

    RESULT_CODE get( IVector*& pVector, IVector const* pSample, IVector::NORM norm, double tolerance ) const override
    {
	if (std::isnan(tolerance) || tolerance < 0)
	{
	    if (logger != nullptr)
		logger->log("In set::insert: NAN tolerance", RESULT_CODE::NAN_VALUE);
	    return RESULT_CODE::NAN_VALUE;
	}

        if (pSample == nullptr)
        {
            if (logger != nullptr)
                logger->log("set::get: null param", RESULT_CODE::BAD_REFERENCE);
            return RESULT_CODE::BAD_REFERENCE;
        }

        if (pSample->getDim() != getDim())
        {
            if (logger != nullptr)
                logger->log("set::get: null param", RESULT_CODE::BAD_REFERENCE);
            return RESULT_CODE::BAD_REFERENCE;
        }

        IVector *diff = nullptr;

        for (auto elem: elements)
        {
            diff = IVector::sub(pSample, elem, logger);
            if (diff == nullptr)
            {
                if (logger != nullptr)
                    logger->log("set::et: unexpected situatuion ?!", RESULT_CODE::BAD_REFERENCE);
                return RESULT_CODE::BAD_REFERENCE;
            }

            if (diff->norm(norm) < tolerance)
            {
                pVector = const_cast<IVector *>(elem->clone());
                delete diff;
                return RESULT_CODE::SUCCESS;
            }
            delete diff;
        }

        if (logger != nullptr)
            logger->log("In Set::get", RESULT_CODE::NOT_FOUND);
        return RESULT_CODE::NOT_FOUND;
    }

    size_t getDim() const override //space dimension
    {
        if (elements.empty())
            return 0;
        return elements[0]->getDim();
    }

    size_t getSize() const override //num elements in set
    {
        return elements.size();
    }

    void clear() override // delete all
    {
        for (auto &el: elements)
            delete el;
        elements.clear();
    }

    RESULT_CODE erase( size_t index ) override
    {
        if (index >= elements.size())
        {
           if (logger != nullptr)
                logger->log("In Set::erase", RESULT_CODE::NOT_FOUND);
            return RESULT_CODE::NOT_FOUND;
        }
        auto itToDel = elements.begin() + index;
        if (*itToDel != nullptr)
            delete *itToDel;
        elements.erase(itToDel);
        return RESULT_CODE::SUCCESS;
    }

    RESULT_CODE erase( IVector const* pSample, IVector::NORM norm, double tolerance ) override
    {
	if (std::isnan(tolerance) || tolerance < 0)
	{
	    if (logger != nullptr)
		logger->log("In set::insert: NAN tolerance", RESULT_CODE::NAN_VALUE);
	    return RESULT_CODE::NAN_VALUE;
	}

        IVector *diff = nullptr;
        long searchIdx = 0;
        for (auto elem: elements)
        {
            diff = IVector::sub(pSample, elem, logger);
            if (diff == nullptr)
                break;
            if (diff->norm(norm) < tolerance)
            {
                delete diff;
                delete *(elements.begin() + searchIdx);
                elements.erase(elements.begin() + searchIdx);
                return RESULT_CODE::SUCCESS;
            }
            delete diff;
            searchIdx++;
        }
        if (logger != nullptr)
            logger->log("In Set::erase", RESULT_CODE::NOT_FOUND);
        return RESULT_CODE::NOT_FOUND;
    }

    ISet * clone() const override
    {
        SetImpl *set = new (std::nothrow) SetImpl(logger);
        if (set == nullptr)
        {
            if (logger != nullptr)
                logger->log("In Set::clone", RESULT_CODE::OUT_OF_MEMORY);
            return nullptr;
        }

        auto n = elements.size();
        set->elements.resize(n);

        for (size_t i = 0; i < n; i++)
            set->elements[i] = elements[i]->clone();
        return set;
    }

private:
    std::vector<IVector const *> elements;
    ILogger* logger;
};
}

ISet * ISet::createSet( ILogger* pLogger )
{
    ISet *set = new (std::nothrow) SetImpl(pLogger);
    if (set == nullptr)
        pLogger->log("In Set::clone", RESULT_CODE::OUT_OF_MEMORY);
    return set;
}

ISet * ISet::add( ISet const* pOperand1, ISet const* pOperand2, IVector::NORM norm, double tolerance, ILogger* pLogger )
{
    if (std::isnan(tolerance) || tolerance < 0)
    {
        if (pLogger != nullptr)
	    pLogger->log("In set::insert: NAN tolerance", RESULT_CODE::NAN_VALUE);
	return nullptr;
    }

    if (pOperand1 == nullptr && pOperand2 == nullptr)
    {
        if (pLogger != nullptr)
            pLogger->log("Set::add: Both operands null", RESULT_CODE::BAD_REFERENCE);
        return nullptr;
    }

    if (pOperand1 == nullptr)
    {
        if (pOperand2 != nullptr)
            return pOperand2->clone();
	return nullptr;
    }

    if (pOperand2 == nullptr)
    {
	if (pOperand1 != nullptr)
            return pOperand1->clone();
	return nullptr;
    }

    if (pOperand1->getDim() != pOperand2->getDim())
    {
        if (pLogger != nullptr)
            pLogger->log("In set::add: dim mismatch", RESULT_CODE::WRONG_DIM);
	return nullptr;
    }
   
    ISet *sum = pOperand1->clone();
    IVector *elem2;

    for (size_t i = 0; i < pOperand2->getSize(); i++)
    {
        pOperand2->get(elem2, i); // guaranteed ok
        sum->insert(elem2, norm, tolerance);
        delete elem2;
    }

    return sum;
}

ISet * ISet::intersect( ISet const* pOperand1, ISet const* pOperand2, IVector::NORM norm, double tolerance, ILogger* pLogger )
{
    if (std::isnan(tolerance) || tolerance < 0)
    {
        if (pLogger != nullptr)
            pLogger->log("In set::insert: NAN tolerance", RESULT_CODE::NAN_VALUE);
	return nullptr;
    }

    if (pOperand1 == nullptr || pOperand2 == nullptr)
    {
        if (pLogger != nullptr)
            pLogger->log("Set::intersect: some of operands is null", RESULT_CODE::BAD_REFERENCE);
        return nullptr;
    }

    if (pOperand1->getDim() != pOperand2->getDim())
    {
        if (pLogger != nullptr)
            pLogger->log("Set::intersect: dim mismatch", RESULT_CODE::WRONG_DIM);
        return nullptr;
    }


    ISet *intersection = ISet::createSet(pLogger);

    if (intersection == nullptr)
        return nullptr;

    IVector *elem, *elemFound;
    for (size_t i = 0; i < pOperand2->getSize(); i++)
    {
        pOperand2->get(elem, i); // guaranteed ok

        auto rc = pOperand1->get(elemFound, elem, norm, tolerance);
        if (rc == RESULT_CODE::SUCCESS)
        {
            intersection->insert(elem, norm, tolerance);
            delete elemFound;
        }
        delete elem;
    }

    return intersection;
}

ISet * ISet::sub( ISet const* pOperand1, ISet const* pOperand2, IVector::NORM norm, double tolerance, ILogger* pLogger )
{
    if (std::isnan(tolerance) || tolerance < 0)
    {
        if (pLogger != nullptr)
            pLogger->log("In set::insert: NAN tolerance", RESULT_CODE::NAN_VALUE);
	return nullptr;
    }


    if (pOperand1 == nullptr)
    {
	if (pLogger != nullptr)
            pLogger->log("Set::subtract: operand is null", RESULT_CODE::BAD_REFERENCE);
        return nullptr;
    }

    if (pOperand2 == nullptr)
        return pOperand1->clone();

    ISet *diff = ISet::createSet(pLogger);

    if (diff == nullptr)
        return nullptr;

    IVector *elem, *elemFound;
    for (size_t i = 0; i < pOperand1->getSize(); i++)
    {
        elemFound = nullptr;
        pOperand1->get(elem, i); // guaranteed ok
        auto rc = pOperand2->get(elemFound, elem, norm, tolerance);
        if (rc == RESULT_CODE::NOT_FOUND)
            diff->insert(elem, norm, tolerance);
        delete elem;
        delete elemFound;
    }

    return diff;
}

ISet * ISet::symSub( ISet const* pOperand1, ISet const* pOperand2, IVector::NORM norm, double tolerance, ILogger* pLogger )
{
    if (std::isnan(tolerance) || tolerance < 0)
    {
        if (pLogger != nullptr)
            pLogger->log("In set::insert: NAN tolerance", RESULT_CODE::NAN_VALUE);
	return nullptr;
    }

    ISet *unified = ISet::add(pOperand1, pOperand2, norm, tolerance, pLogger);
    ISet *intersection = ISet::intersect(pOperand1, pOperand2, norm, tolerance, pLogger);

    auto symsub = ISet::sub(unified, intersection, norm, tolerance, pLogger);
    delete unified;
    delete intersection;
    return symsub;
}
