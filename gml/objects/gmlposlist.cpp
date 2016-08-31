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

#include "gmlposlist.h"
#include "gml_global.h"

GML_BEGIN_NAMESPACE



/*!
    \class GMLPosList

    \brief Stores a list of position pairs as integer pairs.

    Pairs are specified to one centimetre accuracy.

    \author Simon Meaden
    \date   18 Jun 2016
*/

/*!
    \fn GMLPosList(QObject *parent)

    \brief Constructor for GMLPosList.

    Basic constructor with no values specified. Positions can be added later using
    one of the GMLPosList::addPosition or GMLPosList::addPositions methods.

    \sa GMLPosList::addPositions(QList<GMLPos*>)

    \note All positions are defined in centimetres.
*/
GMLPosList::GMLPosList( QObject *parent ) : QObject( parent ) {
}

/*!
    \fn GMLPosList::addPosition( GMLPos* )

    \brief Add a position as two integer values in centimetres.

    \sa GMLPosList::addPositions(QList<GMLPos*>)

    \note All positions are defined in centimetres.
*/
void GMLPosList::addPosition( QSharedPointer<GMLPos> pos ) {
    mPositions.append(pos);
}

/*!
    \fn GMLPosList::addPositions( QList<<GMLPos *> )

    \brief Add a set of position pairs as a single list of centimetre
    accuracy integer pairs.

    \sa GMLPosList::addPosition(GMLPos*)

    \note All positions are defined in centimetres.
*/
void GMLPosList::setPositions(QList<QSharedPointer<GMLPos> > list ) {

    clear();

    for ( int i = 0; i < list.size(); i++ ) {
        addPosition( list.at( i ) );
    }
}

/*!
    \fn GMLPosList::clear()

    \brief Removes all existing items and leaves an empty list.
*/
void GMLPosList::clear() {
//    qDeleteAll( mPositions );
    mPositions.clear();
}

/*!
    \fn GMLPosList::size()

    \brief Returns the number of position pairs in the list.
*/
int GMLPosList::size() {
    return mPositions.size();
}

GML_END_NAMESPACE
