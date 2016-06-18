#ifndef GMLPOSLIST_H
#define GMLPOSLIST_H

#include <QObject>
#include <QList>
#include <QPair>

class GMLPosList : public QObject {
    Q_OBJECT
  public:
    explicit GMLPosList( QObject *parent = 0 );

  signals:

  public:
    void addPosition(QString x, QString y);
    void addPosition(int x, int y);
    void addPosition(QPair<int, int> position);
    void addPositions(QList<int> list);
    void addPositions(QList<QPair<int, int> >);
    void clear();

protected:
    QList<QPair<int, int> > mPositions;
};

#endif // GMLPOSLIST_H
