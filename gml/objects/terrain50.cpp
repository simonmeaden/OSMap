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

#include "terrain50.h"
#include "gml_global.h"

GML_BEGIN_NAMESPACE


Terrain50::Terrain50( QObject *parent ) :
    FeatureObject( parent ),
    mNominalScale( 50000 ),
    mElevationReference( 0 ),
    mEquidistance( 0 ),
//    mEquidistanceType( "m" ),
    mId( -1 ) {

}

void Terrain50::convertToDb() {
}

int Terrain50::nominalScale() {
    return mNominalScale;
}

void Terrain50::setNominalScale( int scale ) {
    mNominalScale = scale;
}

int Terrain50::elevationReference() {
    return mElevationReference;
}

void Terrain50::setElevationReference( int reference ) {
    mElevationReference = reference;
}

int Terrain50::equidistance() {
    return mEquidistance;
}

void Terrain50::setEquidistance( int equidistance ) {
    mEquidistance = equidistance;
}

//QString Terrain50::uom() {
//    return mEquidistanceType;
//}

//void Terrain50::setUom( QString type ) {
//    mEquidistanceType = type;
//}

GML_END_NAMESPACE
