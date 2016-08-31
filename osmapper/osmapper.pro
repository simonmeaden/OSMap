#-------------------------------------------------
#
# Project created by QtCreator 2016-06-18T10:17:00
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app

#CONFIG += debug_and_release_target
CONFIG += static # static library
CONFIG += c++11 # C++11 is the newest standard

DESTDIR = ../../build/osmap

CONFIG(debug, debug|release) {
    TARGET = osmapperd
    OBJECTS_DIR = $$DESTDIR/.obj
    MOC_DIR = $$DESTDIR/.mocd
    RCC_DIR = $$DESTDIR/.qrcd
    UI_DIR = $$DESTDIR/.uid
}

CONFIG(release, debug|release) {
    TARGET = osmapper
    OBJECTS_DIR = $$DESTDIR/.obj
    MOC_DIR = $$DESTDIR/.moc
    RCC_DIR = $$DESTDIR/.qrc
    UI_DIR = $$DESTDIR/.ui
}

include(../gml/gml.pri)
include(../osdb/osdb.pri)

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../build/osmap/gml/ -lgml
#else:win32:CONFIG(debug, debug|release): LIBS += -LL$$PWD/../../build/osmap/gml/ -lgmld
#else:unix:CONFIG(release, debug|release): LIBS += -L$$PWD/../../build/osmap/gml/ -lgml
#else:unix:CONFIG(debug, debug|release): LIBS += -LL$$PWD/../../build/osmap/gml/ -lgmld

#INCLUDEPATH += $$PWD/../gml
#DEPENDPATH += $$PWD/../gml

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../build/osmap/osdb/ -losdb
#else:win32:CONFIG(debug, debug|release): LIBS += -LL$$PWD/../../build/osmap/osdb/ -losdbd
#else:unix:CONFIG(release, debug|release): LIBS += -L$$PWD/../../build/osmap/osdb/ -losdb
#else:unix:CONFIG(debug, debug|release): LIBS += -LL$$PWD/../../build/osmap/osdb/ -losdbd

#INCLUDEPATH += $$PWD/../osdb
#DEPENDPATH += $$PWD/../osdb
