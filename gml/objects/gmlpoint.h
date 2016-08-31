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

#ifndef GMLPOINT_H
#define GMLPOINT_H

#include <QObject>

#include "gmlobject.h"
#include "gmlidobject.h"
#include "gmlnamedobject.h"
#include "gmlpos.h"
#include "gml_global.h"

GML_BEGIN_NAMESPACE


class GMLPoint : public GMLObject, public GMLIdObject, public GMLNamedObject  {
  public:
    GMLPoint( QString referenceSquare, QString name, QObject *parent );

    void setPoint(GMLPos *point);
    GMLPos* point();

protected:
    GMLPos *pPosition;
};

GML_END_NAMESPACE
#endif // GMLPOINT_H
