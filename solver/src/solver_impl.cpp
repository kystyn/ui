#include "include/ISolver.h"

#ifdef _WIN32
#define DECLSPEC __declspec(dllexport)
#else
#define DECLSPEC
#endif

/*
 * Solver param: compact step
 */
class DECLSPEC SolverImpl : public ISolver
{
public:
    SolverImpl() : params(nullptr), problemParams(nullptr), problem(nullptr), compact(nullptr)
    {
        logger = ILogger::createLogger(this);
    }

    RESULT_CODE setParams(IVector const* params) override
    {
        if (params == nullptr)
        {
            if (logger != nullptr)
                logger->log("solver::setParams: null param", RESULT_CODE::BAD_REFERENCE);
            return RESULT_CODE::BAD_REFERENCE;
        }

        if (params->getDim() != 1)
        {
            if (logger != nullptr)
                logger->log("solver::setParams: not 1D param vector", RESULT_CODE::WRONG_DIM);
            return RESULT_CODE::WRONG_DIM;
        }

        if (this->params != nullptr)
            delete this->params;
        this->params = params->clone();

        return RESULT_CODE::SUCCESS;
    }

    RESULT_CODE setParams(QString& str) override
    {
    }

    RESULT_CODE setProblem(IProblem *pProblem) override
    {
        if (pProblem == nullptr)
        {
            if (logger != nullptr)
                logger->log("solver::setProblem: null param", RESULT_CODE::BAD_REFERENCE);
            return RESULT_CODE::BAD_REFERENCE;
        }
        problem = pProblem; // clone???
        return RESULT_CODE::SUCCESS;
    }

    RESULT_CODE setProblemParams(IVector const* params) override
    {
        if (params == nullptr)
        {
            if (logger != nullptr)
                logger->log("solver::setProblemParams: null param", RESULT_CODE::BAD_REFERENCE);
            return RESULT_CODE::BAD_REFERENCE;
        }

        if (this->problemParams != nullptr)
            delete this->problemParams;
        this->problemParams = params->clone();

        return RESULT_CODE::SUCCESS;
    }

    RESULT_CODE setCompact(ICompact *pCompact) override
    {
        if (pCompact == nullptr)
        {
            if (logger != nullptr)
                logger->log("solver::setCompact: null param", RESULT_CODE::BAD_REFERENCE);
            return RESULT_CODE::BAD_REFERENCE;
        }

        if (compact != nullptr)
            delete compact;

        compact = pCompact->clone();

        return RESULT_CODE::SUCCESS;
    }

    size_t getParamsDim() const override
    {
        return params->getDim();
    }

    RESULT_CODE solve() override
    {
        if (!problem->isCompactValid(compact))
        {
            if (logger != nullptr)
                logger->log("solve: not valid compact", RESULT_CODE::WRONG_ARGUMENT);
            return RESULT_CODE::WRONG_ARGUMENT;
        }

        auto it = compact->begin(params);
        if (it == nullptr)
        {
            if (logger != nullptr)
                logger->log("solve: not valid step", RESULT_CODE::WRONG_ARGUMENT);
            return RESULT_CODE::WRONG_ARGUMENT;
        }

        problem->setParams(problemParams);

        auto end = compact->getEnd();
        const double tolerance = 1e-6;

        auto dim = compact->getDim();
        double *data = new (std::nothrow) double[dim];

        if (data == nullptr)
        {
            if (logger != nullptr)
                logger->log("solve: no memory", RESULT_CODE::OUT_OF_MEMORY);
            return RESULT_CODE::OUT_OF_MEMORY;
        }

        IVector *bestSolution = IVector::createVector(dim, data, logger);

        if (bestSolution != nullptr)
        {
            if (logger != nullptr)
                logger->log("solve: smth bad with vector creater", RESULT_CODE::WRONG_ARGUMENT);
            return RESULT_CODE::WRONG_ARGUMENT;
        }

        const double startBestRes = 1e10;
        double bestRes = startBestRes;
        double curRes;
        for (;; it->doStep())
        {
            auto dist = IVector::sub(end, it->getPoint(), logger);

            if (dist == nullptr)
            {
                if (logger != nullptr)
                    logger->log("solve: smth wrong with substraction", RESULT_CODE::WRONG_ARGUMENT);
                return RESULT_CODE::WRONG_ARGUMENT;
            }

            auto rc = problem->goalFunctionByArgs(it->getPoint(), curRes);

            if (rc != RESULT_CODE::SUCCESS)
            {
                if (logger != nullptr)
                    logger->log("solve: smth wrong with goalFunctionByArgs", RESULT_CODE::WRONG_ARGUMENT);
                return RESULT_CODE::WRONG_ARGUMENT;
            }

            if (curRes < bestRes)
            {
                bestRes = curRes;
                auto pt = it->getPoint();
                if (pt == nullptr)
                {
                    if (logger != nullptr)
                        logger->log("solve: smth wrong with goalFunctionByArgs", RESULT_CODE::WRONG_ARGUMENT);
                    return RESULT_CODE::WRONG_ARGUMENT;
                }

                for (size_t i = 0; i < dim; i++)
                    if (bestSolution->setCoord(i, pt->getCoord(i)) != RESULT_CODE::SUCCESS)
                    {
                        if (logger != nullptr)
                            logger->log("solve: smth wrong with setCoord", RESULT_CODE::WRONG_ARGUMENT);
                        return RESULT_CODE::WRONG_ARGUMENT;
                    }
            }

            if (dist->norm(IVector::NORM::NORM_INF) < tolerance)
                break;
        }

        if (std::abs(startBestRes - bestRes) < tolerance)
        {
            logger->log("solve: solution not found", RESULT_CODE::NOT_FOUND);
            return RESULT_CODE::NOT_FOUND;
        }

        if (solution != nullptr)
            delete solution;

        solution = bestSolution->clone();
        delete bestSolution;

        return RESULT_CODE::SUCCESS;
    }

    RESULT_CODE getSolution(IVector * &vec) const override
    {
        if (solution == nullptr)
        {
            logger->log("getSolution: no solution yet", RESULT_CODE::NOT_FOUND);
            return RESULT_CODE::NOT_FOUND;
        }

        vec = solution->clone();
        return RESULT_CODE::SUCCESS;
    }

    ~SolverImpl() override
    {
        delete solution;
        delete params;
        delete problemParams;
        delete compact;
    }

private:
    IVector *solution;
    IVector *params;
    IVector *problemParams;
    ILogger *logger;
    IProblem *problem;
    ICompact *compact;
};
