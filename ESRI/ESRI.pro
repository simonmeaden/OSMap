#-------------------------------------------------
#
# Project created by QtCreator 2016-06-18T10:18:10
#
#-------------------------------------------------

QT       += widgets opengl sql svg xml

greaterThan(QT_MAJOR_VERSION, 4): QT += printsupport

TARGET = ESRI
TEMPLATE = lib

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
