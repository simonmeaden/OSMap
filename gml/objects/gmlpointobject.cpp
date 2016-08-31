/**
 ** This file is part of the OSMap project.
 ** Copyright 2016 Simon Meaden <simonmeaden@smelecomp.co.uk>.
 **
 ** This program is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation, either version 3 of the License, or
 ** (at your option) any later version.
 **
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU General Public License for more details.
 **
 ** You should have received a copy of the GNU General Public License
 ** along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/

#include "gmlpointobject.h"

GML_BEGIN_NAMESPACE

GMLPointObject::GMLPointObject( QString referenceSquare, int number, QObject *parent ) :
    GMLObject( parent ),
    GMLIdObject( referenceSquare ),
    GMLNumberedObject( number ) {

}

bool GMLPointObject::intersects( QRect area ) {
    if ( area.left() <= pPosition->x() && area.right() >= pPosition->x() &&
         area.top() <= pPosition->y() && area.bottom() >= pPosition->y() ) {
        return true;
    }

    return false;
}

void GMLPointObject::paint( QPainter *painter ) {

}

int GMLPointObject::height() {
    return mHeight;
}

void GMLPointObject::setHeight( int height ) {
    mHeight = height;
}

GMLType GMLPointObject::type() {
    return mType;
}

void GMLPointObject::setType( GMLType type ) {
    mType = type;
}

//QString GMLPointObject::uom() {
//    return mUom;
//}

//void GMLPointObject::setUom( QString type ) {
//    mUom = type;
//}

QSharedPointer<GMLPos> GMLPointObject::position() {
    return pPosition;
}

void GMLPointObject::setPosition( QSharedPointer<GMLPos> point ) {
    pPosition = point;
}

GML_END_NAMESPACE
