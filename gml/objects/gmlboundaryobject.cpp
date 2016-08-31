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

#include <limits>

#include "gmlboundaryobject.h"
#include "gml_global.h"

GML_BEGIN_NAMESPACE


GMLBoundaryObject::GMLBoundaryObject( QString id, int number, QObject *parent ) :
    GMLObject( parent ),
    GMLIdObject( id ),
    GMLNumberedObject( number ),
    mBoundary(0, 0, std::numeric_limits<int>::max(), std::numeric_limits<int>::max()) {

}

bool GMLBoundaryObject::intersects( QRect area ) {
    return area.intersects( mBoundary );
}

void GMLBoundaryObject::paint( QPainter *painter ) {

}

int GMLBoundaryObject::height() {
    return mHeight;
}

void GMLBoundaryObject::setHeight( int height ) {
    mHeight = height;
}

GMLType GMLBoundaryObject::type() {
    return mType;
}

void GMLBoundaryObject::setType( GMLType type ) {
    mType = type;
}

//QString BoundaryLine::uom() {
//    return mUom;
//}

//void BoundaryLine::setUom( QString type ) {
//    mUom = type;
//}

QSharedPointer<GMLLineString> GMLBoundaryObject::positions() {
    return pPositions;
}

void GMLBoundaryObject::setPositions( QSharedPointer<GMLLineString> positions ) {
    pPositions = positions;
}
