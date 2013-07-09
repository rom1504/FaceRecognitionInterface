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
    ui->stackedWidget->addWidget(mIdentificationsNonValideesViewer);
    mIdentificationsDeViewer=new PersonneMapViewer<Identification*,AfficherIdentifications,IdentificationSignalListAdapter>();
    ui->stackedWidget->addWidget(mIdentificationsDeViewer);
    mPhotosDeViewer=new PersonneMapViewer<Photo*,AfficherPhotos,PhotoSignalListAdapter>();
    ui->stackedWidget->addWidget(mPhotosDeViewer);


    connect(ui->actionAfficher_les_identifications_non_reconnues,&QAction::triggered,[this](){ui->stackedWidget->setCurrentIndex(0);});
    connect(ui->actionAfficher_les_identifications_non_validees,&QAction::triggered,[this](){ui->stackedWidget->setCurrentIndex(1);});
    connect(ui->actionAfficher_les_identifications_validees,&QAction::triggered,[this](){ui->stackedWidget->setCurrentIndex(2);});
    connect(ui->actionAfficher_les_photos_validees,&QAction::triggered,[this](){ui->stackedWidget->setCurrentIndex(3);});
    ui->stackedWidget->hide();
    connect(ui->actionDetecter_les_visages,&QAction::triggered,[this]{
        mProcessDialog=new QProgressDialog("Détection en cours...",QString(), 0, 4, this);
        mProcessDialog->setWindowModality(Qt::WindowModal);
        mProcessDialog->setValue(1);
        QProcess *myProcess = new QProcess();
        myProcess->start("bash facedetect/source/chaineSimplifie.sh donnees/photos donnees/photosDecoupees donnees/informations");
        mProcessDialog->setValue(2);
        connect(myProcess,SIGNAL(finished(int)),this,SLOT(finir(int)));
    });
}

void MainWindow::run()
{
    QTimer::singleShot(200, ui->stackedWidget, SLOT(show()));
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
    // 1) clear
    // 2) charger
    mProcessDialog->setValue(3);
    emit reloadPhotos();
    mProcessDialog->setValue(4);
    QMessageBox::information(this,"Détection terminé","La détection de visage est terminée");
}

MainWindow::~MainWindow()
{
    delete ui;
}
