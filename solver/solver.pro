QT -= gui

CONFIG += c++11 console

TARGET= solver

TEMPLATE = lib

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        src/solver_impl.cpp

HEADERS += \
        include/ILogger.h \
        include/ICompact.h \
        include/ISolver.h \
        include/IVector.h \
        include/IProblem.h \
        include/RC.h


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

CONFIG: LIBS += -L$$PWD/libs/ -llogger
CONFIG: LIBS += -L$$PWD/libs/ -lvector
CONFIG: LIBS += -L$$PWD/libs/ -lcompact
#CONFIG: LIBS += -L$$PWD/libs/ -lproblem
