#include <iostream>
#include "ISet.h"

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
        s1->insert(IVector::createVector(2, data, logger), IVector::NORM::NORM_2, 1e-6);
    }

    std::cout << "S1\n";
    print(s1);

    for (int i = 0; i < 10; i++) {
        data[0] = i * 4;
        data[1] = i * 6;
        s2->insert(IVector::createVector(2, data, logger), IVector::NORM::NORM_2, 1e-6);
    }

    std::cout << "S2\n";
    print(s2);

    auto unify = ISet::add(s1, s2, IVector::NORM::NORM_2, 1e-6, logger);

    std::cout << "Unify\n";
    print(unify);

    std::cout << "Try add bad dim\n";
    auto res = unify->insert(IVector::createVector(3, data, logger), IVector::NORM::NORM_2, 1e-6);
    std::cout << (res == RESULT_CODE::WRONG_DIM ? "Wrong dim\n" : "test failed\n");

    ISet *s3 = ISet::createSet(logger);

    data[0] = 0;
    data[1] = 0;
    s3->insert(IVector::createVector(2, data, logger), IVector::NORM::NORM_2, 1e-6);

    data[0] = 1;
    data[1] = 1;
    s3->insert(IVector::createVector(2, data, logger), IVector::NORM::NORM_2, 1e-6);

    data[0] = 2;
    data[1] = 3;
    s3->insert(IVector::createVector(2, data, logger), IVector::NORM::NORM_2, 1e-6);

    logger->log("Staying alive", RESULT_CODE::SUCCESS);

    std::cout << "S3\n";
    print(s3);

    auto sub = ISet::sub(s3, unify, IVector::NORM::NORM_2, 1e-6, logger);

    std::cout << "Subtract\n";
    print(sub);

    auto symsub = ISet::symSub(s3, unify, IVector::NORM::NORM_2, 1e-6, logger);

    std::cout << "Symmetric subtract\n";
    print(symsub);

    auto intersect = ISet::intersect(s3, unify, IVector::NORM::NORM_2, 1e-6, logger);

    std::cout << "Intersect\n";
    print(intersect);

    unify->erase(1);

    data[0] = 28;
    data[1] = 42;
    unify->erase(IVector::createVector(2, data, logger), IVector::NORM::NORM_2, 1e-6);
    std::cout << "Unify after erase\n";
    print(unify);

    delete s1;
    delete s2;
    delete unify;
    delete s3;
    delete sub;
    delete symsub;
    delete intersect;

    logger->destroyLogger(argv[0]);

    return 0;
}
