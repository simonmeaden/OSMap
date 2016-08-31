#ifndef GMLNAMESPACE_H
#define GMLNAMESPACE_H

//  Disables the namespace
//  The problem with declaring namespaces like hjis is that the
//  QTCreator method list (Symbols) do not work for some reason,
//  probably in the qtcreator parser.
#if defined(GML_DISABLE_NAMESPACE)

#   define GML_BEGIN_NAMESPACE
#   define GML_END_NAMESPACE
#   define GML_USE_NAMESPACE

#else

#   define GML_BEGIN_NAMESPACE namespace Gml {
#   define GML_END_NAMESPACE }
#   define GML_USE_NAMESPACE using namespace Gml;

#endif

#endif // GMLNAMESPACE_H
