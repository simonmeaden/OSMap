#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QMainWindow>
#include <QFileDialog>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSharedPointer>
#include <QScopedPointer>

#include "osdb.h"
#include "gmlreader.h"
#include "objectstore.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
        Q_OBJECT
    public:
        explicit MainWindow( QWidget *parent = 0 );
        ~MainWindow();
    
protected:
    QSharedPointer<OsDatabase> pDatabase;
    QScopedPointer<GMLReader> pReader;
    QSharedPointer<ObjectStore> pObjectStore;

    void importGMLReferenceSquare();
    void importGMLTerrain50();

    private:
        Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
