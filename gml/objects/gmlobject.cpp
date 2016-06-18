#include "gmlobject.h"

GMLObject::GMLObject( QString id, QObject *parent ) :
    QObject( parent ), mId( id ) {
}
