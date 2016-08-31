#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "sql.h"
#include "osdb.h"

OSDB_USE_NAMESPACE
GML_USE_NAMESPACE

MainWindow::MainWindow( QWidget *parent ) :
    QMainWindow( parent ),
    ui( new Ui::MainWindow ) {

    ui->setupUi( this );

    pDatabase = QSharedPointer<OsDatabase>( new OsDatabase() );
    pDatabase->open();

    pReader.reset( new GMLReader( pDatabase ) );

    pObjectStore.reset( new ObjectStore() );
    ui->pDisplayFrame->setObjectStore( pObjectStore );

    connect( ui->importGMLFileAction, &QAction::triggered, this, &MainWindow::importGMLReferenceSquare );
    connect( ui->importTerrain50GMLFile, &QAction::triggered, this, &MainWindow::importGMLTerrain50 );

}

MainWindow::~MainWindow() {
    pDatabase->close();

    delete ui;
}


void MainWindow::importGMLReferenceSquare() {
    QStringList fileNames = QFileDialog::getOpenFileNames(
                                this,
                                "Select one or more files to open",
                                ".",
                                "GML Files (*.gml)" );

    if ( fileNames.isEmpty() ) {
        return;
    }

    pReader->readOSGml( fileNames );
}

void MainWindow::importGMLTerrain50() {
    QStringList fileNames = QFileDialog::getOpenFileNames(
                                this,
                                "Select one or more files to open",
                                "./terrain50",
                                "GML Files (*.gml)" );

    if ( fileNames.isEmpty() ) {
        return;
    }

    pReader->readOSTerrain50GML( fileNames );
}
