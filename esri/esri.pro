#-------------------------------------------------
#
# Project created by QtCreator 2016-06-18T10:18:10
#
#-------------------------------------------------

QT       += widgets opengl sql svg xml

greaterThan(QT_MAJOR_VERSION, 4): QT += printsupport

TEMPLATE = lib

#CONFIG += debug_and_release_target
CONFIG += static # static library
CONFIG += c++11 # C++11 is the newest standard

DESTDIR = ../../build/osmap/esri

CONFIG(debug, debug|release) {
    TARGET = esrid
    OBJECTS_DIR = $$DESTDIR/.obj
    MOC_DIR = $$DESTDIR/.mocd
    RCC_DIR = $$DESTDIR/.qrcd
    UI_DIR = $$DESTDIR/.uid
}

CONFIG(release, debug|release) {
    TARGET = esri
    OBJECTS_DIR = $$DESTDIR/.obj
    MOC_DIR = $$DESTDIR/.moc
    RCC_DIR = $$DESTDIR/.qrc
    UI_DIR = $$DESTDIR/.ui
}

DEFINES += ESRI_LIBRARY

SOURCES += esri.cpp \
    esrireader.cpp

HEADERS += esri.h\
        esri_global.h \
    esrireader.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
