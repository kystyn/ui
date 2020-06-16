#include <iostream>
#include <cmath>
#include <cassert>
#include <array>
#include "../include/ICompact.h"
#include "../include/IVector.h"
#include "../include/ILogger.h"
#include "../include/tester.h"

// uncomment lower define if you want to see iterator work
//#define ITERATE

const double tol = 1e-6;

template<size_t dim1, size_t dim2>
ICompact * createCompact( std::array<double, dim1> const &begAr,
                              std::array<double, dim2> const &endAr,
                              ILogger *logger )
{
    IVector *beg = IVector::createVector(dim1, const_cast<double *>(begAr.data()), logger);
    IVector *end = IVector::createVector(dim2, const_cast<double *>(endAr.data()), logger);

    auto compact = ICompact::createCompact(beg, end, logger);
    delete beg;
    delete end;

    return compact;
}

bool isBadCompact( ICompact *c)
{
    return c == nullptr;
}

ICompact * createCompactWithNull( ILogger *logger )
{
    double data[] = {1, 2, 3};
    auto vec = IVector::createVector(3, data, logger);
    ICompact *c = ICompact::createCompact(nullptr, vec, logger);
    delete vec;
    return c;
}

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

void output( std::string const &text, ICompact *compact )
{
    if (compact == nullptr)
    {
        std::cout << "error\n";
        return;
    }
    std::cout << text << "\nbegin: ";
    output(compact->getBegin());
    std::cout << "end: ";
    output(compact->getEnd());
}

bool istrue( bool f )
{
    return f;
}

template<size_t dim>
bool checkCompactEqual( ICompact *c,
                        std::array<double, dim> const &begAr,
                        std::array<double, dim> const &endAr,
                        ILogger *logger )
{
    if (c == nullptr)
        return false;
    IVector *beg = IVector::createVector(dim, const_cast<double *>(begAr.data()), logger);
    IVector *end = IVector::createVector(dim, const_cast<double *>(endAr.data()), logger);

    bool eq;
    auto gotbeg = c->getBegin();
    auto rc = IVector::equals(gotbeg, beg, IVector::NORM::NORM_2, tol, &eq, logger);
    delete gotbeg;
    if (rc != RESULT_CODE::SUCCESS || !eq)
    {
        delete beg;
        delete end;
        return false;
    }

    auto gotend = c->getEnd();
    rc = IVector::equals(gotend, end, IVector::NORM::NORM_2, tol, &eq, logger);
    delete gotend;

    if (rc != RESULT_CODE::SUCCESS || !eq)
    {
        delete beg;
        delete end;
        return false;
    }

    delete beg;
    delete end;
    return true;
}

int main( int argc, char *argv[] )
{
    ILogger *logger = ILogger::createLogger(argv[0]);

    auto compact1 = createCompact<3, 3>({0, 0, 0}, {1, 1, 1}, logger);
    test("Create good compact 1", checkCompactEqual<3>, compact1, {0, 0, 0}, {1, 1, 1}, logger);
    delete compact1;

    compact1 = createCompact<3, 3>({1, 1, 1}, {0, 0, 0}, logger);
    test("Create good compact 1 (begin >= right)", checkCompactEqual<3>, compact1, {0, 0, 0}, {1, 1, 1}, logger);

    auto compact2 = createCompact<3, 2>({0, 0, 0}, {1, 1}, logger);
    test("Create bad compact (dim mismatch)", isBadCompact, compact2);

    compact2 = createCompact<3, 3>({0, 0, 0}, {1, NAN, 2}, logger);
    test("Create bad compact (NAN)", isBadCompact, compact2);

    compact2 = createCompactWithNull(logger);
    test("Create bad compact (null param)", isBadCompact, compact2);

    compact2 = createCompact<3, 3>({0, 0, 0}, {1, -1, 2}, logger);
    test("Create bad compact (begin !<= right)", isBadCompact, compact2);

    test("Check dimension", istrue, compact1->getDim() == 3);

    compact2 = createCompact<3, 3>({0.5, 0.5, 0.5}, {1, 1, 1}, logger);
    test("Create good compact 2", checkCompactEqual<3>, compact2, {0.5, 0.5, 0.5}, {1, 1, 1}, logger);

    auto unify = ICompact::add(compact1, compact2, logger);
    test("Correct unify 1 2: ", checkCompactEqual<3>, unify, {0, 0, 0}, {1, 1, 1}, logger);
    delete unify;

    auto compact3 = createCompact<3, 3>({0.5, 0.5, 0.5}, {1.5, 1.5, 1.5}, logger);
    test("Create good compact 3", checkCompactEqual<3>, compact3, {0.5, 0.5, 0.5}, {1.5, 1.5, 1.5}, logger);

    unify = ICompact::add(compact1, compact3, logger);
    test("Unify 1 and 3 (no)", isBadCompact, unify);
    delete unify;

    auto convh = ICompact::makeConvex(compact1, compact3, logger);
    test("Convex hull of 1 and 3", checkCompactEqual<3>, convh, {0, 0, 0}, {1.5, 1.5, 1.5}, logger);
    delete convh;

    auto inters = ICompact::intersection(compact3, compact1, logger);
    test("Intersect 3 and 1", checkCompactEqual<3>, inters, {0.5, 0.5, 0.5}, {1, 1, 1}, logger);
    delete inters;

    inters = ICompact::intersection(nullptr, compact1, logger);
    test("Intersect null and 1", isBadCompact, inters);

    inters = ICompact::intersection(compact1, compact2, logger);
    test("Intersect 1 and 2 (easy)", checkCompactEqual<3>, inters, {0.5, 0.5, 0.5}, {1, 1, 1}, logger);
    delete inters;

    auto compact4 = createCompact<3, 3>({0.3, -0.5, -0.5}, {0.4, 1.2, 0.4}, logger);
    test("Create compact 4", checkCompactEqual<3>, compact4, {0.3, -0.5, -0.5}, {0.4, 1.2, 0.4}, logger);

    inters = ICompact::intersection(compact1, compact4, logger);
    test("Intersect 1 and 4 (hard)", checkCompactEqual<3>, inters, {0.3, 0, 0}, {0.4, 1, 0.4}, logger);

    double data[3];
    data[0] = 0.35;
    data[1] = 0.99;
    data[2] = 0.2;

    auto pt = IVector::createVector(3, data, logger);
    bool cntns;
    auto rc = inters->isContains(pt, cntns);

    test("Contains (yes)", istrue, cntns && rc == RESULT_CODE::SUCCESS);

    pt->setCoord(0, 10);
    pt->setCoord(1, 1.1);

    inters->isContains(pt, cntns);
    test("Contains (no)", istrue, !cntns && rc == RESULT_CODE::SUCCESS);
    delete inters;


    auto compact5 = createCompact<3, 3>({2, 2, 2}, {3, 3, 3}, logger);
    inters = ICompact::intersection(compact1, compact5, logger);
    test("Intersect 1 and 5 (no inters)", isBadCompact, inters);
    delete inters;

    auto compact6 = createCompact<3, 3>({0.5, 0, 0}, {1, 1, 1.5}, logger);

    unify = ICompact::add(compact1, compact6, logger);
    test("Unify 1 and 6 (axis parallel but diff)", isBadCompact, unify);
    delete unify;

    auto compact7 = createCompact<3, 3>({0, 0.5, 0}, {1, 1.5, 1}, logger);
    test("Create compact 7", checkCompactEqual<3>, compact7, {0, 0.5, 0}, {1, 1.5, 1}, logger);
    unify = ICompact::add(compact1, compact7, logger);

    test("Unify 1 and 7 (ok)", checkCompactEqual<3>, unify, {0, 0, 0}, {1, 1.5, 1}, logger);

#ifdef ITERATE
    std::cout << "Iteratre intersetion beg->end\n";
    auto it = inters->begin(IVector::createVector(3, data, logger));
    // iterate over compact beg -> end
    for (; IVector::sub(it->getPoint(), inters->getEnd(), logger)->norm(IVector::NORM::NORM_2) > 1e-6; it->doStep())
        output(it->getPoint());

    delete it;

    std::cout << "Iteratre intersetion end->beg\n";
    // iterate over compact end -> beg
    for (it = inters->end(IVector::createVector(3, data, logger));
         IVector::sub(it->getPoint(), inters->getBegin(), logger)->norm(IVector::NORM::NORM_2) > 1e-6; it->doStep())
        output(it->getPoint());

    delete it;

    // iterate with specific direction and other data
    data[0] = 0.07;
    data[1] = 0.13;
    data[2] = 0.15;

    double dirData[] = {2, 0, 1};

    std::cout << "Iteratre intersection beg-> end with order 2 0 1\n";
    it = inters->begin(IVector::createVector(3, data, logger));
    auto dir = IVector::createVector(3, dirData, nullptr);
    it->setDirection(dir);
    for (; IVector::sub(it->getPoint(), inters->getEnd(), logger)->norm(IVector::NORM::NORM_2) > 1e-6; it->doStep())
        output(it->getPoint());

    delete dir;
    delete it;
#endif /* ITERATE */

    logger->destroyLogger(argv[0]);

    delete compact1;
    delete compact2;
    delete compact3;
    delete compact4;
    delete compact5;
    delete compact6;
    delete compact7;
    delete unify;
    delete inters;
    delete pt;

    std::cout << (allPassed ? "ALL TESTS PASSED" : "TESTS FAILED") << "\n";

	return 0;
}
