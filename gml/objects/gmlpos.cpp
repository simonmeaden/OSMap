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

#include "gmlpos.h"
#include "gml_global.h"

GML_BEGIN_NAMESPACE


/*!
    \class GMLPos

    \brief Stores a single position pair as an integer pair.

    Pairs are specified to one centimetre accuracy.

    \author Simon Meaden
    \date   18 Jun 2016
*/

/*!
    \fn GMLPos(QObject *parent)

    \brief Constructor for GMLPos.

    Basic constructor with no values specified. Positions can be added later using
    one of the GMLPos::setPosition method.

    \sa GMLPos::setPosition(QString, QString)
    \sa GMLPos::setPosition(int, int)
    \sa GMLPos::setPosition(QPair<int, int>)

    \note All positions are defined in centimetres.
*/
GMLPos::GMLPos(QObject *parent ) : QObject(parent) {
}

/*!
    \fn GMLPos::setPosition( QString x, QString y )

    \brief Sets a position as two strings.

    GML Strings are double values defined in metres to a one centimetre accuracy
    for example 125675.23.

    \sa GMLPos::setPosition(int, int)
    \sa GMLPos::setPosition(QPair<int, int>)

    \note All positions are defined in centimetres.
*/
void GMLPos::setPosition( QString x, QString y ) {
    QPair<int, int> pair = qMakePair( ( x.toInt() * 100 ), ( y.toInt() * 100 ) );
    setPosition( pair );
}

/*!
    \fn GMLPos::setPosition( QString x, QString y )

    \brief Sets a position as two integer values in centimetres.

    \sa GMLPos::setPosition(QString, QString)
    \sa GMLPos::setPosition(QPair<int, int>)

    \note All positions are defined in centimetres.
*/
void GMLPos::setPosition( int x, int y ) {
    QPair<int, int> pair = qMakePair( x, y );
    setPosition( pair );
}

/*!
    \fn GMLPos::setPosition( QPair<int, int> )

    \brief Sets a position as two integer values in centimetres.

    \sa GMLPos::setPosition(QString, QString)
    \sa GMLPos::setPosition(int, int)

    \note All positions are defined in centimetres.
*/
void GMLPos::setPosition( QPair<int, int> position ) {
    mPosition = position;
}

GML_END_NAMESPACE
