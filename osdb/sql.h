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

#ifndef SQL_H
#define SQL_H

#include <QString>

#include "osdbnamespace.h"

OSDB_BEGIN_NAMESPACE

class SqlStrings {
    public:

        static const QString CreateDatabase;

        static const QString CreateReferenceSquare;

        static const QString CreatePositions;
        static const QString CreateTerrain;
        static const QString CreateSpotHeight;
        static const QString CreateContourLine;
        static const QString CreateContourPositions;
        static const QString CreateLandWater;
        static const QString CreateLandWaterPositions;

        static const QString InsertPosition;
        static const QString InsertSpotHeight;
        static const QString InsertContourLine;
        static const QString InsertContourPositions;
        static const QString InsertLandWater;
        static const QString InsertLandWaterPositions;


        static const QString DeleteTerrain;
        static const QString DeletePosition;
        static const QString DeleteSpotHeight;
        static const QString DeleteContourLine;
        static const QString DeleteContourPositions;
        static const QString DeleteLandWater;
        static const QString DeleteLandWaterPositions;

        static const QString GetLastId;
        static const QString GetSpotHeightPosId;
        static const QString GetContourId;
        static const QString GetContourPosId;
        static const QString GetLandWaterId;
        static const QString GetLandWaterPosId;
        static const QString GetTerrain;

};

OSDB_END_NAMESPACE
#endif // SQL_H
