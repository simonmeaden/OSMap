#ifndef GMLOBJECT_H
#define GMLOBJECT_H

#include <QObject>
#include <QString>

class GMLObject : public QObject
{
public:
    GMLObject(QString id, QObject * parent = 0);

protected:
    QString mId;
};

#endif // GMLOBJECT_H
