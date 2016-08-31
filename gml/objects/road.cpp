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

#include "road.h"

#include "gmllinestring.h"
#include "gml_global.h"

GML_BEGIN_NAMESPACE


/*!
    \class Road

    \brief Defines a Road centre line.

    Defines all of the objects required to draw a road in the OpenData Vector format.

    \author Simon Meaden
    \date   16Jun 2016
*/


/*!
    \enum Road::Classification

    An enumeration defining the types of road available to this product.

    \value A_ROAD
    a single carriagway A-Road
    \value B_ROAD
    a single carriagway B-Road
    \value LOCAL_STREET
    a local street
    \value MINOR_ROAD
    a Minor road
    \value MOTORWAY
    a single carriagway Motorway
    \value PEDESTRIANISED_STREET
    a pedestrianised street
    \value PRIMARY_ROAD
    a single carriagway primary road
    \value PRIVATE_ROAD_PUBLICALLY_ACCESSIBLE
    a publically available private road
    \value A_ROAD_COLLAPSED_DUAL_CARRIAGEWAY
    a dual carriagway A-Road
    \value B_ROAD_COLLAPSED_DUAL_CARRIAGEWAY
     a dual carriagway B-Road
    \value MINOR_ROAD_COLLAPSED_DUAL_CARRIAGEWAY
     a dual carriagway minor road
    \value MOTORWAY_COLLAPSED_DUAL_CARRIAGEWAY
     a dual carriagway motorway
    \value PRIMARY_ROAD_COLLAPSED_DUAL_CARRIAGEWAY
     a dual carriagway primary road
*/

Road::Road( QString id, QObject *parent ) : GMLObject(parent), GMLIdObject( id ) {
}

void Road::initNames() {
    names << "A Road" <<
          "B Road" <<
          "Local Street" <<
          "Minor Road" <<
          "Motorway" << "Pedestrianised Street" <<
          "Primary Road" <<
          "Private Road Publicly Accessible" <<
          "A Road<< Collapsed Dual Carriageway" <<
          "B Road<< Collapsed Dual Carriageway" <<
          "Minor Road<< Collapsed Dual Carriageway" <<
          "Motorway<< Collapsed Dual Carriageway" <<
          "Primary Road<< Collapsed Dual Carriageway";
}

Road::Classification Road::toType( QString type ) {
    if ( type == names.at( 0 ) ) {
        return A_ROAD;
    } else if ( type == names.at( 1 ) ) {
        return B_ROAD;
    } else if ( type == names.at( 2 ) ) {
        return LOCAL_STREET;
    } else if ( type == names.at( 3 ) ) {
        return MINOR_ROAD;
    } else if ( type == names.at( 4 ) ) {
        return MOTORWAY;
    } else if ( type == names.at( 5 ) ) {
        return PEDESTRIANISED_STREET;
    } else if ( type == names.at( 6 ) ) {
        return PRIMARY_ROAD;
    } else if ( type == names.at( 7 ) ) {
        return PRIVATE_ROAD_PUBLICALLY_ACCESSIBLE;
    } else if ( type == names.at( 8 ) ) {
        return A_ROAD_COLLAPSED_DUAL_CARRIAGEWAY;
    } else if ( type == names.at( 9 ) ) {
        return B_ROAD_COLLAPSED_DUAL_CARRIAGEWAY;
    } else if ( type == names.at( 10 ) ) {
        return MINOR_ROAD_COLLAPSED_DUAL_CARRIAGEWAY;
    } else if ( type == names.at( 11 ) ) {
        return MOTORWAY_COLLAPSED_DUAL_CARRIAGEWAY;
    } else
        /* if (type == names.at(12) */
    {
        return PRIMARY_ROAD_COLLAPSED_DUAL_CARRIAGEWAY;
    }
}

QString Road::toString( Classification type ) {
    return names.at( type );
}

Road::Classification Road::classification() {
    return mClassification;
}

void Road::setClassification( Classification type ) {
    mClassification = type;
}

void Road::setDistinctiveName( QString name ) {
    mDistinctiveName = name;
}

QString Road::distinctiveName() {
    return mDistinctiveName;
}

void Road::setRoadNumber( QString number ) {
    mRoadNumber = number;
}

QString Road::roadNumber() {
    return mRoadNumber;
}

void Road::setLine( GMLLineString *line ) {
    pCentreLine = line;
}

GMLLineString *Road::line() {
    return pCentreLine;
}

GML_END_NAMESPACE
