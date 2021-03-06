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

#ifndef GMLPOSLIST_H
#define GMLPOSLIST_H

#include <QObject>
#include <QList>
#include <QPair>
#include <QSharedPointer>

#include "gml_global.h"

GML_BEGIN_NAMESPACE

class GMLPos;

class GMLSHARED_EXPORT GMLPosList : public QObject {
    Q_OBJECT
  public:
    explicit GMLPosList( QObject *parent = 0 );

  public:
    void addPosition(QSharedPointer<GMLPos> pos );
    void setPositions( QList<QSharedPointer<GMLPos>> );
    void clear();
    int size();

    QSharedPointer<GMLPos> first() { return mPositions.at( 0 ); }
    QSharedPointer<GMLPos> last() { return mPositions.last(); }
    QSharedPointer<GMLPos> position(int i) { return mPositions.at(i); }

  protected:
    QList<QSharedPointer<GMLPos> > mPositions;
};

GML_END_NAMESPACE
#endif // GMLPOSLIST_H
