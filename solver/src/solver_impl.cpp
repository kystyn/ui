#include <QStringList>
#include <QRegExp>

#include "include/ISolver.h"
#include "include/IBrocker.h"

namespace
{

/*
 * Solver param: compact step
 */
class SolverImpl : public ISolver
{
public:
    SolverImpl();

    RESULT_CODE setParams(IVector const* params) override;

    RESULT_CODE setParams(QString& str) override;

    RESULT_CODE setProblem(IProblem *pProblem) override;

    RESULT_CODE setProblemParams(IVector const* params) override;

    RESULT_CODE setCompact(ICompact *pCompact) override;

    size_t getParamsDim() const override;

    RESULT_CODE solve() override;

    RESULT_CODE getSolution(IVector * &vec) const override;

    ~SolverImpl() override;

private:
    IVector *solution;
    IVector *params;
    IVector *problemParams;
    ILogger *logger;
    IProblem *problem;
    ICompact *compact;
};

SolverImpl::SolverImpl() :
    solution(nullptr), params(nullptr),
    problemParams(nullptr), problem(nullptr),
    compact(nullptr)
{
    logger = ILogger::createLogger(this);
}

RESULT_CODE SolverImpl::setParams(const IVector *params)
{
    if (params == nullptr)
    {
        if (logger != nullptr)
            logger->log("solver::setParams: null param", RESULT_CODE::BAD_REFERENCE);
        return RESULT_CODE::BAD_REFERENCE;
    }


    if (this->params != nullptr)
        delete this->params;
    this->params = params->clone();

    return RESULT_CODE::SUCCESS;
}

/* Grammar:
 * dim = {INT}; step = {DOUBLE[DIM]}
 * example:
 * dim = 3; step = 0.01, 0.02, 0.03
 */
RESULT_CODE SolverImpl::setParams(QString &str)
{
    struct Grammar
    {
        const QString paramSeparator = ";";
        const QString coordSeparator = ",";
        const QString assign = "=";
        const QString dimension = "dim";
        const QString step = "step";
        const QRegExp ws = QRegExp(QString("\\s"));
        const int paramsCount = 2;
        const int dummy = 0; // for better padding!
    } g;
    auto res = str.split(g.paramSeparator, QString::SplitBehavior::SkipEmptyParts);
    if (res.size() != g.paramsCount)
    {
        if (logger != nullptr)
            logger->log("Bad grammar of params string", RESULT_CODE::WRONG_ARGUMENT);
        return RESULT_CODE::WRONG_ARGUMENT;
    }

    bool ok;
    uint dim = 0;
    double *data = nullptr;
    for (auto str : res)
    {
        auto args = str.split(g.assign, QString::SplitBehavior::SkipEmptyParts);

        if (args.size() != 2)
        {
            if (logger != nullptr)
                logger->log("Bad param grammar: should be KEY = VALUE", RESULT_CODE::WRONG_ARGUMENT);
            return RESULT_CODE::WRONG_ARGUMENT;
        }

        if (args[0].remove(g.ws) == g.dimension)
        {
            dim = args[1].toUInt(&ok);
            if (!ok)
            {
                if (logger != nullptr)
                    logger->log("Bad grammar: dimension should be uint", RESULT_CODE::WRONG_ARGUMENT);
                return RESULT_CODE::WRONG_ARGUMENT;
            }
        }
        else if (args[0].remove(g.ws) == g.step)
        {
            auto stp = args[1].split(g.coordSeparator);

            // here could be check dim == str.size() but we allow user to choose args order
            // if this condition won't be passed, vector will not be created and we will detect it

            auto sz = stp.size();
            data = new (std::nothrow) double[sz];

            for (int i = 0; i < sz; i++)
            {
                data[i] = stp[i].toDouble(&ok);

                if (!ok)
                {
                    if (logger != nullptr)
                        logger->log("Bad grammar: coord should be double", RESULT_CODE::WRONG_ARGUMENT);

                    delete []data;
                    return RESULT_CODE::WRONG_ARGUMENT;
                }
            }
        }
        else
        {
            if (logger != nullptr)
                logger->log("Bad grammar: wrong param name", RESULT_CODE::WRONG_ARGUMENT);
            return RESULT_CODE::WRONG_ARGUMENT;
        }
    }

    IVector *v = IVector::createVector(dim, data, logger);
    delete []data;

    if (v != nullptr)
    {
        params = v;
        return RESULT_CODE::SUCCESS;
    }

    if (logger != nullptr)
        logger->log("Something went wrong while creating param vector", RESULT_CODE::WRONG_ARGUMENT);
    return RESULT_CODE::WRONG_ARGUMENT;
}

RESULT_CODE SolverImpl::setProblem(IProblem *pProblem)
{
    if (pProblem == nullptr)
    {
        if (logger != nullptr)
            logger->log("solver::setProblem: null param", RESULT_CODE::BAD_REFERENCE);
        return RESULT_CODE::BAD_REFERENCE;
    }
    problem = pProblem;
    return RESULT_CODE::SUCCESS;
}

RESULT_CODE SolverImpl::setProblemParams(const IVector *params)
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

RESULT_CODE SolverImpl::setCompact(ICompact *pCompact)
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

size_t SolverImpl::getParamsDim() const
{
    if (params == nullptr)
        return 0;
    return params->getDim();
}

RESULT_CODE SolverImpl::solve()
{
    if (!problem->isCompactValid(compact))
    {
        if (logger != nullptr)
            logger->log("solve: not valid compact", RESULT_CODE::WRONG_ARGUMENT);
        return RESULT_CODE::WRONG_ARGUMENT;
    }

    if (params->getDim() != compact->getDim())
    {
        if (logger != nullptr)
            logger->log("solver::solve: params dimension should beq equal to compact", RESULT_CODE::WRONG_DIM);
        return RESULT_CODE::WRONG_DIM;
    }

    auto it = compact->begin(params);
    if (it == nullptr)
    {
        if (logger != nullptr)
            logger->log("solve: not valid step", RESULT_CODE::WRONG_ARGUMENT);
        return RESULT_CODE::WRONG_ARGUMENT;
    }

    if (problemParams != nullptr)
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
    delete []data;

    if (bestSolution == nullptr)
    {
        if (logger != nullptr)
            logger->log("solve: smth bad with vector created", RESULT_CODE::WRONG_ARGUMENT);
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
        {
            delete dist;
            break;
        }
        delete dist;
    }

    delete it;

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

RESULT_CODE SolverImpl::getSolution(IVector *&vec) const
{
    if (solution == nullptr)
    {
        logger->log("getSolution: no solution yet", RESULT_CODE::NOT_FOUND);
        return RESULT_CODE::NOT_FOUND;
    }

    vec = solution->clone();
    return RESULT_CODE::SUCCESS;
}

SolverImpl::~SolverImpl()
{
    delete solution;
    delete params;
    delete problemParams;
    delete compact;
}

class BrockerImpl : public IBrocker
{
private:
    BrockerImpl()
    {
        impl = new (std::nothrow) SolverImpl();
    }

public:
    Type getType() const override
    {
        return Type::SOLVER;
    }

    void * getInterfaceImpl(Type type) const override
    {
        switch (type)
        {
        case Type::SOLVER:
            return impl;
        default:
            return nullptr;
        }
    }
    void release() override // harakiri
    {
        delete impl;
        impl = nullptr;
    }

    static BrockerImpl * getInstance()
    {
        return instance;
    }

    /*dtor*/
    ~BrockerImpl() override
    {
        delete impl;
    }
private:
    SolverImpl *impl;
    static BrockerImpl *instance;
};

BrockerImpl * BrockerImpl::instance = new BrockerImpl;
}

extern "C"
{

DECLSPEC void * getBrocker()
{
    return BrockerImpl::getInstance();
}

}
