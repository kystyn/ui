#include "../include/ICompact.h"
#include "../include/IVector.h"
#include "../include/ILogger.h"

int main( int argc, char *argv[] )
{
    ILogger *logger = ILogger::createLogger(argv[0]);
    logger->log("alive", RESULT_CODE::NAN_VALUE);
    logger->destroyLogger(argv[0]);
    logger->createLogger((void*)"f,shdfku");
    logger->log("alive2", RESULT_CODE::NAN_VALUE);
    logger->destroyLogger(argv[0]);
    double d[] = {2, 4};
    IVector *vector = IVector::createVector(2, d, nullptr);
	return 0;
}
