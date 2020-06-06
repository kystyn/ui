#ifndef ILOGGER_H
#define ILOGGER_H
#include "RC.h"


#ifdef _WIN32
#define DECLSPEC __declspec(dllimport)
#else
#define DECLSPEC
#endif

class DECLSPEC ILogger {
public:
    static ILogger* createLogger(void* pClient);
    virtual void destroyLogger(void* pClient) = 0;
    virtual void log(char const* pMsg, RESULT_CODE err) = 0;
    virtual RESULT_CODE setLogFile(char const* pLogFile) = 0;
protected:
    virtual ~ILogger() = default;
    ILogger() = default;
private:
    ILogger(ILogger const& vector) = delete;
    ILogger& operator=(ILogger const& vector) = delete;
};

#endif // ILOGGER_H
