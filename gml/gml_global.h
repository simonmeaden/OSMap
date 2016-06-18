#ifndef GML_GLOBAL_H
#define GML_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(GML_LIBRARY)
#  define GMLSHARED_EXPORT Q_DECL_EXPORT
#else
#  define GMLSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // GML_GLOBAL_H
