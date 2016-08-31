
DEFINES += GML_LIBRARY
DEFINES += GML_DISABLE_NAMESPACE
DEFINES += OSDB_DISABLE_NAMESPACE

SOURCES += \
    $$PWD/gml.cpp \
    $$PWD/objects/road.cpp \
    $$PWD/objects/gmlposlist.cpp \
    $$PWD/objects/gmllinestring.cpp \
    $$PWD/objects/gmllinearring.cpp \
    $$PWD/objects/gmlpolygonpatch.cpp \
    $$PWD/objects/gmlobject.cpp \
    $$PWD/objects/gmlidobject.cpp \
    $$PWD/objects/gmlnamedobject.cpp \
    $$PWD/objects/gmlpoint.cpp \
    $$PWD/objects/gmlpos.cpp \
    $$PWD/gmlreader.cpp \
    $$PWD/objects/featurecollection.cpp \
    $$PWD/objects/woodland.cpp \
    $$PWD/objects/terrain50.cpp \
    $$PWD/objects/featureobject.cpp \
    $$PWD/objects/spotheight.cpp \
    $$PWD/objects/contourline.cpp \
    $$PWD/objects/landwaterboundary.cpp \
    $$PWD/displayframe.cpp \
    $$PWD/objectstore.cpp \
    $$PWD/objects/gmlpointobject.cpp \
    $$PWD/objects/gmlboundaryobject.cpp

HEADERS += gml.h\
    $$PWD/gml_global.h \
    $$PWD/objects/road.h \
    $$PWD/objects/gmlposlist.h \
    $$PWD/objects/gmllinestring.h \
    $$PWD/objects/gmllinearring.h \
    $$PWD/objects/gmlpolygonpatch.h \
    $$PWD/objects/gmlidobject.h \
    $$PWD/objects/gmlobject.h \
    $$PWD/objects/gmlnamedobject.h \
    $$PWD/objects/gmlpoint.h \
    $$PWD/objects/gmlpos.h \
    $$PWD/gmlreader.h \
    $$PWD/objects/featurecollection.h \
    $$PWD/objects/woodland.h \
    $$PWD/objects/terrain50.h \
    $$PWD/objects/featureobject.h \
    $$PWD/objects/spotheight.h \
    $$PWD/objects/contourline.h \
    $$PWD/objects/landwaterboundary.h \
    $$PWD/global.h \
    $$PWD/gmlnamespace.h \
    $$PWD/displayframe.h \
    $$PWD/objectstore.h \
    $$PWD/objects/gmlenum.h \
    $$PWD/objects/gmlpointobject.h \
    $$PWD/objects/gmlboundaryobject.h


INCLUDEPATH += $$PWD
