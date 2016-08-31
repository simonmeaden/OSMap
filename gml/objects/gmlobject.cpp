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

#include "gmlobject.h"
#include "gml_global.h"

GML_BEGIN_NAMESPACE



/*!
    \class GMLObject

    \brief Base object for all GML objects

    \author Simon Meaden
    \date   16 Jun 2016
*/

/*!
    \fn GMLObject( QObject *parent )

    \brief Constructor gor GMLObject

*/
GMLObject::GMLObject( QObject *parent ) : QObject( parent ) {
}

/*!
    \class GMLIdObject

    \brief A class that adds an id string to a GMLObject.

    \author Simon Meaden
    \date   16 Jun 2106
*/

GMLIdObject::GMLIdObject() {
}

/*!
    \fn GMLIdObject( QString )

    \brief Constructor for GMLIdObject.
*/
GMLIdObject::GMLIdObject( QString id ) :
    mId( id ) {
}

/*!
    \fn GMLIdObject::setId( QString )

    \brief Sets the id string
*/
void GMLIdObject::setReferenceSquare( QString id ) {
    mId = id;
}

/*!
    \fn GMLIdObject::id()

    \brief Returns the id string
*/
QString GMLIdObject::referenceSquare() {
    return mId;
}

/*!
    \fn GMLNumberedObject( QString )

    \brief Constructor for GMLNumberedObject.
*/
GMLNumberedObject::GMLNumberedObject( int idNumber ) :
    mIdNumber( idNumber ) {
}

/*!
    \fn GMLNumberedObject::setIdNumber( QString )

    \brief Sets the id string
*/
void GMLNumberedObject::setIdNumber( int id ) {
    mIdNumber = id;
}

/*!
    \fn GMLNumberedObject::id()

    \brief Returns the id string
*/
int GMLNumberedObject::idNumber() {
    return mIdNumber;
}
GML_END_NAMESPACE
