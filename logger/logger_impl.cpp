#include <set>
#include <fstream>
#include "ILogger.h"

namespace  {
#pragma pack(push, 1)
class LoggerImpl : public ILogger
{
public:
    void destroyLogger(void* pClient) override
    {
        std::set<void*>::iterator it;
        if ((it = clients.find(pClient)) != clients.end())
            clients.erase(it);

        if (clients.empty()) {
            logStream.close();
            delete instance;
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
        logStream << headMsg << pMsg << "\n";
    }

    RESULT_CODE setLogFile( char const* pLogFile ) override
    {
        logStream.open(pLogFile, std::ofstream::out);
        if (logStream.is_open())
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
    std::ofstream logStream;
};
#pragma pack(pop)

LoggerImpl *LoggerImpl::instance = new LoggerImpl();
}

ILogger * ILogger::createLogger( void* pClient )
{
    auto logger = LoggerImpl::getInstance();
    logger->addClient(pClient);
    return logger;
}
