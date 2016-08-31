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

#ifndef OSDB_H
#define OSDB_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSharedPointer>
#include <QString>
#include <QTextStream>
#include <QFile>

#include "osdb_global.h"
#include "osdbnamespace.h"
#include "gmlnamespace.h"

GML_BEGIN_NAMESPACE // Forward declarations

class Terrain50;
class SpotHeight;
class ContourLine;
class LandWaterBoundary;

GML_END_NAMESPACE


OSDB_BEGIN_NAMESPACE

class OSDBSHARED_EXPORT OsDatabase {

    public:
        OsDatabase();

        bool open();
        void close();
        void write();
        bool writeTerrain( QSharedPointer<Terrain50> terrain50 );

        bool writeSpotHeight( QSharedPointer<SpotHeight> spotHeight );
        bool writeContourLine( QSharedPointer<ContourLine> spotHeight );
        bool writeLandWater( QSharedPointer<LandWaterBoundary> landWater );


    protected:
        QSqlDatabase mDb;

        static const QString mDatabaseName;

        void createDatabaseIfRequired();

        bool checkOverwrite();
        bool checkTerrainOverwrite( QString refSquare );

        bool insertTerrain( QSharedPointer<Terrain50> terrain50 );

        bool deleteTerrain( QSharedPointer<Terrain50> terrain50 );
        bool deleteSpotHeights( QString refSquare );
        bool deleteContourLines( QString refSquare );
        bool deleteLineWaterBoundaties( QString refSquare );
        bool deletePosition( int posId );

};

OSDB_END_NAMESPACE
#endif // OSDB_H
