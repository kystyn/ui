#include <iostream>
#include <string>

#include <QCoreApplication>
#include <QString>
#include <QFileInfo>
#include <QLibrary>

#include "include/ILogger.h"
#include "include/IBrocker.h"
#include "include/IProblem.h"
#include "include/ISolver.h"

typedef IBrocker *(* get_brocker_func)();

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


template<typename InterfaceT, IBrocker::Type t>
InterfaceT * load( QFileInfo const &fileName, ILogger *logger, IBrocker *&brocker )
{
    QLibrary lib(fileName.absoluteFilePath());

    if (!lib.load())
    {
        std::cout << lib.errorString().toStdString() << "\n";
        if (logger != nullptr)
            logger->log("Library was not found", RESULT_CODE::NOT_FOUND);
        return nullptr;
    }

    auto getBrocker = reinterpret_cast<get_brocker_func>(lib.resolve("getBrocker"));

    if (getBrocker == nullptr)
    {
        if (logger != nullptr)
            logger->log("getBrocker was not found", RESULT_CODE::NOT_FOUND);
        return nullptr;
    }

    brocker = getBrocker();

    if (brocker->getType() != t)
    {
        if (logger != nullptr)
            logger->log("Brocker cannot create needed interface", RESULT_CODE::WRONG_ARGUMENT);
        return nullptr;
    }

    return reinterpret_cast<InterfaceT *>(brocker->getInterfaceImpl(t));
}

int main(int argc, char *argv[])
{
    // You can view available paths (to be hardcoded) in comments
    ILogger *logger = ILogger::createLogger(argv[0]);

    std::cout << "Input problem library address without suffix: ";

    std::string name;
    std::cin >> name;

    IBrocker *problemBrocker;

    /// name = "../user_app/libs/problem";
    auto problem = load<IProblem, IBrocker::Type::PROBLEM>(QFileInfo(name.c_str()), logger, problemBrocker);

    if (problem == nullptr)
    {
        std::cout << "Problem was not loaded\n";
        if (logger != nullptr)
            logger->destroyLogger(argv[0]);
        return 0;
    }

    std::cout << "Input solver library address without suffix: ";
    std::cin >> name;

    IBrocker *solverBrocker;
    ///name = "../user_app/libs/solver";
    auto solver = load<ISolver, IBrocker::Type::SOLVER>(QFileInfo(name.c_str()), logger, solverBrocker);

    if (solver == nullptr)
    {
        std::cout << "Solver was not loaded\n";
        problemBrocker->release();
        if (logger != nullptr)
            logger->destroyLogger(argv[0]);
        return 0;
    }

    std::cout << "Input problem params dimension: ";
    size_t dim;
    std::cin >> dim;
    ///dim = 2;
    std::cout << "Input problem params vector, separated with ws or enter: ";
    double *data = new double[dim];
    for (size_t i = 0; i < dim; i++)
        std::cin >> data[i];

    ///data[0] = 1;
    ///data[1] = 100;

    IVector *v;

    v = IVector::createVector(dim, data, logger);
    auto rc = problem->setParams(v);
    delete []data;
    delete v;

    if (rc != RESULT_CODE::SUCCESS)
    {
        problemBrocker->release();
        solverBrocker->release();
        if (logger != nullptr)
            logger->destroyLogger(argv[0]);
        return 0;
    }

    rc = solver->setProblem(problem);

    if (rc != RESULT_CODE::SUCCESS)
    {
        problemBrocker->release();
        solverBrocker->release();
        if (logger != nullptr)
            logger->destroyLogger(argv[0]);
        return 0;
    }

    std::cout << "Input solver params dimension: ";
    std::cin >> dim;
    ///dim = 2;

    std::cout << "Input solver params vector, separated with ws or enter: ";
    /// the way with string
    ///std::string s = "dim = 2; step = 0.002, 0.003";
    /// QString qs(s.c_str());
    /// rc = solver->setParams(qs);

    // more convinient and obvious way IMHO
    data = new double[dim];
    for (size_t i = 0; i < dim; i++)
        std::cin >> data[i];

    v = IVector::createVector(dim, data, logger);
    rc = solver->setParams(v);

    delete []data;
    delete v;

    if (rc != RESULT_CODE::SUCCESS)
    {
        problemBrocker->release();
        solverBrocker->release();
        if (logger != nullptr)
            logger->destroyLogger(argv[0]);
        return 0;
    }

    std::cout << "Input compact to be used in solver:\nbegin:\ndimension: ";
    std::cin >> dim;
    std::cout << "vector: ";
    data = new double[dim];
    for (size_t i = 0; i < dim; i++)
        std::cin >> data[i];

    ///dim = 2;
    ///data[0] = 0;
    ///data[1] = 0;
    auto beg = IVector::createVector(dim, data, logger);

    std::cout << "input end vector with the same dimension: ";
    for (size_t i = 0; i < dim; i++)
        std::cin >> data[i];

    ///data[0] = 2.8;
    ///data[1] = 1;

    auto end = IVector::createVector(dim, data, logger);
    delete []data;

    auto compact = ICompact::createCompact(beg, end, logger);
    rc = solver->setCompact(compact);
    delete compact;

    delete beg;
    delete end;

    if (rc != RESULT_CODE::SUCCESS)
    {
        problemBrocker->release();
        solverBrocker->release();
        if (logger != nullptr)
            logger->destroyLogger(argv[0]);
        return 0;
    }

    rc = solver->solve();
    if (rc != RESULT_CODE::SUCCESS)
    {
        problemBrocker->release();
        solverBrocker->release();
        logger->destroyLogger(argv[0]);
        return 0;
    }

    IVector *solution = nullptr;
    rc = solver->getSolution(solution);

    if (rc != RESULT_CODE::SUCCESS)
        std::cout << "Soultion wasn't found\n";
    else
    {
        std::cout << "Solution was found: ";
        output(solution);
    }

    delete solution;

    problemBrocker->release();
    solverBrocker->release();
    if (logger != nullptr)
        logger->destroyLogger(argv[0]);
    return 0;
}

