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

#include "gmlpolygonpatch.h"
#include "gml_global.h"

GML_BEGIN_NAMESPACE


/*!
    \class GMLPolygonPatch

    \brief Defines a surface polygonal surface patch.

    A polygon patch is a surface patch that is defined by a set of boundary curves
    and an underlying surface to which these curves adhere. The curves shall be
    coplanar and the polygon uses planar interpolation in its interior.

    \author Simon Meaden
    \date   16 Jun 2016
*/

/*!
    \fn GMLPolygonPatch( QObject * )

    \brief Constructor for GMLPolygonPatch
*/
GMLPolygonPatch::GMLPolygonPatch( QObject *parent ) :
    GMLObject( parent ),
    pExterior( Q_NULLPTR ) {
}

/*!
    \fn addRing(GMLLinearRing*)

    \brief Adds a new ring to the patch.



    \sa [see also section]
    \note [any note about the function you might have]
    \warning [any warning if necessary]
*/
void GMLPolygonPatch::addInterior( GMLLinearRing *ring ) {
    mPatches.append( ring );
}

/*!
    \fn interior()

    \brief Returns the interior rings as a QList of GMLLinearRing's.
*/
QList<GMLLinearRing *> GMLPolygonPatch::interior() {
    return mPatches;
}

/*!
    \fn setExterior(GMLLinearRing*)

    \brief Set the exterior ring.

    A patch can have 0 or more interior rings, only one of which can be
    specified as the exterior ring
*/
void GMLPolygonPatch::setExterior( GMLLinearRing *ring ) {
    pExterior = ring;
}

/*!
    \fn exterior()

    \brief Returns the exterior ring or NULL if no exterior ring.
*/
GMLLinearRing *GMLPolygonPatch::exterior() {
    return pExterior;
}

GML_END_NAMESPACE
