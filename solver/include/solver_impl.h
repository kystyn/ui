#ifndef SOLVERIMPL_H
#define SOLVERIMPL_H

#include "include/ISolver.h"

#ifdef _WIN32
#define DECLSPEC __declspec(dllexport)
#else
#define DECLSPEC
#endif

namespace
{
/*
 * Solver param: compact step
 */
class DECLSPEC SolverImpl : public ISolver
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
}


#endif // SOLVERIMPL_H
