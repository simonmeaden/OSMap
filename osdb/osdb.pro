#-------------------------------------------------
#
# Project created by QtCreator 2016-08-28T10:28:45
#
#-------------------------------------------------

QT       += sql

TEMPLATE = lib

DESTDIR = ../../build/osmap/osdb

CONFIG(debug, debug|release) {
    TARGET = osdbd
    OBJECTS_DIR = $$DESTDIR/.obj
    MOC_DIR = $$DESTDIR/.mocd
    RCC_DIR = $$DESTDIR/.qrcd
    UI_DIR = $$DESTDIR/.uid
}

CONFIG(release, debug|release) {
    TARGET = osdb
    OBJECTS_DIR = $$DESTDIR/.obj
    MOC_DIR = $$DESTDIR/.moc
    RCC_DIR = $$DESTDIR/.qrc
    UI_DIR = $$DESTDIR/.ui
}

include(osdb.pri)

unix {
    target.path = /usr/lib
    INSTALLS += target
}

DISTFILES += \
    osdb.pri
