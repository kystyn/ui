#include <iostream>
#include <cassert>
#include "../include/ICompact.h"
#include "../include/IVector.h"
#include "../include/ILogger.h"

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

int main( int argc, char *argv[] )
{
    ILogger *logger = ILogger::createLogger(argv[0]);

    double data[] = {0, 0, 0};
    IVector *begin = IVector::createVector(3, data, logger);
    if (begin == nullptr)
        std::cout << "not create begin\n";

    data[0] = data[1] = data[2] = 1;

    IVector *end = IVector::createVector(3, data, nullptr);
    if (end == nullptr)
        std::cout << "not create end\n";

    // good compact 1
    std::cout << "good compact\n";
    ICompact *compact1 = ICompact::createCompact(begin, end, logger);

    delete begin;
    if (compact1 == nullptr)
        std::cout << "compact1 not create\n";

    // bad compact
    begin = IVector::createVector(2, data, logger);
    ICompact *compact2 = ICompact::createCompact(begin, end, logger);
    if (compact2 != nullptr)
        std::cout << "created compact2 but should not\n";

    compact2 = ICompact::createCompact(begin, end, nullptr);
    delete begin;
    if (compact2 != nullptr)
        std::cout << "bad compact2 could not create\n";

    std::cout << "dim: " << compact1->getDim() << "\n";

    // good compact 2
    data[0] = data[1] = data[2] = 0.5;
    begin = IVector::createVector(3, data, logger);

    if (begin == nullptr)
        std::cout << "begin 0.5 not create\n";

    compact2 = ICompact::createCompact(begin, end, logger);

    if (compact2 == nullptr)
        std::cout << "good compact 2 not create\n";

    auto unify = ICompact::add(compact1, compact2, logger);

    // unify: one in other
    if (unify == nullptr)
        std::cout << "not unidfied 1 and 2 but should\n";

    // good compact 3
    data[0] = data[1] = data[2] = 1.5;
    end = IVector::createVector(3, data, logger);

    if (end == nullptr)
        std::cout << "end 1.5 not create\n";

    ICompact *compact3 = ICompact::createCompact(begin, end, logger);

    if (compact3 == nullptr)
        std::cout << "compact 3 not create\n";

    unify = ICompact::add(compact1, compact3, logger);

    if (unify != nullptr)
        std::cout << "no unify but create\n";

    auto inters = ICompact::intersection(compact3, compact1, logger);

    if (inters == nullptr)
        std::cout << "has intersection but not create\n";

    data[0] = 0.5;
    data[1] = 1.1;
    data[2] = 0.5;
    auto pt = IVector::createVector(3, data, logger);
    bool cntns;
    inters->isContains(pt, cntns);
    std::cout << "contains: " << cntns << "\n";

    data[0] = 0.1;
    data[1] = 0.2;
    data[2] = 0.15;

    output(inters->getBegin());
    output(inters->getEnd());
    // iterate over compact beg -> end
    for (auto it = inters->begin(IVector::createVector(3, data, logger));
         IVector::sub(it->getPoint(), inters->getEnd(), logger)->norm(IVector::NORM::NORM_2) > 1e-6; it->doStep())
        output(it->getPoint());

    // iterate over compact end -> beg
    for (auto it = inters->end(IVector::createVector(3, data, logger));
         IVector::sub(it->getPoint(), inters->getBegin(), logger)->norm(IVector::NORM::NORM_2) > 1e-6; it->doStep())
        output(it->getPoint());


    // iterate with specific direction and other data
    data[0] = 0.07;
    data[1] = 0.13;
    data[2] = 0.15;

    double dirData[] = {2, 0, 1};

    auto it = inters->begin(IVector::createVector(3, data, logger));
    auto dir = IVector::createVector(3, dirData, nullptr);
    it->setDirection(IVector::createVector(3, dirData, logger));
    for (; IVector::sub(it->getPoint(), inters->getEnd(), logger)->norm(IVector::NORM::NORM_2) > 1e-6; it->doStep())
        output(it->getPoint());

    logger->destroyLogger(argv[0]);
	return 0;
}
