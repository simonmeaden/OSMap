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

#ifndef GMLPOINTOBJECT_H
#define GMLPOINTOBJECT_H

#include <QObject>
#include <QSharedPointer>

#include "gmlobject.h"
#include "gmlidobject.h"
#include "gmlpos.h"
#include "gml_global.h"
#include "gmlenum.h"

GML_BEGIN_NAMESPACE

class GMLPointObject  : public GMLObject, public GMLIdObject, public GMLNumberedObject {
        Q_OBJECT

    public:
        GMLPointObject( QString referenceSquare, int number, QObject *parent = 0 );

        int height();
        void setHeight( int height );
        GMLType type();
        void setType( GMLType type );
        //        QString uom();
        //        void setUom( QString uom );
        void setPosition( QSharedPointer<GMLPos> position );
        QSharedPointer<GMLPos> position();

        virtual bool intersects( QRect area );
        virtual void paint( QPainter *painter );

    protected:
        //        QString mUom;
        GMLType mType;
        int mHeight;
        QSharedPointer<GMLPos> pPosition;

};

GML_END_NAMESPACE
#endif // GMLPOINTOBJECT_H
