#include <cmath>
#include "include/problem_impl.h"

namespace
{

RESULT_CODE ProblemImpl::goalFunction(const IVector *args, const IVector *params, double &res) const
{
    if (args == nullptr || params == nullptr)
    {
        if (logger != nullptr)
            logger->log("Problem::goalFunction: null params or args", RESULT_CODE::BAD_REFERENCE);
        return RESULT_CODE::BAD_REFERENCE;
    }

    if (args->getDim() != getArgsDim() || params->getDim() != getParamsDim())
    {
        if (logger != nullptr)
            logger->log("Problem::goalFunction: wrong dimension of arg or param", RESULT_CODE::WRONG_DIM);
        return RESULT_CODE::WRONG_DIM;
    }

    // t is iterator over uniform grid [0; 2 * sqrt(2) * W]
    // - position along vertical wall
    const double sq2 = sqrt(2);
    auto checkAvailable = [sq2, args, params]( double t ) -> bool
    {
        double
                b = args->getCoord(1),
                d = args->getCoord(0);
        double c = d + b * d * d / (t * sqrt(d * d - t * t));
        double y = t + b * d / sqrt(d * d - t * t);
        double x = sqrt(c * c - y * y);

        double ly = sq2 * y * (x * x + x * y) / (c * c + 2 * x * y);
        return ly <= params->getCoord(0) * sq2;
    };

    bool available = true;
    for (double t = 0, maxt = 2 * sq2 * params->getCoord(0);
         t <= maxt; t += (maxt - 1) / params->getCoord(1))
        if (!checkAvailable(t))
        {
            available = false;
            break;
        }

    if (available)
        res = params->getCoord(0) * params->getCoord(1);
    else
        res = 0;

    return RESULT_CODE::SUCCESS;
}

RESULT_CODE ProblemImpl::goalFunctionByArgs(const IVector *args, double &res) const
{
    return goalFunction(args, params, res);
}

size_t ProblemImpl::getArgsDim() const
{
    return 2;
}

size_t ProblemImpl::getParamsDim() const
{
    return 2;
}

RESULT_CODE ProblemImpl::setParams(const IVector *params)
{
    if (params == nullptr)
    {
        if (logger != nullptr)
            logger->log("Problem::setParams: null params", RESULT_CODE::BAD_REFERENCE);
        return RESULT_CODE::BAD_REFERENCE;
    }

    auto dim = getParamsDim();

    if (params->getDim() != dim)
    {
        if (logger != nullptr)
            logger->log("Problem::setParams: wrong dimension of param", RESULT_CODE::WRONG_DIM);
        return RESULT_CODE::WRONG_DIM;
    }

    if (this->params == nullptr)
        this->params = params->clone();
    else
        for (size_t i = 0; i < dim; i++)
            this->params->setCoord(i, params->getCoord(i));

    return RESULT_CODE::SUCCESS;
}

bool ProblemImpl::isCompactValid(const ICompact * const &compact) const
{
    if (compact == nullptr)
    {
        if (logger != nullptr)
            logger->log("Problem::isCompactValid - null compact", RESULT_CODE::BAD_REFERENCE);
        return false;
    }

    auto dim = compact->getDim();
    if (dim != getArgsDim())
    {
        if (logger != nullptr)
            logger->log("Problem::isCompactValid - wrong dim", RESULT_CODE::WRONG_DIM);
        return false;
    }

    auto
            beg = compact->getBegin(),
            end = compact->getEnd();

    const double sq2 = sqrt(2);

    return end->getCoord(0) <= 2 * sq2 * params->getCoord(0) && beg->getCoord(0) >= 0 &&
            end->getCoord(1) <= params->getCoord(0) && beg->getCoord(1) >= 0;
}

ProblemImpl::~ProblemImpl()
{
    delete params;
}

ProblemImpl::ProblemImpl() : params(nullptr)
{
    logger = ILogger::createLogger(this);
}


}
