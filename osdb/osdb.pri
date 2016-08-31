
DEFINES += OSDB_LIBRARY
DEFINES += OSDB_DISABLE_NAMESPACE

SOURCES += \
    $$PWD/osdb.cpp \
    $$PWD/sql.cpp

HEADERS += \
    $$PWD/osdb.h \
    $$PWD/osdb_global.h \
    $$PWD/osdbnamespace.h \
    $$PWD/sql.h

INCLUDEPATH += $$PWD
