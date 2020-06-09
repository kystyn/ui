#include <new>
#include "include/IBrocker.h"

#ifdef _WIN32
#define DECLSPEC __declspec(dllexport)
#else
#define DECLSPEC
#endif

#include "include/solver_impl.h"

namespace
{
class DECLSPEC BrockerImpl : public IBrocker
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
