#ifndef ESRI_GLOBAL_H
#define ESRI_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(ESRI_LIBRARY)
#  define ESRISHARED_EXPORT Q_DECL_EXPORT
#else
#  define ESRISHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // ESRI_GLOBAL_H
