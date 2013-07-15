#include <QStringListModel>
#include <QProcess>
#include <QMessageBox>
#include <QTimer>
#include <QDebug>
#include <QDir>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vue/personnemapviewer.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
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
    connect(ui->actionDetecter_les_visages,&QAction::triggered,this,&MainWindow::detect);
    connect(ui->actionReconnaissance_automatique,&QAction::triggered,this,&MainWindow::recognize);
}

void MainWindow::detect()
{
    QDir dir("donnees/photos");
    int photoFilesNumber=dir.entryList().count()-2;
    dir.cd("../informations");
    int informationsFilesNumber=dir.entryList().count()-2;
    int remaining=photoFilesNumber-informationsFilesNumber;
    Q_ASSERT(remaining>=0);
    QProgressDialog * processDialog=new QProgressDialog("Détection en cours...",QString(), 0, int(double(remaining)*1.5), this);
    processDialog->setWindowModality(Qt::WindowModal);
    processDialog->setMinimumDuration(0);
    processDialog->setValue(1);
    processDialog->setValue(2);
    QProcess *process = new QProcess();
    double *avancement=new double(processDialog->value());
    int *num=new int(0);
    connect(process,&QProcess::readyReadStandardOutput,[processDialog,num,remaining,avancement,process,this](){
        // voir pour faire péter la compilation de la chaine : ce serait plutôt une étape d'installation
        if(processDialog->value()>=processDialog->maximum()-1) processDialog->setMaximum(int(double(processDialog->maximum())*1.2));
        (*num)++;
        (*avancement)+=(*num)>remaining ? 0.2 : 1.0;
        processDialog->setValue(int(*avancement));
        // améliorable en lisant le début du découpage et en divisant le progrés par 2 ou qq chose comme ça
        process->readAllStandardOutput();
        // faire une estimation initiale via fileNumber*2 puis une fois qu'on a récupéré les infos ajuster via setMaximum : non inutile, je crois que ce qui prends du temps c'est la première partie, on peut considérer qu'il reste fileNumber/10 étape ensuite, qu'on peut remplir d'un coup
    });
    process->start("bash facedetect/source/chaineSimplifie.sh donnees/photos donnees/photosDecoupees donnees/informations");
    void (QProcess:: *f)(int) = &QProcess::finished;
    connect(process,f,[this,processDialog](int){
        emit reloadPhotos();
        processDialog->setValue(processDialog->maximum());
        QMessageBox::information(this,"Détection terminé","La détection de visage est terminée");// indiquer des infos (nombre de photo dont on va vraiment fait la détection, sur combien, combien de temps pris,...)
    });
}

void MainWindow::recognize()
{
    QProgressDialog * processDialog=new QProgressDialog("Reconnaissance en cours...",QString(), 0, 6, this);
    processDialog->setWindowModality(Qt::WindowModal);
    processDialog->setMinimumDuration(0);
    processDialog->setValue(1);
    QProcess *process = new QProcess();
    connect(process,&QProcess::readyReadStandardOutput,[processDialog,process](){
        processDialog->setValue(processDialog->value()+1);
        process->readAllStandardOutput();
    });
    process->start("bash facerecognition/source/chaineSimplifie.sh donnees/informations donnees/photosDecoupees donnees/modele donnees/intermediaire");
    void (QProcess:: *f)(int) = &QProcess::finished;
    connect(process,f,[this,processDialog](int){
        emit reloadPhotos();
        processDialog->setValue(processDialog->maximum());
        QMessageBox::information(this,"Reconnaissance terminé","La reconnaissance de visage est terminée");
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

MainWindow::~MainWindow()
{
    delete ui;
}
