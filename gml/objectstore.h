#ifndef OBJECTSTORE_H
#define OBJECTSTORE_H

#include <QObject>
#include <QList>
#include <QMap>

#include "gml_global.h"
#include "objects/gmlobject.h"

GML_BEGIN_NAMESPACE

class ObjectStore : public QObject {
        Q_OBJECT
    public:
        explicit ObjectStore( QObject *parent = 0 );

        QList<QSharedPointer<GMLObject>> objects();

protected:
    QMap<QRect, int> mBoundaryIds;
    QMap<int, QSharedPointer<GMLObject>> mObjects;
};

GML_END_NAMESPACE
#endif // OBJECTSTORE_H
