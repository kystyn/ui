QT -= gui

CONFIG += c++11 console

TARGET = problem

TEMPLATE = lib

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        src/problem_impl.cpp

HEADERS += \
        include/ILogger.h \
        include/ICompact.h \
        include/IVector.h \
        include/IProblem.h \
        include/IBrocker.h \
        include/RC.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

LIBS += -L$$PWD/libs/ -llogger
LIBS += -L$$PWD/libs/ -lvector
LIBS += -L$$PWD/libs/ -lcompact
