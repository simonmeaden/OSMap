#ifndef DISPLAYFRAME_H
#define DISPLAYFRAME_H

#include <QFrame>
#include <QPainter>
#include <QPaintEvent>
#include <QSharedPointer>

#include "gml_global.h"
#include "objectstore.h"

GML_BEGIN_NAMESPACE

class DisplayFrame : public QFrame {
        Q_OBJECT
    public:
        explicit DisplayFrame( QWidget *parent = 0 );

        void setObjectStore( QSharedPointer<ObjectStore> objectStore );

    protected:
        virtual void paintEvent( QPaintEvent *evt );

    signals:

    protected:
        QSharedPointer<ObjectStore> pObjectStore;

};

GML_END_NAMESPACE
#endif // DISPLAYFRAME_H
