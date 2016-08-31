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

#include "osdb.h"
#include "osdb_global.h"
#include "sql.h"
#include "objects/terrain50.h"
#include "objects/spotheight.h"
#include "objects/contourline.h"
#include "objects/landwaterboundary.h"
#include "objects/gmlpos.h"

OSDB_BEGIN_NAMESPACE

GML_USE_NAMESPACE

QTextStream out( stdout );

const QString OsDatabase::mDatabaseName = "osdb.sqlite";

OsDatabase::OsDatabase() {

    mDb = QSqlDatabase::addDatabase( "QSQLITE" );
    mDb.setDatabaseName( mDatabaseName );

    open();

}

bool OsDatabase::open() {
    if ( !mDb.isOpen() ) {
        if ( !mDb.open() ) {
//            out << "Error: connection with database fail" << endl;
            return false;
        } else {
//            out << "Database: connection ok" << endl;
            createDatabaseIfRequired();
            return true;
        }
    }
}

void OsDatabase::close() {
    if ( mDb.isOpen() ) {
        mDb.close();
    }
}

void OsDatabase::createDatabaseIfRequired() {
    QSqlQuery query;

    query.prepare( SqlStrings::CreateDatabase + mDatabaseName );

    if ( !query.exec() ) {
//        out << "CreateDatabase error : " << query.lastError().text() << endl;
    }

    query.prepare( SqlStrings::CreateTerrain );
    query.exec();

    if ( !query.exec() ) {
//        out << "CreateTerrain error:  " << query.lastError().text() << endl;
    }

    query.prepare( SqlStrings::CreateSpotHeight );
    query.exec();

    if ( !query.exec() ) {
//        out << "CreateSpotHeight error:  " << query.lastError().text() << endl;
    }

    query.prepare( SqlStrings::CreateContourLine );
    query.exec();

    if ( !query.exec() ) {
//        out << "CreateContourLine error:  " << query.lastError().text() << endl;
    }

    query.prepare( SqlStrings::CreateContourPositions );
    query.exec();

    if ( !query.exec() ) {
//        out << "CreateContourPositions error:  " << query.lastError().text() << endl;
    }

    query.prepare( SqlStrings::CreateLandWater );
    query.exec();

    if ( !query.exec() ) {
//        out << "CreateLandWater error:  " << query.lastError().text() << endl;
    }

    query.prepare( SqlStrings::CreateLandWaterPositions );
    query.exec();

    if ( !query.exec() ) {
//        out << "CreateLandWaterPositions error:  " << query.lastError().text() << endl;
    }

    query.prepare( SqlStrings::CreatePositions );
    query.exec();

    if ( !query.exec() ) {
//        out << "CreatePositions error:  " << query.lastError().text() << endl;
    }

    query.prepare( SqlStrings::CreateReferenceSquare );
    query.exec();

    if ( !query.exec() ) {
//        out << "CreateReferenceSquare error:  " << query.lastError().text() << endl;
    }

}

void OsDatabase::write() {

}

bool OsDatabase::writeTerrain( QSharedPointer<Terrain50> terrain50 ) {

    if ( !checkTerrainOverwrite( terrain50->referenceSquare() ) ) {
        // doesn't exist so far so INSERT
        return insertTerrain( terrain50 );
    } else {
        // exists so delete old value
        deleteTerrain( terrain50 );
        // then insert new value.
        insertTerrain( terrain50 );
    }
}

bool OsDatabase::deleteTerrain( QSharedPointer<Terrain50> terrain50 ) {
    int posId;
    QString refSquare = terrain50->referenceSquare();
    QSqlQuery query1, query2;

    deleteSpotHeights( refSquare );
    deleteContourLines( refSquare );
    deleteLineWaterBoundaties( refSquare );

    // finally delete the terrain50
    query1.prepare( SqlStrings::DeleteTerrain );
    query1.bindValue( ":refsquare", refSquare );

    if ( !query1.exec() ) {
//        out << "add get delete terrain error:  " << query1.lastError().text() << endl;
    }

}

bool OsDatabase::deleteSpotHeights( QString refSquare ) {
    QSqlQuery query;
    // get all pos_id for spotheight's with the refsquare
    query.prepare( SqlStrings::GetSpotHeightPosId );
    query.bindValue( ":refsquare", refSquare );

    if ( !query.exec() ) {
//        out << "add get spotheight pos id error:  " << query.lastError().text() << endl;
    }

    // only one position in spotheight
    if ( query.next() ) {
        int posId = query.value( "pos_id" ).toInt();
        deletePosition( posId );
    }

    // then delete the spotheight's
    query.prepare( SqlStrings::DeleteSpotHeight );
    query.bindValue( ":refsquare", refSquare );

    if ( !query.exec() ) {
//        out << "add delete spotheight error:  " << query.lastError().text() << endl;
    }

}

bool OsDatabase::deleteContourLines( QString refSquare ) {
    QSqlQuery query1, query2;
    query1.prepare( SqlStrings::GetContourId );
    query1.bindValue( ":refsquare", refSquare );

    if ( !query1.exec() ) {
//        out << "add get contour id error:  " << query1.lastError().text() << endl;
    }

    // work through each pos_id deleting positions
    while ( query1.next() ) {
        int contourId = query1.value( "contour_id" ).toInt();

        query2.prepare( SqlStrings::GetContourPosId );
        query2.bindValue( ":contour_id", contourId );

        if ( !query2.exec() ) {
//            out << "add get pos_id error:  " << query1.lastError().text() << endl;
        }

        while ( query2.next() ) {
            int posId = query2.value( "pos_id" ).toInt();
            deletePosition( posId );
        }

        query2.prepare( SqlStrings::DeleteContourPositions );
        query2.bindValue( ":countour_id", contourId );

        if ( !query2.exec() ) {
//            out << "add delete contour_id error:  " << query1.lastError().text() << endl;
        }
    }

    query1.prepare( SqlStrings::DeleteContourLine );
    query1.bindValue( ":refsquare", refSquare );

    if ( !query1.exec() ) {
//        out << "add get contour id error:  " << query1.lastError().text() << endl;
    }

}

bool OsDatabase::deletePosition( int posId ) {
    QSqlQuery query;
    query.prepare( SqlStrings::DeletePosition );
    query.bindValue( ":pos_id", posId );

    if ( !query.exec() ) {
//        out << "add delete position error:  " << query.lastError().text() << endl;
    }
}

bool OsDatabase::deleteLineWaterBoundaties( QString refSquare ) {
    QSqlQuery query1, query2;
    query1.prepare( SqlStrings::GetLandWaterId );
    query1.bindValue( ":refsquare", refSquare );

    if ( !query1.exec() ) {
//        out << "add get linewater id error:  " << query1.lastError().text() << endl;
    }

    // work through each pos_id deleting positions
    while ( query1.next() ) {
        int landWaterId = query1.value( "linewater_id" ).toInt();

        query2.prepare( SqlStrings::GetLandWaterPosId );
        query2.bindValue( ":landwater_id", landWaterId );

        if ( !query2.exec() ) {
//            out << "add get pos_id error:  " << query1.lastError().text() << endl;
        }

        while ( query2.next() ) {
            int posId = query2.value( "pos_id" ).toInt();
            deletePosition( posId );
        }

        query2.prepare( SqlStrings::DeleteLandWaterPositions );
        query2.bindValue( ":countour_id", landWaterId );

        if ( !query2.exec() ) {
//            out << "add delete landwater error:  " << query1.lastError().text() << endl;
        }
    }

    query1.prepare( SqlStrings::DeleteLandWater );
    query1.bindValue( ":refsquare", refSquare );

    if ( !query1.exec() ) {
//        out << "add get landwater id error:  " << query1.lastError().text() << endl;
    }
}

bool OsDatabase::insertTerrain( QSharedPointer<Terrain50> terrain50 ) {
    QSqlQuery query
    ;
    query.prepare( "INSERT INTO terrain "
                   "(refsquare, nomscale, elevref, uom, equivalue, year, lowerx, lowery, upperx, uppery, quarter) "
                   "VALUES "
                   "(:refsquare, :nomscale, :elevref, :uom, :equivalue, :year, "
                   ":lowerx, :lowery, :upperx, :uppery, :quarter)" );
    query.bindValue( ":refsquare", terrain50->referenceSquare() );
    query.bindValue( ":nomscale", terrain50->nominalScale() );
    query.bindValue( ":elevref", terrain50->elevationReference() );
//    query.bindValue( ":uom", terrain50->uom() );
    query.bindValue( ":equivalue", terrain50->equidistance() );
    query.bindValue( ":year", terrain50->year() );
    query.bindValue( ":lowerx", terrain50->lowerX() );
    query.bindValue( ":lowery", terrain50->lowerY() );
    query.bindValue( ":upperx", terrain50->upperX() );
    query.bindValue( ":uppery", terrain50->upperY() );
    query.bindValue( ":quarter", terrain50->quarter() );

    if ( !query.exec() ) {
//        out << "add terrain error:  " << query.lastError().text() << endl;
//        return false;
    }

    return true;
}

bool OsDatabase::writeSpotHeight( QSharedPointer<SpotHeight> spotHeight ) {
    QSharedPointer<GMLPos> pos;
    int posId = -1;
    QSqlQuery query;

    pos = spotHeight->position();

    QSqlDatabase::database().transaction();
    query.prepare( SqlStrings::InsertPosition );
    query.bindValue( ":x", pos->x() );
    query.bindValue( ":y", pos->y() );

    if ( !query.exec() ) {
//        out << "add position error:  " << query.lastError().text() << endl;
//        return false;
    }

    query.prepare( SqlStrings::GetLastId );

    if ( !query.exec() ) {
//        out << "add position error:  " << query.lastError().text() << endl;
//        return false;
    }

    if ( query.next() ) {
        posId = query.value( 0 ).toInt();
    }

    query.prepare( SqlStrings::InsertSpotHeight );
    query.bindValue( ":refsquare", spotHeight->referenceSquare() );
    query.bindValue( ":id", spotHeight->idNumber() );
    query.bindValue( ":height", spotHeight->height() );
    query.bindValue( ":heighttype", (int)(spotHeight->type()) );
//    query.bindValue( ":uom", spotHeight->uom() );
    query.bindValue( ":pos_id", posId );

    if ( !query.exec() ) {
//        out << "add position error:  " << query.lastError().text() << endl;
//        return false;
    }
    QSqlDatabase::database().commit();

    out << "Spotheight Complete : " << spotHeight->idNumber() << endl;

}

bool OsDatabase::writeContourLine( QSharedPointer<ContourLine> contourLine ) {
    QSharedPointer<GMLPos> pos;
    QSqlQuery query1, query2, query3;
    int posId = -1;
    int contourId = -1;

    // insert contour line data
    QSqlDatabase::database().transaction();
    query1.prepare( SqlStrings::InsertContourLine );
    query1.bindValue( ":refsquare", contourLine->referenceSquare() );
    query1.bindValue( ":id", contourLine->idNumber() );
    query1.bindValue( ":height", contourLine->height() );
    query1.bindValue( ":heighttype", (int)(contourLine->type()) );
//    query1.bindValue( ":uom", contourLine->uom() );

    // recover auto id for contour line
    if ( !query1.exec() ) {
//        out << "add contourline error:  " << query.lastError().text() << endl;
//        return false;
    }

    query1.prepare( SqlStrings::GetLastId );

    if ( !query1.exec() ) {
//        out << "add position error:  " << query.lastError().text() << endl;
//        return false;
    }

    if ( query1.next() ) {
        contourId = query1.value( 0 ).toInt();
    }

    QSharedPointer<GMLPosList> positions = contourLine->positions()->positions();

    // for each position
    query1.prepare( SqlStrings::InsertPosition );
    query2.prepare( SqlStrings::GetLastId );
    query3.prepare( SqlStrings::InsertContourPositions );
    for ( int index = 0; index < positions->size(); index++ ) {
        pos = positions->position( index );

        // store the position and get it's id
        query1.bindValue( ":x", pos->x() );
        query1.bindValue( ":y", pos->y() );

        if ( !query1.exec() ) {
//            out << "add position error:  " << query.lastError().text() << endl;
//            return false;
        }

        if ( !query2.exec() ) {
//            out << "add position error:  " << query.lastError().text() << endl;
//            return false;
        }

        if ( query2.next() ) {
            posId = query2.value( 0 ).toInt();
        }

        // save the position <==> contourline link
        query3.bindValue( ":contour_id", contourId );
        query3.bindValue( ":pos_id", posId );
        query3.bindValue( ":index", index );

        if ( !query3.exec() ) {
//            out << "add position error:  " << query.lastError().text() << endl;
//            return false;
        }

    }
    QSqlDatabase::database().commit();

    out << "ContourLine Complete : " << contourLine->idNumber() << endl;
}

bool OsDatabase::writeLandWater( QSharedPointer<LandWaterBoundary> landWater ) {
    QSharedPointer<GMLPos> pos;
    QSqlQuery query1, query2, query3;
    int posId = -1;
    int landWaterId = -1;

    // insert contour line data
    QSqlDatabase::database().transaction();
    query1.prepare( SqlStrings::InsertLandWater );
    query1.bindValue( ":refsquare", landWater->referenceSquare() );
    query1.bindValue( ":id", landWater->idNumber() );
    query1.bindValue( ":height", landWater->height() );
    query1.bindValue( ":heighttype", (int)(landWater->type()) );
//    query1.bindValue( ":uom", landWater->uom() );

    // recover auto id for landwater line
    if ( !query1.exec() ) {
//        out << "add landwater error:  " << query.lastError().text() << endl;
//        return false;
    }

    query1.prepare( SqlStrings::GetLastId );

    if ( !query1.exec() ) {
//        out << "add landwater error:  " << query.lastError().text() << endl;
//        return false;
    }

    if ( query1.next() ) {
        landWaterId = query1.value( 0 ).toInt();
    }

    QSharedPointer<GMLPosList> positions = landWater->positions()->positions();

    // for each position
    query1.prepare( SqlStrings::InsertPosition );
    query2.prepare( SqlStrings::GetLastId );
    query3.prepare( SqlStrings::InsertLandWaterPositions );
    for ( int index = 0; index < positions->size(); index++ ) {
        pos = positions->position( index );

        // store the position and get it's id
        query1.bindValue( ":x", pos->x() );
        query1.bindValue( ":y", pos->y() );

        if ( !query1.exec() ) {
//            out << "add position error:  " << query.lastError().text() << endl;
//            return false;
        }


        if ( !query2.exec() ) {
//            out << "add position error:  " << query.lastError().text() << endl;
//            return false;
        }

        if ( query2.next() ) {
            posId = query2.value( 0 ).toInt();
        }

        // save the position <==> landwater link
        query3.bindValue( ":landwater_id", landWaterId );
        query3.bindValue( ":pos_id", posId );
        query3.bindValue( ":index", index );

        if ( !query3.exec() ) {
//            out << "add position error:  " << query1.lastError().text() << endl;
//            return false;
        }
    }
    QSqlDatabase::database().commit();
    out << "LandWaterBoundary Complete : " << landWater->idNumber() << endl;

}

bool OsDatabase::checkOverwrite() {
}

bool OsDatabase::checkTerrainOverwrite( QString refSquare ) {

    QSqlQuery query;

    query.prepare( SqlStrings::GetTerrain );
    query.bindValue( ":refsquare", refSquare );

    if ( query.exec() ) {
        if ( query.next() ) {
            return true;
        }
    }

//    out << "add check error:  " << query.lastError().text() << endl;

    return false;
}

OSDB_END_NAMESPACE
