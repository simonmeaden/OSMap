#-------------------------------------------------
#
# Project created by QtCreator 2016-08-28T10:27:22
#
#-------------------------------------------------

QT       += xml xmlpatterns

QT       -= gui

TARGET = osgml
TEMPLATE = lib

DEFINES += OSGML_LIBRARY

#CONFIG += debug_and_release_target
CONFIG += static # static library
CONFIG += c++11 # C++11 is the newest standard

DESTDIR = ../../build/osmap/osgml

CONFIG(debug, debug|release) {
    TARGET = osgmld
    OBJECTS_DIR = $$DESTDIR/.obj
    MOC_DIR = $$DESTDIR/.mocd
    RCC_DIR = $$DESTDIR/.qrcd
    UI_DIR = $$DESTDIR/.uid
}

CONFIG(release, debug|release) {
    TARGET = osgml
    OBJECTS_DIR = $$DESTDIR/.obj
    MOC_DIR = $$DESTDIR/.moc
    RCC_DIR = $$DESTDIR/.qrc
    UI_DIR = $$DESTDIR/.ui
}

SOURCES += osgml.cpp

HEADERS += osgml.h\
        osgml_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
