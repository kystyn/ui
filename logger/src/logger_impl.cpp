#include <cstdio>
#include <set>
#include <fstream>
#include "../include/ILogger.h"

namespace  {
class LoggerImpl : public ILogger
{
public:
    LoggerImpl()
    {
        logStream = fopen("log.txt", "w");
        if (logStream == nullptr)
            fprintf(stderr, "Couldn't create log.txt");
    }

    void destroyLogger(void* pClient) override
    {
        std::set<void*>::iterator it;
        if ((it = clients.find(pClient)) != clients.end())
            clients.erase(it);

        if (clients.empty()) {
            fclose(logStream);
            delete instance;
            instance = nullptr;
        }
    }

    void log( char const* pMsg, RESULT_CODE err ) override
    {
        const char *headMsg;
        switch (err)
        {
        case RESULT_CODE::SUCCESS:
            headMsg = "INFO: ";
            break;
        case RESULT_CODE::NAN_VALUE:
            headMsg = "ERROR: NOT A NUMBER: ";
            break;
        case RESULT_CODE::NOT_FOUND:
            headMsg = "ERROR: NOT FOUND: ";
            break;
        case RESULT_CODE::WRONG_DIM:
            headMsg = "ERROR: WRONG DIMENSION: ";
            break;
        case RESULT_CODE::FILE_ERROR:
            headMsg = "ERROR: FILE ERROR: ";
            break;
        case RESULT_CODE::BAD_REFERENCE:
            headMsg = "ERROR: BAD REFERENCE: ";
            break;
        case RESULT_CODE::OUT_OF_BOUNDS:
            headMsg = "ERROR: OUT OF BOUNDS: ";
            break;
        case RESULT_CODE::OUT_OF_MEMORY:
            headMsg = "ERROR: OUT OF MEMORY: ";
            break;
        case RESULT_CODE::WRONG_ARGUMENT:
            headMsg = "ERROR: WRONG ARGUMENT: ";
            break;
        case RESULT_CODE::DIVISION_BY_ZERO:
            headMsg = "ERROR: DIVIDE BY ZERO: ";
            break;
        case RESULT_CODE::CALCULATION_ERROR:
            headMsg = "ERROR: CALCULATION ERROR: ";
            break;
        case RESULT_CODE::MULTIPLE_DEFINITION:
            headMsg = "ERROR: MULTIPLE DEFINITION: ";
            break;
        }
        fprintf(logStream, "%s%s\n", headMsg, pMsg);
    }

    RESULT_CODE setLogFile( char const* pLogFile ) override
    {
        fclose(logStream);
        logStream = fopen(pLogFile, "w");
        if (logStream != nullptr)
            return RESULT_CODE::SUCCESS;
        return RESULT_CODE::FILE_ERROR;
    }

    static LoggerImpl * getInstance()
    {
        return instance;
    }

    void addClient(void *pClient)
    {
        clients.insert(pClient);
    }

protected:
    ~LoggerImpl() override
    {
    }

private:
    static LoggerImpl *instance;
    std::set<void *> clients;
    FILE *logStream;
};

LoggerImpl *LoggerImpl::instance = new LoggerImpl();
}

ILogger * ILogger::createLogger( void* pClient )
{
    auto logger = LoggerImpl::getInstance();

    if (logger == nullptr)
        logger = new LoggerImpl();

    logger->addClient(pClient);
    return logger;
}
