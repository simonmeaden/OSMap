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

#ifndef GMLOBJECT_H
#define GMLOBJECT_H

#include <QObject>
#include <QPainter>

#include "gml_global.h"

GML_BEGIN_NAMESPACE

class GMLObject : public QObject {
        Q_OBJECT
    public:
        explicit GMLObject( QObject *parent = 0 );

        virtual bool intersects( QRect area )=0;

    protected:

        virtual void paint( QPainter *painter )=0;

};

class GMLIdObject {
    public:
        GMLIdObject();
        GMLIdObject( QString referenceSquare );

        void setReferenceSquare( QString referenceSquare );
        QString referenceSquare();

    protected:
        QString mId;
};

class GMLNumberedObject {
    public:
        GMLNumberedObject( int idNumber );

        void setIdNumber( int number );
        int idNumber();

    protected:
        int mIdNumber;
};

GML_END_NAMESPACE
#endif // GMLOBJECT_H
