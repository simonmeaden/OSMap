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

#ifndef ROAD_H
#define ROAD_H

#include <QObject>
#include <QString>
#include <QStringList>

#include "gmlidobject.h"
#include "gmlobject.h"
#include "gml_global.h"

GML_BEGIN_NAMESPACE


class GMLLineString;

class Road : public GMLObject, public GMLIdObject {
    Q_OBJECT
  public:
    enum Classification {
        A_ROAD,
        B_ROAD,
        LOCAL_STREET,
        MINOR_ROAD,
        MOTORWAY,
        PEDESTRIANISED_STREET,
        PRIMARY_ROAD,
        PRIVATE_ROAD_PUBLICALLY_ACCESSIBLE,
        A_ROAD_COLLAPSED_DUAL_CARRIAGEWAY,
        B_ROAD_COLLAPSED_DUAL_CARRIAGEWAY,
        MINOR_ROAD_COLLAPSED_DUAL_CARRIAGEWAY,
        MOTORWAY_COLLAPSED_DUAL_CARRIAGEWAY,
        PRIMARY_ROAD_COLLAPSED_DUAL_CARRIAGEWAY,
    };

    explicit Road( QString referenceSquare, QObject *parent = 0 );

  signals:

  public:
    Classification toType( QString type ) ;
    QString toString( Classification type );

    void setDistinctiveName(QString name);
    QString distinctiveName();
    void setRoadNumber(QString number);
    QString roadNumber();
    void setClassification(Classification type);
    Classification classification();
    void setLine(GMLLineString *line);
    GMLLineString* line();

  protected:
    QStringList names;
    QString mDistinctiveName;
    QString mRoadNumber;
    Classification mClassification;
    GMLLineString *pCentreLine;

    void initNames();

};

GML_END_NAMESPACE
#endif // ROAD_H
