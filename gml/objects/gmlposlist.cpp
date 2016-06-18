/*!
    \file gmlposlist.cpp

    \author Simon Meaden
    \date   18 Jun 2016

    Stores a GML poslist. A poslist is defined by a set of number pairs specifying a
    list of consecutive position in metres to a one centimetre accuracy.
*/
#include "gmlposlist.h"


/*!
    \class GMLPosList

    \brief Stores a list of position pairs as integer pairs.

    Pairs are specified to one centimetre accuracy.

    \author Simon Meaden
    \date   18 Jun 2016
*/

/*!
    \fn GMLPosList(QObject *parent)

    \brief Constructor for GMLPosList.

    Basic constructor with no values specified. Positions can be added later using
    one of the GMLPosList::addPosition or GMLPosList::addPositions methods.

    \sa GMLPosList::addPosition(QString, QString)
    \sa GMLPosList::addPosition(int, int)
    \sa GMLPosList::addPosition(QPair<int, int>)
    \sa GMLPosList::addPositions(QList<int>)
    \sa GMLPosList::addPositions(QList<QPair<int, int>>)

    \note All positions are defined in centimetres.
*/
GMLPosList::GMLPosList( QObject *parent ) : QObject( parent ) {
}

/*!
    \fn GMLPosList::addPosition( QString x, QString y )

    \brief Add a position as two strings.

    GML Strings are double values defined in metres to a one centimetre accuracy
    for example 125675.23.

    \sa GMLPosList::addPosition(int, int)
    \sa GMLPosList::addPosition(QPair<int, int>)
    \sa GMLPosList::addPositions(QList<int>)
    \sa GMLPosList::addPositions(QList<QPair<int, int>>)

    \note All positions are defined in centimetres.
*/
void GMLPosList::addPosition( QString x, QString y ) {
    QPair<int, int> pair = qMakePair( ( x.toInt() * 100 ), ( y.toInt() * 100 ) );
    addPosition( pair );
}

/*!
    \fn GMLPosList::addPosition( QString x, QString y )

    \brief Add a position as two integer values in centimetres.

    \sa GMLPosList::addPosition(QString, QString)
    \sa GMLPosList::addPosition(QPair<int, int>)
    \sa GMLPosList::addPositions(QList<int>)
    \sa GMLPosList::addPositions(QList<QPair<int, int>>)

    \note All positions are defined in centimetres.
*/
void GMLPosList::addPosition( int x, int y ) {
    QPair<int, int> pair = qMakePair( x, y );
    addPosition( pair );
}

/*!
    \fn GMLPosList::addPosition( QPair<int, int> )

    \brief Add a position as two integer values in centimetres.

    \sa GMLPosList::addPosition(QString, QString)
    \sa GMLPosList::addPosition(int, int)
    \sa GMLPosList::addPositions(QList<int>)
    \sa GMLPosList::addPositions(QList<QPair<int, int>>)

    \note All positions are defined in centimetres.
*/
void GMLPosList::addPosition( QPair<int, int> position ) {
    addPosition( position );
}

/*!
    \fn GMLPosList::addPositions( QList<int> )

    \brief Add a set of position pairs as a single list of centimetre
    accuracy integer values.

    \sa GMLPosList::addPosition(QString, QString)
    \sa GMLPosList::addPosition(int, int)
    \sa GMLPosList::addPosition(QPair<int, int>)
    \sa GMLPosList::addPositions(QList<int>)
    \sa GMLPosList::addPositions(QList<QPair<int, int>>)

    \note All positions are defined in centimetres.

    \warning The number of values in the list MUST be a multiple of two.
*/
void GMLPosList::addPositions( QList<int> list ) {
    Q_ASSERT_X( ( list.size() % 2 > 0 ), "position add", "position count must be a multiple of two" );
    int size = list.size() / 2;

    for ( int i = 0; i < size; i++ ) {
        addPosition( list.at( i ), list.at( i + 1 ) );
    }
}

/*!
    \fn GMLPosList::addPositions( QList<QPair<int, int> > )

    \brief Add a set of position pairs as a single list of centimetre
    accuracy integer pairs.

    \sa GMLPosList::addPosition(QString, QString)
    \sa GMLPosList::addPosition(int, int)
    \sa GMLPosList::addPosition(QPair<int, int>)
    \sa GMLPosList::addPositions(QList<int>)
    \sa GMLPosList::addPositions(QList<int>)

    \note All positions are defined in centimetres.
*/
void GMLPosList::addPositions( QList<QPair<int, int> > list ) {
    for ( int i = 0; i < list.size(); i++ ) {
        addPosition( list.at( i ) );
    }
}

/*!
    \fn GMLPosList::clear()

    \brief Removes all existing items and leaves an empty list.
*/
void GMLPosList::clear() {
    qDeleteAll( mPositions );
    mPositions.clear();
}
