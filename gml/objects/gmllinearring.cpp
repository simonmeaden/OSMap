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

#include "gmllinearring.h"
#include "gml_global.h"

GML_BEGIN_NAMESPACE


/*!
    \class GMLLinearRing

    \brief Defines a LinearRing segment with both ends being the same point.

    The LinearRing element holds the
    data points that defines a line segment. This must have as a minimum four
    with both ends being the same point.

    \author Simon Meaden
    \date   16Jun 2016
*/

/*!
    \fn GMLLinearRing( QObject * )

    \brief Constructor for GMLLinearRing.

    GMLLinearRing has one parameters, a parent QObject.
*/
GMLLinearRing::GMLLinearRing( QObject *parent ) : GMLObject( parent ) {
}

/*!
    \fn GMLLinearRing::setPositions( GMLPosList )

    \brief Sets the points that define the line.

    The position points are defined in a GMLPosList object and must consist
    of at least four points with both ends being the same point,
    otherwise an assertion is thrown.
*/
void GMLLinearRing::setPositions( GMLPosList *positions ) {
    Q_ASSERT_X( positions->size() >= 4, "GMLLinearRing", "must have at least four position pairs" );
    Q_ASSERT_X( positions->first() != positions->last(), "GMLLinearRing", "first and last position must be identical" );
    pPositions = positions;
}

/*!
    \fn GMLLinearRing::positions( )

    \brief Returns the points that define the line.

*/
GMLPosList *GMLLinearRing::positions() {
    return pPositions;
}

GML_END_NAMESPACE
