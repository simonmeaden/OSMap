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

#include "gmlpoint.h"
#include "gml_global.h"

GML_BEGIN_NAMESPACE


/*!
    \class GMLPoint

    \brief Defines a single points position.

    \author Simon Meaden
    \date   16Jun 2016
*/

/*!
    \fn GMLPoint::GMLPoint( QString, QString, QObject * )

    \brief Constructor for GMLPoint.

    GMLPoint has three parameters, an id string,a name string and
    a parent QObject.
*/
GMLPoint::GMLPoint( QString id, QString name, QObject *parent ) :
    GMLObject( parent ),
    GMLIdObject( id ),
    GMLNamedObject( name ) {
}

/*!
    \fn GMLPoint::point( )

    \brief Returns the point as a GMLPos*.

*/
GMLPos *GMLPoint::point() {
    return pPosition;
}

/*!
    \fn GMLLineString::setPoint(GMLPos *point)

    \brief Sets the point position.
*/
void GMLPoint::setPoint( GMLPos *point ) {
    pPosition = point;
}

GML_END_NAMESPACE
