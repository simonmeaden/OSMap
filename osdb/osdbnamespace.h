#ifndef OSDBNAMESPACE_H
#define OSDBNAMESPACE_H

//  Disables the namespace
//  The problem with declaring namespaces like hjis is that the
//  QTCreator method list (Symbols) do not work for some reason,
//  probably in the qtcreator parser.
#if defined(OSDB_DISABLE_NAMESPACE)

#   define OSDB_BEGIN_NAMESPACE
#   define OSDB_END_NAMESPACE
#   define OSDB_USE_NAMESPACE

#else

#   define OSDB_BEGIN_NAMESPACE namespace OSDatabase {
#   define OSDB_END_NAMESPACE }
#   define OSDB_USE_NAMESPACE using namespace OSDatabase;

#endif

#endif // OSDBNAMESPACE_H
