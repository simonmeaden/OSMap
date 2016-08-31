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

#include "gmllinestring.h"
#include "gmlpos.h"
#include "gml_global.h"

GML_BEGIN_NAMESPACE


/*!
    \class GMLLineString

    \brief Defines a LineString segment.

    The GMLLineString element holds the
    data points that defines a line segment. This must have as a minimum two
    points defining the two ends of the line.

    \author Simon Meaden
    \date   16Jun 2016
*/

/*!
    \fn GMLLineString( QObject * )

    \brief Constructor for GMLLineString.

    GMLLineString has one parameters a parent QObject.
*/
GMLLineString::GMLLineString( QObject *parent ) :
    QObject( parent ) {
}

/*!
    \fn GMLLineString::setPositions( GMLPosList )

    \brief Sets the points that define the line.

    The position points are defined in a GMLPosList object and must consist
    of at least two points, otherwise an assertion is thrown.
*/
void GMLLineString::setPositions( QSharedPointer<GMLPosList> positions ) {
    Q_ASSERT_X( positions->size() >= 2, "GMLLineString", "must have at least two position pairs" );
    pPositions = positions;


    for (int i = 0; i < pPositions.data()->size(); i++) {
        QSharedPointer<GMLPos> pos = pPositions->position(i);

        if ( pos->x() < mBoundary.left() ) {
            mBoundary.setLeft( pos->x() );
        }

        if ( pos->x() > mBoundary.right() ) {
            mBoundary.setRight( pos->x() );
        }

        if ( pos->y() > mBoundary.bottom() ) {
            mBoundary.setBottom( pos->y() );
        }

        if ( pos->y() < mBoundary.top() ) {
            mBoundary.setTop( pos->y() );
        }
    }
}

/*!
    \fn GMLLineString::positions( )

    \brief Returns the points that define the line.

*/
QSharedPointer<GMLPosList> GMLLineString::positions() {
    return pPositions;
}

QRect GMLLineString::bounds() {
    return mBoundary;
}

GML_END_NAMESPACE
