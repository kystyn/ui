#include <iostream>
#include <cassert>
#include "../include/ICompact.h"
#include "../include/IVector.h"
#include "../include/ILogger.h"

// uncomment lower define if you want to see iterator work
#define ITERATE

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
    output("Compact 1: ", compact1);

    // bad compact
    begin = IVector::createVector(2, data, logger);
    ICompact *compact2 = ICompact::createCompact(begin, end, logger);

    if (compact2 != nullptr)
    {
        std::cout << "created compact2 but should not\n";
        output("Compact 2: ", compact2);
    }

    compact2 = ICompact::createCompact(begin, end, nullptr);
    delete begin;
    if (compact2 != nullptr)
        std::cout << "bad compact2 could not create\n";

    std::cout << "dim compact 1: " << compact1->getDim() << "\n";

    // good compact 2
    data[0] = data[1] = data[2] = 0.5;
    begin = IVector::createVector(3, data, logger);

    if (begin == nullptr)
        std::cout << "begin 0.5 not create\n";

    compact2 = ICompact::createCompact(begin, end, logger);

    if (compact2 == nullptr)
        std::cout << "good compact 2 not create\n";

    output("Compact 2: ", compact2);

    auto unify = ICompact::add(compact1, compact2, logger);

    // unify: one in other
    if (unify == nullptr)
        std::cout << "not unidfied 1 and 2 but should\n";

    output("unify 1 and 2: ", unify);

    // good compact 3
    data[0] = data[1] = data[2] = 1.5;
    end = IVector::createVector(3, data, logger);

    if (end == nullptr)
        std::cout << "end 1.5 not create\n";

    ICompact *compact3 = ICompact::createCompact(begin, end, logger);

    if (compact3 == nullptr)
        std::cout << "compact 3 not create\n";

    output("Compact 3: ", compact3);

    unify = ICompact::add(compact1, compact3, logger);

    if (unify != nullptr)
    {
        std::cout << "no unify but create\n";
        output("Unify 1 and 3:", unify);
    }
    else
    {
        auto convh = ICompact::makeConvex(compact1, compact3, logger);
        if (convh == nullptr)
            std::cout << "smth went wrong makeConvex\n";
        else
            output("Convex hull 1 and 3 compact: ", convh);
    }

    auto inters = ICompact::intersection(compact3, compact1, logger);

    if (inters == nullptr)
        std::cout << "has intersection but not create\n";

    output("Intersection 3 and 1: ", inters);

    data[0] = 0.5;
    data[1] = 1.;
    data[2] = 0.5;
    auto pt = IVector::createVector(3, data, logger);
    bool cntns;
    inters->isContains(pt, cntns);
    std::cout << "Intersection contains 0.5 1. 0.5: " << (cntns ? "yes" : "no") << "\n";

    pt->setCoord(0, 10);
    pt->setCoord(1, 1.1);
    inters->isContains(pt, cntns);
    std::cout << "Intersection contains 10 1.1 0.5: " << (cntns ? "yes" : "no") << "\n";

    data[0] = 0.1;
    data[1] = 0.2;
    data[2] = 0.15;

    //good compact 4
    data[0] = 0.5;
    data[1] = 0;
    data[2] = 0;
    begin = IVector::createVector(3, data, logger);

    data[0] = 1;
    data[1] = 1;
    data[2] = 1.5;
    end = IVector::createVector(3, data, logger);

    auto compact4 = ICompact::createCompact(begin, end, logger);
    delete end;

    if (compact4 == nullptr)
        std::cout << "compact 4 not create\n";

    output("Compact 4: ", compact4);

    unify = ICompact::add(compact1, compact4, logger);
    if (unify != nullptr)
    {
        std::cout << "could not unify 1 and 4 compact but did\n";
        output("unify 1 4: ", unify);
    }

    data[0] = 1.5;
    data[1] = 1;
    data[2] = 1;
    end = IVector::createVector(3, data, logger);

    auto compact5 = ICompact::createCompact(begin, end, logger);
    delete begin;
    delete end;

    if (compact5 == nullptr)
        std::cout << "compact 5 not create\n";

    output("Compact 5: ", compact5);

    unify = ICompact::add(compact1, compact5, logger);
    if (unify != nullptr)
        output("unify 1 5: ", unify);
    else
        std::cout << "could not unify 1 and 5 compact but should\n";


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
    delete unify;
    delete inters;

	return 0;
}
