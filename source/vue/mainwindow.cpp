#include <QStringListModel>
#include <QProcess>
#include <QMessageBox>
#include <QTimer>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vue/personnemapviewer.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mAfficherOuValider(true)
{
    showMaximized();
    ui->setupUi(this);
    mIdentificationsNonValideesViewer=new PersonneMapViewer<Identification*,AfficherIdentifications,IdentificationSignalListAdapter>();
    ui->horizontalLayout->addWidget(mIdentificationsNonValideesViewer);
    mIdentificationsDeViewer=new PersonneMapViewer<Identification*,AfficherIdentifications,IdentificationSignalListAdapter>();
    ui->horizontalLayout->addWidget(mIdentificationsDeViewer);
    mPhotosDeViewer=new PersonneMapViewer<Photo*,AfficherPhotos,PhotoSignalListAdapter>();
    ui->horizontalLayout->addWidget(mPhotosDeViewer);


    connect(ui->actionAfficher_les_identifications_non_reconnues,&QAction::triggered,[this](){
        mIdentificationsDeViewer->hide();
        mPhotosDeViewer->hide();
        mIdentificationsNonValideesViewer->hide();
        ui->personneNonReconnuesViewer->show();
    });

    connect(ui->actionAfficher_les_identifications_non_validees,&QAction::triggered,[this](){
        mIdentificationsDeViewer->hide();
        mPhotosDeViewer->hide();
        ui->personneNonReconnuesViewer->hide();
        mIdentificationsNonValideesViewer->show();
    });

    connect(ui->actionAfficher_les_identifications_validees,&QAction::triggered,[this](){
        ui->personneNonReconnuesViewer->hide();
        mIdentificationsNonValideesViewer->hide();
        mPhotosDeViewer->hide();
        mIdentificationsDeViewer->show();
    });

    connect(ui->actionAfficher_les_photos_validees,&QAction::triggered,[this](){
        ui->personneNonReconnuesViewer->hide();
        mIdentificationsNonValideesViewer->hide();
        mIdentificationsDeViewer->hide();
        mPhotosDeViewer->show();
    });

    ui->personneNonReconnuesViewer->hide();
    mIdentificationsNonValideesViewer->hide();
    mIdentificationsDeViewer->hide();
    mPhotosDeViewer->hide();

    connect(ui->actionDetecter_les_visages,&QAction::triggered,[this]{
        QProcess *myProcess = new QProcess();
        myProcess->start("bash facedetect/source/chaineSimplifie.sh donnees/photos donnees/photosDecoupees donnees/informations");
        connect(myProcess,SIGNAL(finished(int)),this,SLOT(finir(int)));
    });
}

void MainWindow::run()
{
    QTimer::singleShot(200, ui->personneNonReconnuesViewer, SLOT(show()));
    show();
}


void MainWindow::setAdapterIdentificationNonValidees(PersonneMap<Identification*> * adapter)
{
    mIdentificationsNonValideesViewer->setModel(adapter);
}

void MainWindow::setAdapterIdentificationNonReconnues(IdentificationSignalListAdapter * adapter)
{
    ui->personneNonReconnuesViewer->setModel(adapter);
}


void MainWindow::setAdapterPhotoDe(PersonneMap<Photo*> * adapter)
{
    mPhotosDeViewer->setModel(adapter);
}

void MainWindow::setAdapterIdentificationDe(PersonneMap<Identification*> * adapter)
{
    mIdentificationsDeViewer->setModel(adapter);
}

void MainWindow::finir(int)
{
    // maj les infos ici.
    QMessageBox::information(this,"Détection terminé","La détection de visage est terminée");
}

MainWindow::~MainWindow()
{
    delete ui;
}
