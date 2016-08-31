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

#include "featureobject.h"
#include "gml_global.h"

GML_BEGIN_NAMESPACE


FeatureObject::FeatureObject( QObject *parent ) :
    QObject( parent ) {

}

QList<int> FeatureObject::idList() {
    return mObjects.keys();
}

int FeatureObject::year() {
    return mYear;
}

void FeatureObject::setYear( int year ) {
    mYear = year;
}

int FeatureObject::lowerX() {
    return mLower.first;
}

int FeatureObject::lowerY() {
    return mLower.second;
}

void FeatureObject::setLower( int first , int second ) {
    mLower = qMakePair( first, second );
}

int FeatureObject::upperX() {
    return mUpper.first;
}

int FeatureObject::upperY() {
    return mUpper.second;
}

void FeatureObject::setUpper( int first, int second ) {
    mUpper = qMakePair( first, second );
}

QString FeatureObject::referenceSquare() {
    return mReferenceSquare;
}

void FeatureObject::setReferenceSquare( QString name ) {
    mReferenceSquare = name;
}

QString FeatureObject::quarter() {
    return mQuarter;
}

void FeatureObject::setQuarter( QString name ) {
    mQuarter = name;
}

QSharedPointer<GMLObject> FeatureObject::object(int id) {
    return mObjects.value(id);
}

void FeatureObject::setObject(int id, QSharedPointer<GMLObject> object) {
    mObjects.insert(id, object);
}

GML_END_NAMESPACE
