#include <iostream>
#include <array>
#include "../include/ISet.h"
#include "../include/tester.h"

void print( ISet *set )
{
    IVector *v;
    for (size_t i = 0; i < set->getSize(); i++)
    {
        auto res = set->get(v, i);
        if (res == RESULT_CODE::SUCCESS)
        {
            std::cout << "(";
            for (size_t n = 0; n < set->getDim(); n++)
                std::cout << v->getCoord(n) << ", ";
            std::cout << ")\n";
        }
        else
            std::cout << "Bad element\n";
    }
}

const double tol = 1e-6;

template<size_t dim>
bool checkEqualVec( IVector *vec, std::array<double, dim> const &reference )
{
    if (vec == nullptr)
        return false;
    if (vec->getDim() != dim)
        return false;

    for (size_t i = 0; i < dim ; i++)
        if (std::abs(vec->getCoord(i) - reference[i]) > tol)
            return false;
    return true;
}

template<size_t setSize, size_t dim>
bool checkEqualSet( ISet *set, std::array<std::array<double, dim>, setSize> const &reference )
{
    IVector *v, *pv;

    if (set->getSize() != setSize)
        return false;

    for (size_t i = 0; i < setSize; i++)
    {
        v = IVector::createVector(dim, const_cast<double *>(reference[i].data()), nullptr);
        auto rc = set->get(pv, v, IVector::NORM::NORM_2, tol);
        if (rc != RESULT_CODE::SUCCESS)
        {
            delete v;
            delete pv;
            return false;
        }

        if (!checkEqualVec(pv, reference[i]))
        {
            delete v;
            delete pv;
            return false;
        }
        delete v;
        delete pv;
    }
    return true;
}

bool set1( ISet *set )
{
    return
            checkEqualSet<10, 2>(set,
            {
                std::array<double, 2>{0., 0.},
                                     {2., 3.},
                                     {4., 6.},
                                     {6., 9.},
                                     {8., 12.},
                                     {10., 15.},
                                     {12., 18.},
                                     {14., 21.},
                                     {16., 24.},
                                     {18., 27.}
            });
}

bool set2( ISet *set )
{
    return
            checkEqualSet<8, 2>(set,
            {
                std::array<double, 2>{0., 0.},
                                     {4., 6.},
                                     {8., 12.},
                                     {12., 18.},
                                     {16., 24.},
                                     {20., 30.},
                                     {24., 36.},
                                     {28., 42.}
            });
}

bool unify12( ISet *set )
{
    return
            checkEqualSet<13, 2>(set,
            {
                std::array<double, 2>{0., 0.},
                                    {2., 3.},
                                    {4., 6.},
                                    {6., 9.},
                                    {8., 12.},
                                    {10., 15.},
                                    {12., 18.},
                                    {14., 21.},
                                    {16., 24.},
                                    {18., 27.},
                                    {20., 30.},
                                    {24., 36.},
                                    {28., 42.}
            });
}

bool unify12_erase( ISet *set )
{
    return
            checkEqualSet<12, 2>(set,
            {
                std::array<double, 2>{0., 0.},
                                    {2., 3.},
                                    {4., 6.},
                                    {6., 9.},
                                    {8., 12.},
                                    {10., 15.},
                                    {12., 18.},
                                    {14., 21.},
                                    {16., 24.},
                                    {18., 27.},
                                    {20., 30.},
                                    {24., 36.}
            });
}

bool symsub12( ISet *set )
{
    return
            checkEqualSet<8, 2>(set,
            {
                std::array<double, 2>{20., 30.},
                                     {24., 36.},
                                     {28., 42.},
                                    {2., 3.},
                                    {6., 9.},
                                    {10., 15.},
                                    {14., 21.},
                                    {18., 27.}
            });
}

bool sub_unify_1( ISet *set )
{
    return
            checkEqualSet<3, 2>(set,
            {
                std::array<double, 2>{20., 30.},
                                     {24., 36.},
                                     {28., 42.}
            });
}

bool intersect12( ISet *set )
{
    return
            checkEqualSet<5, 2>(set,
            {
                std::array<double, 2>{0., 0.},
                                     {4., 6.},
                                     {8., 12.},
                                     {12., 18.},
                                     {16., 24.}
            });
}

bool erase1( ISet *set )
{
    return
            checkEqualSet<9, 2>(set,
            {
                std::array<double, 2>{0., 0.},
                                     {4., 6.},
                                     {6., 9.},
                                     {8., 12.},
                                     {10., 15.},
                                     {12., 18.},
                                     {14., 21.},
                                     {16., 24.},
                                     {18., 27.}
            });
}

bool istrue( bool f )
{
    return f;
}


int main( int argc, char *argv[])
{
    ILogger *logger = ILogger::createLogger(argv[0]);
    if (logger->setLogFile("set.log") != RESULT_CODE::SUCCESS)
        std::cout << "Incorrect log file\n";

    ISet *s1 = ISet::createSet(logger);
    ISet *s2 = ISet::createSet(logger);

    double data[3];

    for (int i = 0; i < 10; i++) {
        data[0] = i * 2;
        data[1] = i * 3;
        auto v = IVector::createVector(2, data, logger);
        s1->insert(v, IVector::NORM::NORM_2, tol);
        delete v;
    }

    for (int i = 0; i < 8; i++) {
        data[0] = i * 4;
        data[1] = i * 6;
        auto v = IVector::createVector(2, data, logger);
        s2->insert(v, IVector::NORM::NORM_2, tol);
        delete v;
    }

    auto unify = ISet::add(s1, s2, IVector::NORM::NORM_2, 1e-6, logger);

    test("Correctly generated set1", set1, s1);
    test("Correctly generated set2", set2, s2);
    test("Unify set1 and set2", unify12, unify);

    data[2] = 10;
    auto v = IVector::createVector(3, data, logger);
    auto insBadDim = unify->insert(v, IVector::NORM::NORM_2, 1e-6);
    delete v;

    test("Bad dim insert (check RC)", istrue, insBadDim != RESULT_CODE::SUCCESS);
    test("Bad dim insert (check save content)", unify12, unify);

    auto insNull = unify->insert(nullptr, IVector::NORM::NORM_2, 1e-6);

    test("Insert null (check RC)", istrue, insNull != RESULT_CODE::SUCCESS);
    test("Bad dim insert (check save content)", unify12, unify);

    ISet *s3 = unify->clone();
    test("Clone", unify12, s3);

    auto sub = ISet::sub(s3, s1, IVector::NORM::NORM_2, 1e-6, logger);
    test("Sub", sub_unify_1, sub);
    delete sub;

    sub = ISet::sub(nullptr, s1, IVector::NORM::NORM_2, 1e-6, logger);
    test("Sub from null", istrue, sub == nullptr);

    auto symsub = ISet::symSub(s1, s2, IVector::NORM::NORM_2, 1e-6, logger);
    test("Symm sub", symsub12, symsub);
    delete symsub;

    symsub = ISet::symSub(s1, nullptr, IVector::NORM::NORM_2, 1e-6, logger);
    test("Sym sub with null", set1, s1);
    delete symsub;

    auto intersect = ISet::intersect(s1, s2, IVector::NORM::NORM_2, 1e-6, logger);
    test("Intersect", intersect12, intersect);
    delete intersect;

    intersect = ISet::intersect(nullptr, s2, IVector::NORM::NORM_2, 1e-6, logger);
    test("Intersect with null", istrue, intersect == nullptr);

    s1->erase(1);
    test("Erase by compatible idx", erase1, s1);

    data[0] = 28;
    data[1] = 42;
    v = IVector::createVector(2, data, logger);
    unify->erase(v, IVector::NORM::NORM_2, 1e-6);
    delete v;

    test("Erase by value", unify12_erase, unify);

    auto errc = s1->erase(1000);

    test("Erase by bad idx (check RC)", istrue, errc != RESULT_CODE::SUCCESS);
    test("Erase by bad idx (check save content)", erase1, s1);

    std::cout << (allPassed ? "ALL TESTS PASSED" : "TESTS FAILED") << "\n";

    delete s1;
    delete s2;
    delete unify;
    delete s3;
    delete intersect;

    logger->destroyLogger(argv[0]);

    return 0;
}
