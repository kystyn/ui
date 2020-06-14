#include <iostream>
#include <cmath>
#include <array>
#include "../include/IVector.h"
#include "../include/tester.h"

using namespace std;

double
        coords1[] = {1., 2., 3., 4., 5.},
        coords2[] = {10., 20., 30., 40., 50.};

IVector *vec3dim = IVector::createVector(3, coords1, nullptr);

const double tol = 1e-6;

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

bool check5Dim( IVector *vec, std::array<double, 5> const &reference )
{
    if (vec == nullptr)
        return false;
    if (vec->getDim() != 5)
        return false;

    if (std::abs(vec->getCoord(0) - reference[0]) < tol &&
        std::abs(vec->getCoord(1) - reference[1]) < tol &&
        std::abs(vec->getCoord(2) - reference[2]) < tol &&
        std::abs(vec->getCoord(3) - reference[3]) < tol &&
        std::abs(vec->getCoord(4) - reference[4]) < tol)
        return true;
    return false;
}

bool vecSum( IVector *sum )
{
    return check5Dim(sum, {11, 22, 33, 44, 55});
}

bool badVec( IVector *vec )
{
    return vec == nullptr;
}

bool vecSub( IVector *sub )
{
    return check5Dim(sub, {-9, -18, -27, -36, -45});
}

bool vecMulNum( IVector *vec )
{
    return check5Dim(vec, {2, 4, 6, 8, 10});
}

bool vecDotVec( double val )
{
    return std::abs(val - 550) < tol;
}

bool badCoord( IVector *vec )
{
    return std::isnan(vec->getCoord(10)) || std::isinf(vec->getCoord(10));
}

bool vecClone( IVector *vec )
{
    return check5Dim(vec, {1, 2, 3, 4, 5});
}

bool vecEquals( IVector *v1, IVector *v2 )
{
    bool eq;
    auto rc = IVector::equals(v1, v2, IVector::NORM::NORM_INF, tol, &eq, nullptr);
    return rc == RESULT_CODE::SUCCESS && eq;
}

bool vecNotEquals( IVector *v1, IVector *v2 )
{
    return !vecEquals(v1, v2);
}

int main( int argc, char *argv[] )
{
    ILogger *logger = ILogger::createLogger(argv[0]);
    IVector
            *v1 = IVector::createVector(5, coords1, logger),
            *v2 = IVector::createVector(5, coords2, logger);

    auto
            goodsum = IVector::add(v1, v2, logger),
            goodsub = IVector::sub(v1, v2, logger),
            goodmul = IVector::mul(v1, 2.0, logger);

    auto
            badsum1 = IVector::add(v1, vec3dim, logger),
            badsub1 = IVector::sub(v1, vec3dim, logger);

    auto
            badsum2 = IVector::add(nullptr, vec3dim, logger),
            badsub2 = IVector::add(v2, nullptr, logger);

    auto gooddot = IVector::mul(v1, v2, logger);
    auto baddot = IVector::mul(v1, vec3dim, logger);

    IVector *v3 = v1->clone();

    test("Sum of compatible vec", vecSum, goodsum);
    test("Sum of incompatible vec", badVec, badsum1);
    test("Sum of null and vec", badVec, badsum2);
    test("Diff of compatible vec", vecSub, goodsub);
    test("Diff of incompatible vec", badVec, badsub1);
    test("Diff of vec and null", badVec, badsub2);
    test("Multiply compatible num", vecMulNum, goodmul);
    test("Not available coord", badCoord, v1);
    test("Dot product of compatible vectors", vecDotVec, gooddot);
    test("Dot product of incompatible vectors", std::isnan, baddot);
    test("Clone", vecClone, v3);
    test("Equals", vecEquals, v1, v3);
    test("Not equals with compatible vec", vecNotEquals, v1, v2);
    test("Not equals with null", vecNotEquals, v1, static_cast<IVector *>(nullptr));

    std::cout << (allPassed ? "ALL TESTS PASSED" : "TESTS FAILED") << "\n";

    delete v1;
    delete v2;
    delete v3;
    delete vec3dim;
    delete goodsum;
    delete goodsub;
    delete goodmul;

    logger->destroyLogger(argv[0]);

    return 0;
}
