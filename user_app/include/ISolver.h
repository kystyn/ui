#ifndef ISOLVER_H
#define ISOLVER_H

#include "IVector.h"
#include "IProblem.h"
#include "RC.h"
#include <QString>

#ifdef _WIN32
#define DECLSPEC __declspec(dllimport)
#else
#define DECLSPEC
#endif

class DECLSPEC ISolver
{
public:
    enum InterfaceTypes
    {
        INTERFACE_0,
        DIMENSION_INTERFACE_IMPL
    };

    virtual RESULT_CODE setParams(IVector const* params) = 0;
    /* Grammar:
     * dim = {INT}; step = {DOUBLE[DIM]}
     * example:
     * dim = 3; step = 0.01, 0.02, 0.03
     */
    virtual RESULT_CODE setParams(QString& str) = 0;
    virtual RESULT_CODE setProblem(IProblem *pProblem) = 0;
    virtual RESULT_CODE setProblemParams(IVector const* params) = 0;
    virtual RESULT_CODE setCompact(ICompact * pCompact) = 0;

    virtual size_t getParamsDim() const = 0;

    virtual RESULT_CODE solve() = 0;
    virtual RESULT_CODE getSolution(IVector * &vec)const = 0;

protected:
    virtual ~ISolver() = default;

    ISolver() = default;

private:
    /* no way default copy/assignment */
    ISolver(const ISolver& other) = delete;
    void operator=(const ISolver& other) = delete;
};


#endif // ISOLVER_H
