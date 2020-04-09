#include <cstring>
#include <cmath>
#include <memory>
#include <iostream>
#include <limits>
#include "IVector.h"

// develop on UNIX => no __declspec

namespace  {
#pragma pack(push, 1)
class VectorImpl : public IVector
{
public:
    IVector * clone() const override
    {
        return IVector::createVector(dim, coords, logger);
    }

    double getCoord(size_t index) const override
    {
        if (index >= dim)
            return std::numeric_limits<double>::quiet_NaN();

        return coords[index];
    }

    RESULT_CODE setCoord(size_t index, double value) override
    {
        if (index >= dim)
            return RESULT_CODE::WRONG_ARGUMENT;
        coords[index] = value;
        return RESULT_CODE::SUCCESS;
    }

    size_t getDim() const override
    {
        return dim;
    }

    double norm(NORM norm) const override
    {
        double vecNorm = 0;
        switch (norm) {
        case NORM::NORM_1:
            for (size_t i = 0; i < dim; i++)
                vecNorm += std::abs(coords[i]);
            break;
        case NORM::NORM_2:
            for (size_t i = 0; i < dim; i++)
                vecNorm += coords[i] * coords[i];
            vecNorm = sqrt(vecNorm);
            break;
        case NORM::NORM_INF:
            vecNorm = coords[0];
            for (size_t i = 0; i < dim; i++)
                if (std::abs(coords[i]) > vecNorm)
                    vecNorm = std::abs(coords[i]);
            break;
        }
        return vecNorm;
    }

    ~VectorImpl() override
    {
        auto ptr = reinterpret_cast<char *>(coords) - sizeof(VectorImpl);
        operator delete[](coords, ptr);
    }

    double * getCoords() const
    {
        return coords;
    }

    // coords should be guaranteed alive array for all runtime
    VectorImpl(size_t dim, double *coords, ILogger *pLogger) :
        coords(coords), logger(pLogger), dim(dim)
    {
    }

private:
    double *coords;
    ILogger *logger;
    size_t dim;
};
#pragma pack(pop)
}

IVector * IVector::createVector(size_t dim, double* pData, ILogger *logger)
{
    if (logger == nullptr)
    {
        std::cerr << "No logger mentioned\n";
        return nullptr;
    }

    for (size_t i = 0; i < dim; ++i)
        if (std::isnan(pData[i]))
        {
            logger->log((std::to_string(i) + " component ").c_str(), RESULT_CODE::NAN_VALUE);
            return nullptr;
        }

    size_t size = dim * sizeof(double) + sizeof(VectorImpl);

    char *bulk = new (std::nothrow) char[size];
    if (bulk == nullptr)
    {
        logger->log("Couldn't create bulk", RESULT_CODE::OUT_OF_MEMORY);
        return nullptr;
    }

    memcpy(bulk + sizeof(VectorImpl), pData, sizeof(double) * dim);

    auto vec = new (bulk) VectorImpl(dim, reinterpret_cast<double *>(bulk + sizeof(VectorImpl)), logger);

    return vec;
}

IVector * IVector::add(IVector const* pOperand1, IVector const* pOperand2, ILogger *logger)
{
    if (pOperand1 == nullptr || pOperand2 == nullptr)
    {
        logger->log("in Vector add", RESULT_CODE::WRONG_ARGUMENT);
        return nullptr;
    }

    if (pOperand1->getDim() != pOperand2->getDim())
    {
        logger->log("in Vector add", RESULT_CODE::WRONG_DIM);
        return nullptr;
    }

    auto res = createVector(pOperand1->getDim(), reinterpret_cast<VectorImpl const *>(pOperand1)->getCoords(), logger);

    // no log message cause already called in createVector if needsed
    if (res == nullptr)
        return nullptr;

    for (size_t i = 0; i < res->getDim(); ++i)
        if (res->setCoord(i, pOperand1->getCoord(i) + pOperand2->getCoord(i)) != RESULT_CODE::SUCCESS)
        {
            delete res;
            return nullptr;
        }

    return res;
}

IVector * IVector::sub(IVector const* pOperand1, IVector const* pOperand2, ILogger *logger)
{
    if (pOperand1 == nullptr || pOperand2 == nullptr)
    {
        logger->log("in Vector subtract", RESULT_CODE::WRONG_ARGUMENT);
        return nullptr;
    }

    if (pOperand1->getDim() != pOperand2->getDim())
    {
        logger->log("in Vector subtract", RESULT_CODE::WRONG_DIM);
        return nullptr;
    }

    auto res = createVector(pOperand1->getDim(), reinterpret_cast<VectorImpl const *>(pOperand1)->getCoords(), logger);

    if (res == nullptr)
        return nullptr;

    for (size_t i = 0; i < res->getDim(); ++i)
        if (res->setCoord(i, pOperand1->getCoord(i) - pOperand2->getCoord(i)) != RESULT_CODE::SUCCESS)
        {
            delete res;
            return nullptr;
        }

    return res;
}

IVector * IVector::mul(IVector const* pOperand1, double scaleParam, ILogger *logger)
{
    if (pOperand1 == nullptr)
    {
        logger->log("in Vector multiply", RESULT_CODE::WRONG_ARGUMENT);
        return nullptr;
    }

    auto res = createVector(pOperand1->getDim(), reinterpret_cast<VectorImpl const *>(pOperand1)->getCoords(), logger);

    if (res == nullptr)
        return nullptr;

    for (size_t i = 0; i < res->getDim(); ++i)
        if (res->setCoord(i, pOperand1->getCoord(i) * scaleParam) != RESULT_CODE::SUCCESS)
        {
            delete res;
            return nullptr;
        }

    return res;
}

double IVector::mul(IVector const* pOperand1, IVector const* pOperand2, ILogger *logger)
{
    if (pOperand1 == nullptr || pOperand2 == nullptr)
    {
        logger->log("in Vector multiply", RESULT_CODE::NAN_VALUE);
        return std::numeric_limits<double>::quiet_NaN();
    }

    if (pOperand1->getDim() != pOperand2->getDim())
    {
        logger->log("in Vector multiply", RESULT_CODE::WRONG_DIM);
        return std::numeric_limits<double>::quiet_NaN();
    }

    double res = 0;

    for (size_t i = 0; i < pOperand1->getDim(); ++i)
        res += pOperand1->getCoord(i) * pOperand2->getCoord(i);

    return res;
}

RESULT_CODE IVector::equals(
        IVector const* pOperand1, IVector const* pOperand2,
        NORM norm, double tolerance, bool* result, ILogger* pLogger)
{
    if (pOperand1 == nullptr || pOperand2 == nullptr)
    {
        pLogger->log("in Vector multiply", RESULT_CODE::NAN_VALUE);
        return RESULT_CODE::NAN_VALUE;
    }

    if (pOperand1->getDim() != pOperand2->getDim())
    {
        pLogger->log("in Vector multiply", RESULT_CODE::WRONG_DIM);
        return RESULT_CODE::WRONG_DIM;
    }

    auto diff = sub(pOperand1, pOperand2, pLogger);

    if (diff == nullptr)
        return RESULT_CODE::BAD_REFERENCE;

    *result = diff->norm(norm) < tolerance;
    return RESULT_CODE::SUCCESS;
}
