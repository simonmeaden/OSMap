#include "road.h"

Road::Road( QString id, QObject *parent ) : GMLObject( id, parent ) {
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

Road::Type Road::toType( QString type ) {
    if ( type == names.at( 0 ) )
    { return A_ROAD; }
    else if ( type == names.at( 1 ) )
    { return B_ROAD; }
    else if ( type == names.at( 2 ) )
    { return LOCAL_STREET; }
    else if ( type == names.at( 3 ) )
    { return MINOR_ROAD; }
    else if ( type == names.at( 4 ) )
    { return MOTORWAY; }
    else if ( type == names.at( 5 ) )
    { return PEDESTRIANISED_STREET; }
    else if ( type == names.at( 6 ) )
    { return PRIMARY_ROAD; }
    else if ( type == names.at( 7 ) )
    { return PRIVATE_ROAD_PUBLICALLY_ACCESSIBLE; }
    else if ( type == names.at( 8 ) )
    { return A_ROAD_COLLAPSED_DUAL_CARRIAGEWAY; }
    else if ( type == names.at( 9 ) )
    { return B_ROAD_COLLAPSED_DUAL_CARRIAGEWAY; }
    else if ( type == names.at( 10 ) )
    { return MINOR_ROAD_COLLAPSED_DUAL_CARRIAGEWAY; }
    else if ( type == names.at( 11 ) )
    { return MOTORWAY_COLLAPSED_DUAL_CARRIAGEWAY; }
    else
        /* if (type == names.at(12) */
    { return PRIMARY_ROAD_COLLAPSED_DUAL_CARRIAGEWAY; }
}

QString Road::toString( Type type ) {
    return names.at( type );
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
