#include <iostream>
#include "../include/IVector.h"

using namespace std;

void output( IVector *vec )
{
    if (vec == nullptr)
    {
        std::cout << "error\n";
        return;
    }
    for (size_t i = 0; i < vec->getDim(); ++i)
        std::cout << vec->getCoord(i) << ' ';
    std::cout << "\n";
}

int main()
{
    double
            coords1[] = {1., 2., 3., 4., 5.},
            coords2[] = {10., 20., 30., 40., 50.};
    ILogger *logger = ILogger::createLogger((void *)"main");
    IVector
            *v1 = IVector::createVector(5, coords1, logger),
            *v2 = IVector::createVector(5, coords2, logger);

    auto
            sum = IVector::add(v1, v2, logger),
            sub = IVector::sub(v1, v2, logger),
            mul = IVector::mul(v1, 2.0, logger);

    auto dot = IVector::mul(v1, sum, logger);

    std::cout << v2->getCoord(10) << "\n";

    output(sum);
    output(sub);
    output(mul);
    std::cout << dot << "\n";

    IVector *v3 = v1->clone();
    output(v3);

    delete v1;
    delete v2;
    delete v3;
    delete sum;
    delete sub;
    delete mul;

    return 0;
}
