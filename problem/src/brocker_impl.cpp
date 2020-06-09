#include <new>
#include "include/IBrocker.h"

#ifdef _WIN32
#define DECLSPEC __declspec(dllexport)
#else
#define DECLSPEC
#endif

#include "include/problem_impl.h"

namespace
{
class DECLSPEC BrockerImpl : public IBrocker
{
private:
    BrockerImpl()
    {
        impl = new (std::nothrow) ProblemImpl();
    }

public:
    Type getType() const override
    {
        return Type::PROBLEM;
    }

    void * getInterfaceImpl(Type type) const override
    {
        switch (type)
        {
        case Type::PROBLEM:
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
    ProblemImpl *impl;
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

