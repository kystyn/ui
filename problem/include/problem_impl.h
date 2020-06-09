#ifndef PROBLEMIMPL_H_
#define PROBLEMIMPL_H_

#ifdef _WIN32
#define DECLSPEC __declspec(dllexport)
#else
#define DECLSPEC
#endif

#include "IProblem.h"

namespace
{
/* Sofa problem for rectangular shape
 * Problem: find such D and B that rectangular ship
 * with length D and width B will be able to pass
 * 90-degree turn of channel with width W (param)
 *
 * arg: (D, B)
 * param: (W, Tc)
 * where
 * Tc - count of positions in the turn
 */
class DECLSPEC ProblemImpl : public IProblem
{
public:
    //args - x , params - coef
    // args - width and heigh
    RESULT_CODE goalFunction(IVector const* args, IVector const* params, double& res) const override;
    RESULT_CODE goalFunctionByArgs(IVector const*  args, double& res) const override;
    size_t getArgsDim() const override;
    size_t getParamsDim() const override;

    RESULT_CODE setParams(IVector const* params) override;
    bool isCompactValid(ICompact const * const & compact) const override;

    ~ProblemImpl() override;

    ProblemImpl();

private:
    ILogger *logger;
    IVector *params;
};
}

#endif /* PROBLEMIMPL_H_ */
