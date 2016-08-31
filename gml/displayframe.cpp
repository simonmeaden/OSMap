#include "displayframe.h"

GML_BEGIN_NAMESPACE

DisplayFrame::DisplayFrame( QWidget *parent ) :
    QFrame( parent ) {

}


void DisplayFrame::paintEvent( QPaintEvent *evt ) {

}


void DisplayFrame::setObjectStore( QSharedPointer<ObjectStore> objectStore ) {
    pObjectStore = objectStore;
}

GML_END_NAMESPACE
