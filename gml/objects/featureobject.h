#ifndef FEATUREOBJECT_H
#define FEATUREOBJECT_H

#include <QObject>
#include <QMap>
#include <QSharedPointer>

#include "gmlobject.h";
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

#include "gml_global.h"

GML_BEGIN_NAMESPACE


class FeatureObject : public QObject {
        Q_OBJECT
    public:
        explicit FeatureObject( QObject *parent = 0 );

        int year();
        void setYear( int year );
        int lowerX();
        int lowerY();
        void setLower( int first, int second );
        int upperX();
        int upperY();
        void setUpper( int first , int second );
        QString referenceSquare();
        void setReferenceSquare( QString name );
//        int subSquare();
//        void setSubSquare( int value );
        QString quarter();
        void setQuarter( QString name );

        QSharedPointer<GMLObject> object(int id);
        void setObject(int id, QSharedPointer<GMLObject> object);
        QList<int> idList();

    signals:

    public slots:

    protected:
        QMap<int, QSharedPointer<GMLObject>> mObjects;
        QString mReferenceSquare, mQuarter;
        int mSubSquare;
        int mYear;
        QPair<int, int> mLower, mUpper;


};

GML_END_NAMESPACE
#endif // FEATUREOBJECT_H
