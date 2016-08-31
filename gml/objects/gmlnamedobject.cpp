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

#include "gmlnamedobject.h"
#include "gml_global.h"

GML_BEGIN_NAMESPACE


/*!
 * \class GMLNamedObject
 *
 * \brief A class that adds an name string to a GMLObject.
 *
 * \author Simon Meaden
 * \date   16 Jun 2106
 */


GMLNamedObject::GMLNamedObject() {
}

/*!
 * \fn GMLNamedObject( QString )
 *
 * \brief Constructor for GMLIdObject.
 */
GMLNamedObject::GMLNamedObject( QString name ) :
    mName( name ) {
}

/*!
 * \fn GMLIdObject::setName( QString )
 *
 * \brief Sets the name string
 */
void GMLNamedObject::setName( QString name ) {
    mName = name;
}

/*!
 * \fn GMLIdObject::name()
 *
 * \brief Returns the name string
 */
QString GMLNamedObject::name() {
    return mName;
}

GML_END_NAMESPACE
