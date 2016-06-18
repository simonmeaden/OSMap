#-------------------------------------------------
#
# Project created by QtCreator 2016-06-18T10:34:07
#
#-------------------------------------------------

QT       -= gui

TARGET = gml
TEMPLATE = lib

DEFINES += GML_LIBRARY

SOURCES += gml.cpp \
    objects/road.cpp \
    objects/gmlobject.cpp \
    objects/gmlposlist.cpp

HEADERS += gml.h\
        gml_global.h \
    objects/road.h \
    objects/gmlobject.h \
    objects/gmlposlist.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
