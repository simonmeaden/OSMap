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

#ifndef TERRAIN50_H
#define TERRAIN50_H

#include <QObject>
#include <QMap>
#include <QSqlDatabase>

#include "featureobject.h"
#include "gml_global.h"

GML_BEGIN_NAMESPACE


class GMLObject;

class GMLSHARED_EXPORT Terrain50 : public FeatureObject {
        Q_OBJECT
    public:
        explicit Terrain50( QObject *parent = 0 );

        int nominalScale();
        void setNominalScale(int scale);
        int elevationReference();
        void setElevationReference(int reference);
        int equidistance();
        void setEquidistance(int equidistance);
//        QString uom();
//        void setUom(QString type);

        virtual void convertToDb();

    signals:

    public slots:

    protected:
        int mNominalScale, mElevationReference, mEquidistance, mId;
//        QString mEquidistanceType;

};

GML_END_NAMESPACE
#endif // TERRAIN50_H
