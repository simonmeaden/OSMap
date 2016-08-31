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

#include "gmlreader.h"

#include "objects/featurecollection.h"
#include "objects/featureobject.h"
#include "objects/terrain50.h"
#include "objects/spotheight.h"
#include "objects/contourline.h"
#include "objects/landwaterboundary.h"

#include "objects/gmlpos.h"
#include "objects/gmlposlist.h"
#include "objects/gmllinestring.h"

#include "sql.h"

#include "global.h"
#include "gml_global.h"
#include "objects/gmlenum.h"

#include "osdb.h"

GML_BEGIN_NAMESPACE

OSDB_USE_NAMESPACE

GMLReader::GMLReader( QSharedPointer<OsDatabase> database ) :
    pDatabase( database ) {

    pDatabase->open();

}

GMLReader::~GMLReader() {
    pDatabase->close();
}

bool GMLReader::readOSGml( QStringList names ) {
    foreach ( QString filename, names ) {
        QFile file( filename );

        if ( file.exists() ) {
            return readOSGml( &file );
        }
    }
}

bool GMLReader::readOSTerrain50GML( QStringList names ) {
    foreach ( QString filename, names ) {
        QFile file( filename );

        if ( file.exists() ) {
            readOSTerrain50GML( &file );
        }

    }
}

bool GMLReader::readOSTerrain50GML( QIODevice *device ) {

    if ( !device->open( QIODevice::ReadOnly | QIODevice::Text ) ) {
        //        qDebug() << "Cannot read file" << file.errorString();
        return false;
    }

    pReader = new QXmlStreamReader( device );

    mFeatureObject = QSharedPointer<FeatureObject>( new Terrain50() );
    QSharedPointer<Terrain50> terrain50 = qSharedPointerDynamicCast<Terrain50>( mFeatureObject );

    while ( pReader->readNextStartElement() ) {
        QString name = pReader->name().toString();

        if ( name == "DataSet" ) {

            parseBaseFeatures( terrain50 );

        } else if ( name == "boundedBy" ) {
            bool success = parseBoundedBy( terrain50 );

            if ( !success ) {
                pReader->raiseError( QObject::tr( "Problem importing file!" ) );
                return pReader->error();
            }

            pReader->skipCurrentElement();

        } else if ( name == "nominalScale" ) {

            QString s = pReader->readElementText();
            terrain50->setNominalScale( s.toInt() );

        } else if ( name == "elevationReference" ) {

            QString s = pReader->readElementText();
            terrain50->setElevationReference( s.toInt() );

        } else if ( name == "equidistance" ) {

            QXmlStreamAttributes att = pReader->attributes();
            //            QString uom = att.value( "uom" ).toString();
            QString s = pReader->readElementText();

            terrain50->setEquidistance( s.toInt() );
            //            terrain50->setUom( uom );

        } else if ( name == "member" ) {

            parseDatasetMember();

        } else {
            pReader->skipCurrentElement();
        }
    }

    pDatabase->writeTerrain( terrain50 );

    return !pReader->error();
}

bool GMLReader::readOSGml( QIODevice *device ) {

    if ( !device->open( QIODevice::ReadOnly | QIODevice::Text ) ) {
        //        qDebug() << "Cannot read file" << file.errorString();
        return false;
    }

    pReader = new QXmlStreamReader( device );
    mFeatureObject = QSharedPointer<FeatureObject>( new FeatureCollection() );
    QSharedPointer<FeatureCollection> featureCollection = qSharedPointerDynamicCast<FeatureCollection>( mFeatureObject );

    while ( pReader->readNextStartElement() ) {
        QString name = pReader->name().toString();

        if ( name == "FeatureCollection" ) {

            parseBaseFeatures( mFeatureObject );

        } else if ( name == "boundedBy" ) {
            bool success = parseBoundedBy( mFeatureObject );

            if ( !success ) {
                pReader->raiseError( QObject::tr( "Problem importing file!" ) );
                return pReader->error();
            }

            pReader->skipCurrentElement();

        } else if ( name == "featureMember" ) {

            parseFeatureMember( featureCollection );

        } else {
            pReader->skipCurrentElement();
        }
    }

    return !pReader->error();
}

void GMLReader::parseBaseFeatures( QSharedPointer<FeatureObject> featureObject ) {
    QString id = pReader->attributes().value( "gml:id" ).toString();
    QStringList split = id.split( ".", QString::KeepEmptyParts );
    QString name = split.at( 1 );
    QString yearStr = split.at( 2 );
    int year =  yearStr.toInt();
    QString reference = name;
    QString quarter;

    if ( split.size() > 3 ) {
        quarter = split.at( 3 );
    }


    featureObject->setReferenceSquare( reference );
    featureObject->setYear( year );
    featureObject->setQuarter( quarter );
}

bool GMLReader::parseDatasetMember( /*QSharedPointer<Terrain50> terrain50*/ ) {

    pReader->readNextStartElement();
    QString name = pReader->name().toString();

    if ( name == "SpotHeight" ) {

        parseSpotHeight();

    } else if ( name == "ContourLine" ) {

        parseContourLine();

    } else if ( name == "LandWaterBoundary" ) {

        parseLandWaterBoundary();

    } else {
        //        out << "Neither SpotHeight, ContourLine or LandWaterBoundary : " << name << endl;
    }

    pReader->skipCurrentElement();
    //    name = pReader->name().toString();

    return !pReader->error();

}

bool GMLReader::parseSpotHeight() {

    QString att = pReader->attributes().value( "gml:id" ).toString();
    QStringList split = att.split( ".", QString::KeepEmptyParts );
    QString refSquare = split.at( 2 );
    QString id = split.at( 3 );
    int x, y, idNumber = id.toInt();
    QString s, name;

    pReader->readNextStartElement();
    name = pReader->name().toString(); // geometry

    if ( name == "geometry" ) {

        pReader->readNextStartElement();
        name = pReader->name().toString(); // Point

        QSharedPointer<SpotHeight> spotHeight = QSharedPointer<SpotHeight>( new SpotHeight( refSquare, idNumber ) );

        if ( name == "Point" ) {

            pReader->readNextStartElement();
            name = pReader->name().toString(); // pos

            if ( name == "pos" ) {

                s = pReader->readElementText();
                split = s.split( " ", QString::KeepEmptyParts );

                if ( split.size() != 2 ) {
                    pReader->raiseError( QObject::tr( "Incorrect number of points - must be 2." ) );
                    return !pReader->error();
                }

                spotHeight->setPosition( parsePos( split.at( 0 ), split.at( 1 ) ) );

            }

            pReader->skipCurrentElement();
            //            name = pReader->name().toString(); // Point
            pReader->skipCurrentElement();
            //            name = pReader->name().toString(); // geometry

            pReader->readNextStartElement();
            name = pReader->name().toString(); // propertyValue

            if ( name == "propertyValue" ) {
                //                att = pReader->attributes().value( "uom" ).toString();
                s = pReader->readElementText();
                spotHeight->setHeight( s.toInt() );
                //                spotHeight->setUom( att );
            } else {
                // TODO throw error
            }

            pReader->readNextStartElement();
            name = pReader->name().toString(); // spotHeightType

            if ( name == "spotHeightType" ) {

                s = pReader->readElementText();

                if ( s == "generic" ) {
                    spotHeight->setType( Generic );
                } else {
                    out << "Not generic : " << s << endl;
                }


            } else {
                // TODO throw error
            }

            pDatabase->writeSpotHeight( spotHeight );
            //            terrain50->setObject( idNumber, spotHeight );

            pReader->skipCurrentElement();
            name = pReader->name().toString(); // SpotHeight
        }
    }

}

bool GMLReader::parseContourLine() {

    QString att = pReader->attributes().value( "gml:id" ).toString();
    QStringList split = att.split( ".", QString::KeepEmptyParts );
    QString refSquare = split.at( 2 );
    QString id = split.at( 3 );
    int idNumber = id.toInt();
    QString s, name;

    QSharedPointer<ContourLine> contourLine = QSharedPointer<ContourLine>( new ContourLine( refSquare, idNumber ) );

    pReader->readNextStartElement();
    name = pReader->name().toString(); // geometry

    if ( name == "geometry" ) {

        pReader->readNextStartElement();
        name = pReader->name().toString(); // Point

        if ( name == "LineString" ) {

            pReader->readNextStartElement();
            name = pReader->name().toString(); // pos

            if ( name == "posList" ) {
                contourLine->setPositions( parseLineString( ) );
            }

            pReader->skipCurrentElement();
            //            name = pReader->name().toString(); // Point
            pReader->skipCurrentElement();
            //            name = pReader->name().toString(); // geometry

            pReader->readNextStartElement();
            name = pReader->name().toString(); // propertyValue

            if ( name == "propertyValue" ) {
                //                att = pReader->attributes().value( "uom" ).toString();
                s = pReader->readElementText();
                contourLine->setHeight( s.toInt() );
                //                contourLine->setUom( att );
            } else {
                // TODO throw error
            }

            pReader->readNextStartElement();
            name = pReader->name().toString(); // contourLineType

            if ( name == "contourLineType" ) {

                s = pReader->readElementText();

                if ( s == "ordinary" ) {
                    contourLine->setType( Ordinary ); // normally ordinary
                } else {
                    //                    out << "Not ordinary : " << s << endl;
                }

            } else {
                // TODO throw error
            }

            pDatabase->writeContourLine( contourLine );
            //            terrain50->setObject( idNumber, contourLine );

            pReader->skipCurrentElement();
            name = pReader->name().toString(); // SpotHeight

        }
    }
}

QSharedPointer<GMLPosList> GMLReader::parsePosList( ) {
    QString s = pReader->readElementText();
    int x, y;
    QStringList split = s.split( " ", QString::KeepEmptyParts );
    QSharedPointer<GMLPosList> posList = QSharedPointer<GMLPosList>( new GMLPosList( ) );

    if ( split.size() % 2 != 0 ) {
        //        pReader->raiseError( QObject::tr( "Incorrect number of points - musy be multiple of 2." ) );
        //        return !pReader->error();
    }

    for ( int i = 0; i < split.size(); i += 2 ) {
        posList->addPosition( parsePos( split.at( i ), split.at( i + 1 ) ) );
    }

    return posList;

}

QSharedPointer<GMLPos> GMLReader::parsePos( QString xStr, QString yStr ) {
    int x = xStr.toInt();
    int y = yStr.toInt();
    QSharedPointer<GMLPos> pos = QSharedPointer<GMLPos>( new GMLPos() );
    pos->setPosition( x, y );
    return pos;
}

QSharedPointer<GMLLineString> GMLReader::parseLineString() {

    QSharedPointer<GMLLineString> lineString = QSharedPointer<GMLLineString>( new GMLLineString() );
    QSharedPointer<GMLPosList> posList = parsePosList();
    lineString->setPositions( posList );
    return lineString;

}

bool GMLReader::parseLandWaterBoundary( /*QSharedPointer<Terrain50> terrain50*/ ) {

    QString att = pReader->attributes().value( "gml:id" ).toString();
    QStringList split = att.split( ".", QString::KeepEmptyParts );
    QString refSquare = split.at( 2 );
    QString id = split.at( 3 );
    int x, y, idNumber = id.toInt();
    QString s, name;

    pReader->readNextStartElement();
    name = pReader->name().toString(); // geometry

    if ( name == "geometry" ) {

        pReader->readNextStartElement();
        name = pReader->name().toString(); // Point

        QSharedPointer<LandWaterBoundary> landWaterBoundary = QSharedPointer<LandWaterBoundary>( new LandWaterBoundary( refSquare, idNumber ) );

        if ( name == "LineString" ) {

            pReader->readNextStartElement();
            name = pReader->name().toString(); // pos

            if ( name == "posList" ) {
                landWaterBoundary->setPositions( parseLineString( ) );;
            }

            pReader->skipCurrentElement();
            //            name = pReader->name().toString(); // Point
            pReader->skipCurrentElement();
            //            name = pReader->name().toString(); // geometry

            pReader->readNextStartElement();
            name = pReader->name().toString(); // propertyValue

            if ( name == "propertyValue" ) {
                //                att = pReader->attributes().value( "uom" ).toString();
                s = pReader->readElementText();
                landWaterBoundary->setHeight( s.toInt() );
                //                landWaterBoundary->setUom( att );
            } else {
                // TODO throw error
            }

            pReader->readNextStartElement();
            name = pReader->name().toString(); // contourLineType

            if ( name == "waterLevelCategory" ) {

                s = pReader->readElementText();

                if ( s == "meanLowWater" ) {
                    landWaterBoundary->setType( MeanLowWater ); // normally meanLowWater
                } else if (  s == "meanHighWater" ) {
                    landWaterBoundary->setType( MeanHighWater ); // normally meanLowWater
                } else {
                    out << "Not meanLowWater or meanHighWater : " << s << endl;
                }

            } else {
                // TODO throw error
            }

            pDatabase->writeLandWater( landWaterBoundary );
            //            terrain50->setObject( idNumber, landWaterBoundary );

            pReader->skipCurrentElement();
            name = pReader->name().toString(); // SpotHeight

            //                                  <os: propertyValue uom = "m">227 < / os:propertyValue >
            //                                  <os: spotHeightType>generic < / os:spotHeightType >
        }
    }

}

bool GMLReader::parseFeatureMember( QSharedPointer<FeatureCollection> featureCollection ) {
    pReader->readNextStartElement();
    QString name = pReader->name().toString();

    if ( name == "featureMember" ) {

        pReader->readNextStartElement();
        name = pReader->name().toString();

        if ( name == "Woodland" ) {
            parseWoodland( featureCollection );
        }

    }

    return !pReader->error();

}

bool GMLReader::parseWoodland( QSharedPointer<FeatureCollection> featureCollection ) {

}

bool GMLReader::parseBoundedBy( QSharedPointer<FeatureObject> featureObject ) {

    pReader->readNextStartElement();
    QString name = pReader->name().toString();

    if ( name == "Envelope" ) {

        pReader->readNextStartElement();

        setUpperOrLowerBounds( featureObject );

        pReader->readNextStartElement();

        setUpperOrLowerBounds( featureObject );

        pReader->skipCurrentElement();

    }

    return !pReader->error();

}

void GMLReader::setUpperOrLowerBounds( QSharedPointer<FeatureObject> featureObject ) {

    int x, y;
    QString s, name = pReader->name().toString();
    QStringList split;

    if ( name == "lowerCorner" )  {

        s = pReader->readElementText();
        split = s.split( " ", QString::KeepEmptyParts );
        x = split.at( 0 ).toInt();
        y = split.at( 1 ).toInt();
        featureObject->setLower( x, y );

    } else if ( name == "upperCorner" ) {

        s = pReader->readElementText();
        split = s.split( " ", QString::KeepEmptyParts );
        x = split.at( 0 ).toInt();
        y = split.at( 1 ).toInt();
        featureObject->setUpper( x, y );
    }
}

QString GMLReader::errorString() const {
    return QObject::tr( "%1\nLine %2, column %3" )
           .arg( pReader->errorString() )
           .arg( pReader->lineNumber() )
           .arg( pReader->columnNumber() );
}

GML_END_NAMESPACE
