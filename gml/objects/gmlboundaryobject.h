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

#ifndef BOUNDARYLINE_H
#define BOUNDARYLINE_H

#include <QObject>

#include "gmlobject.h"
#include "gmlidobject.h"
#include "gmllinestring.h"
#include "gml_global.h"
#include "gmlenum.h"

GML_BEGIN_NAMESPACE

class GMLSHARED_EXPORT GMLBoundaryObject : public GMLObject, public GMLIdObject, public GMLNumberedObject {
        Q_OBJECT
    public:
        GMLBoundaryObject( QString referenceSquare, int number, QObject *parent = 0 );

        int height();
        void setHeight( int height );
        GMLType type();
        void setType( GMLType type );
        //        QString uom();
        //        void setUom( QString uom );
        void setPositions( QSharedPointer<GMLLineString> positions );
        QSharedPointer<GMLLineString> positions();

        virtual bool intersects( QRect area );
        virtual void paint( QPainter *painter );

    protected:
        QRect mBoundary;
        //        QString mUom;
        GMLType mType;
        int mHeight;
        QSharedPointer<GMLLineString> pPositions;
};

GML_END_NAMESPACE
#endif // BOUNDARYLINE_H
