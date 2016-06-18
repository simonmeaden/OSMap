#ifndef ROAD_H
#define ROAD_H

#include <QObject>
#include <QString>
#include <QStringList>

#include "gmlobject.h"

class Road : public GMLObject {
    Q_OBJECT
  public:
    enum Type {
        A_ROAD,
        B_ROAD,
        LOCAL_STREET,
        MINOR_ROAD,
        MOTORWAY,
        PEDESTRIANISED_STREET,
        PRIMARY_ROAD,
        PRIVATE_ROAD_PUBLICALLY_ACCESSIBLE,
        A_ROAD_COLLAPSED_DUAL_CARRIAGEWAY,
        B_ROAD_COLLAPSED_DUAL_CARRIAGEWAY,
        MINOR_ROAD_COLLAPSED_DUAL_CARRIAGEWAY,
        MOTORWAY_COLLAPSED_DUAL_CARRIAGEWAY,
        PRIMARY_ROAD_COLLAPSED_DUAL_CARRIAGEWAY,
    };

    explicit Road( QString id, QObject *parent = 0 );

  signals:

  public:
    Type toType( QString type ) ;
    QString toString( Type type );

    void setDistinctiveName(QString name);
    QString distinctiveName();
    void setRoadNumber(QString number);
    QString roadNumber();

  protected:
    QStringList names;
    QString mDistinctiveName;
    QString mRoadNumber;

    void initNames();

};


#endif // ROAD_H
