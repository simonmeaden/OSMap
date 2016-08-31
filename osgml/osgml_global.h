#ifndef OSGML_GLOBAL_H
#define OSGML_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(OSGML_LIBRARY)
#  define OSGMLSHARED_EXPORT Q_DECL_EXPORT
#else
#  define OSGMLSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // OSGML_GLOBAL_H
