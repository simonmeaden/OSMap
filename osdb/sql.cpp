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

#include "sql.h"
#include "osdbnamespace.h"

OSDB_BEGIN_NAMESPACE

const QString SqlStrings::CreateDatabase = "CREATE DATABASE IF NOT EXISTS ";

/*
 * Table creation strings
 */
const QString SqlStrings::CreatePositions =
    "CREATE TABLE IF NOT EXISTS positions (id INTEGER PRIMARY KEY, x INTEGER NOT NULL, y INTEGER NOT NULL);";

const QString SqlStrings::CreateTerrain =
    "CREATE TABLE IF NOT EXISTS terrain (refsquare TEXT, nomscale INTEGER, elevref "
    "INTEGER, equivalue INTEGER, year INTEGER, lowerx INTEGER, upperx "
    "INTEGER, lowery INTEGER, uppery INTEGER, quarter TEXT);";

const QString SqlStrings::CreateSpotHeight =
    "CREATE TABLE IF NOT EXISTS spotheight (refsquare TEXT NOT NULL ,id INTEGER,height "
    "INTEGER, type CHAR(1), pos_id INTEGER);";

const QString SqlStrings::CreateContourLine =
    "CREATE TABLE IF NOT EXISTS contourline (refsquare TEXT NOT NULL, id INTEGER, height INTEGER,"
    " type  CHAR(1), contour_id INTEGER PRIMARY KEY);";

const QString SqlStrings::CreateContourPositions =
    "CREATE TABLE IF NOT EXISTS contourpositions (contour_id INTEGER NOT NULL, "
    "pos_id INTEGER NOT NULL, indx INTEGER NOT NULL);";

const QString SqlStrings::CreateLandWater =
    "CREATE TABLE IF NOT EXISTS landwaterboundary (refsquare TEXT NOT NULL, id INTEGER, height INTEGER,"
    " type CHAR(1), landwater_id  INTEGER PRIMARY KEY);";

const QString SqlStrings::CreateLandWaterPositions =
    "CREATE TABLE IF NOT EXISTS landwaterpositions (landwater_id INTEGER NOT NULL, "
    "pos_id  INTEGER NOT NULL, indx INTEGER NOT NULL);";

const QString SqlStrings::CreateReferenceSquare =
    "CREATE TABLE IF NOT EXISTS referencesquare (\"refsquare\" TEXT NOT NULL);";

/*
 * Insertion strings.
 */
const QString SqlStrings::InsertPosition =
    "INSERT INTO positions (x, y) VALUES (:x, :y);";

const QString SqlStrings::InsertSpotHeight =
    "INSERT INTO spotheight (refsquare, id, height, type, pos_id)"
    "VALUES (:refsquare, :id, :height, :type :pos_id);";

const QString SqlStrings::InsertContourLine =
    "INSERT INTO contourline (refsquare, id, height, type)"
    "VALUES (:refsquare, :id, :height, :type,);";

const QString SqlStrings::InsertContourPositions =
    "INSERT INTO contourpositions (contour_id, pos_id, indx) VALUES (:contour_id, :pos_id, :index);";

const QString SqlStrings::InsertLandWater =
    "INSERT INTO landwaterboundary (refsquare, id, height, type)"
    "VALUES (:refsquare, :id, :height, :type);";

const QString SqlStrings::InsertLandWaterPositions =
    "INSERT INTO landwaterpositions (landwater_id, pos_id, indx) VALUES (:landwater_id, :pos_id, :index);";


const QString SqlStrings::DeleteTerrain = "DELETE FROM terrain WHERE refsquare = :refsquare";
const QString SqlStrings::DeletePosition = "DELETE FROM position WHERE pos_id = :pos_id";
const QString SqlStrings::DeleteSpotHeight = "DELETE FROM spotheight WHERE refsquare = :refsquare";
const QString SqlStrings::DeleteContourLine = "DELETE FROM contourline WHERE refsquare = :refsquare";
const QString SqlStrings::DeleteContourPositions = "DELETE FROM contourpositions WHERE contour_id = :contour_id";
const QString SqlStrings::DeleteLandWater = "DELETE FROM landwaterbondary WHERE refsquare = :refsquare";
const QString SqlStrings::DeleteLandWaterPositions = "DELETE FROM landwaterpositions WHERE landwater_id = :landwater_id";

const QString SqlStrings::GetLastId = "SELECT last_insert_rowid();";
const QString SqlStrings::GetSpotHeightPosId = "SELECT pos_id FROM spotheight WHERE refsquare=:refsquare";
const QString SqlStrings::GetContourId = "SELECT contour_id FROM contourline WHERE refsquare=:refsquare";
const QString SqlStrings::GetContourPosId = "SELECT pos_id FROM contourpositions WHERE contour_id=:contour_id";
const QString SqlStrings::GetLandWaterId = "SELECT landwater_id FROM landwaterboundary WHERE refsquare=:refsquare";
const QString SqlStrings::GetLandWaterPosId = "SELECT pos_id FROM landwaterpositions WHERE landwater_id=:landwater_id";
const QString SqlStrings::GetTerrain = "SELECT * FROM terrain WHERE refsquare=:refsquare";


OSDB_END_NAMESPACE
