#include <algorithm>
#include <vector>
#include "../include/ISet.h"

namespace
{
class SetImpl : public ISet
{
public:
    SetImpl( ILogger *logger ) : pLogger(logger)
    {}

    ~SetImpl() override
    {

    }

    RESULT_CODE insert( const IVector* pVector, IVector::NORM norm, double tolerance ) override
    {
        IVector *diff;

        if (!elements.empty())
            if (pVector->getDim() != getDim())
            {
                pLogger->log("In Set::insert", RESULT_CODE::WRONG_DIM);
                return RESULT_CODE::WRONG_DIM;
            }

        for (auto elem: elements)
        {
            diff = IVector::sub(pVector, elem, pLogger);
            if (diff == nullptr)
                continue;
            if (diff->norm(norm) < tolerance)
            {
                pLogger->log("In Set::insert", RESULT_CODE::MULTIPLE_DEFINITION);
                return RESULT_CODE::MULTIPLE_DEFINITION;
            }
        }

        elements.push_back(pVector);
        return RESULT_CODE::SUCCESS;
    }

    RESULT_CODE get( IVector*& pVector, size_t index ) const override
    {
        if (index >= elements.size())
        {
            pLogger->log("In Set::get", RESULT_CODE::OUT_OF_BOUNDS);
            return RESULT_CODE::OUT_OF_BOUNDS;
        }

        pVector = const_cast<IVector *>(elements[index]);
        return RESULT_CODE::SUCCESS;
    }

    RESULT_CODE get( IVector*& pVector, IVector const* pSample, IVector::NORM norm, double tolerance ) const override
    {
        IVector *diff;
        for (auto elem: elements)
        {
            diff = IVector::sub(pSample, elem, pLogger);
            if (diff == nullptr)
                continue;
            if (diff->norm(norm) < tolerance)
            {
                pVector = const_cast<IVector *>(elem);
                return RESULT_CODE::SUCCESS;
            }
        }
        pLogger->log("In Set::get", RESULT_CODE::NOT_FOUND);
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
        elements.clear();
    }

    RESULT_CODE erase( size_t index ) override
    {
        if (index >= elements.size())
        {
            pLogger->log("In Set::erase", RESULT_CODE::NOT_FOUND);
            return RESULT_CODE::NOT_FOUND;
        }
        elements.erase(elements.begin() + index);
        return RESULT_CODE::SUCCESS;
    }

    RESULT_CODE erase( IVector const* pSample, IVector::NORM norm, double tolerance ) override
    {
        IVector *diff;
        long searchIdx = 0;
        for (auto elem: elements)
        {
            diff = IVector::sub(pSample, elem, pLogger);
            if (diff == nullptr)
                continue;
            if (diff->norm(norm) < tolerance)
            {
                elements.erase(elements.begin() + searchIdx);
                return RESULT_CODE::SUCCESS;
            }
            searchIdx++;
        }
        pLogger->log("In Set::erase", RESULT_CODE::NOT_FOUND);
        return RESULT_CODE::NOT_FOUND;
    }

    ISet * clone() const override
    {
        SetImpl *set = new SetImpl(pLogger);
        if (set == nullptr)
        {
            pLogger->log("In Set::clone", RESULT_CODE::OUT_OF_MEMORY);
            return nullptr;
        }
        set->elements = elements;
        return set;
    }

protected:
    SetImpl()
    {
        pLogger = ILogger::createLogger(this);
    }
private:
    std::vector<IVector const *> elements;
    ILogger* pLogger;
};
}

ISet * ISet::createSet( ILogger* pLogger )
{
    ISet *set = new SetImpl(pLogger);
    if (set == nullptr)
        pLogger->log("In Set::clone", RESULT_CODE::OUT_OF_MEMORY);
    return set;
}

ISet * ISet::add( ISet const* pOperand1, ISet const* pOperand2, IVector::NORM norm, double tolerance, ILogger* pLogger )
{
    if (pOperand1 == nullptr && pOperand2 == nullptr)
    {
        pLogger->log("Set::add: Both operands null", RESULT_CODE::BAD_REFERENCE);
        return nullptr;
    }

    if (pOperand1 == nullptr)
        return pOperand2->clone();

    if (pOperand2 == nullptr)
        return pOperand1->clone();

    ISet *sum = pOperand1->clone();
    IVector *elem2;

    for (size_t i = 0; i < pOperand2->getSize(); i++)
    {
        pOperand2->get(elem2, i); // guaranteed ok
        sum->insert(elem2, norm, tolerance);
    }

    return sum;
}

ISet * ISet::intersect( ISet const* pOperand1, ISet const* pOperand2, IVector::NORM norm, double tolerance, ILogger* pLogger )
{
    if (pOperand1 == nullptr || pOperand2 == nullptr)
    {
        pLogger->log("Set::intersect: some of operands is null", RESULT_CODE::BAD_REFERENCE);
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
            intersection->insert(elem, norm, tolerance);
    }

    return intersection;
}

ISet * ISet::sub( ISet const* pOperand1, ISet const* pOperand2, IVector::NORM norm, double tolerance, ILogger* pLogger )
{
    if (pOperand1 == nullptr)
    {
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
        pOperand1->get(elem, i); // guaranteed ok
        auto rc = pOperand2->get(elemFound, elem, norm, tolerance);
        if (rc == RESULT_CODE::NOT_FOUND)
            diff->insert(elem, norm, tolerance);
    }

    return diff;
}

ISet * ISet::symSub( ISet const* pOperand1, ISet const* pOperand2, IVector::NORM norm, double tolerance, ILogger* pLogger )
{
    ISet *unified = ISet::add(pOperand1, pOperand2, norm, tolerance, pLogger);
    ISet *intersection = ISet::intersect(pOperand1, pOperand2, norm, tolerance, pLogger);

    return ISet::sub(unified, intersection, norm, tolerance, pLogger);
}
