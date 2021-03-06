#-------------------------------------------------
#
# Project created by QtCreator 2016-06-18T10:34:07
#
#-------------------------------------------------

QT       -= gui

TEMPLATE = lib

CONFIG += static # static library
CONFIG += c++11 # C++11 is the newest standard

DESTDIR = ../../build/osmap/gml

CONFIG(debug, debug|release) {
    TARGET = gmld
    OBJECTS_DIR = $$DESTDIR/.obj
    MOC_DIR = $$DESTDIR/.mocd
    RCC_DIR = $$DESTDIR/.qrcd
    UI_DIR = $$DESTDIR/.uid
}

CONFIG(release, debug|release) {
    TARGET = gml
    OBJECTS_DIR = $$DESTDIR/.obj
    MOC_DIR = $$DESTDIR/.moc
    RCC_DIR = $$DESTDIR/.qrc
    UI_DIR = $$DESTDIR/.ui
}

include(gml.pri)

unix {
    target.path = /usr/lib
    INSTALLS += target
}
