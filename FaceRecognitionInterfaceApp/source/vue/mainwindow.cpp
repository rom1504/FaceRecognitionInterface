#include <QStringListModel>
#include <QProcess>
#include <QMessageBox>
#include <QTimer>
#include <QDebug>
#include <QDir>
#include <QPixmapCache>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vue/personnemapviewer.h"
#include "vue/progressdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    showMaximized();
    ui->setupUi(this);
    mIdentificationsNonValideesViewer=new PersonneMapViewer<Identification*,AfficherIdentifications>();
    ui->stackedWidget->addWidget(mIdentificationsNonValideesViewer);
    mIdentificationsDeViewer=new PersonneMapViewer<Identification*,AfficherIdentifications>();
    ui->stackedWidget->addWidget(mIdentificationsDeViewer);
    mPhotosDeViewer=new PersonneMapViewer<Photo*,AfficherPhotos>();
    ui->stackedWidget->addWidget(mPhotosDeViewer);
    QPixmapCache::setCacheLimit(100000);


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
    int informationsFilesNumber;
    if(dir.exists("../informations"))
    {
        dir.cd("../informations");
        informationsFilesNumber=dir.entryList().count()-2;
    }
    else informationsFilesNumber=0;
    int remaining=photoFilesNumber-informationsFilesNumber;
    Q_ASSERT(remaining>=0);
    ProgressDialog * progressDialog=new ProgressDialog("Détection","Détection en cours...",0, int(double(remaining)*1.5),1, this);
    progressDialog->start();
    QProcess *process = new QProcess();
    double *avancement=new double(progressDialog->value());
    int *num=new int(0);
    connect(process,&QProcess::readyReadStandardOutput,[progressDialog,num,remaining,avancement,process,this](){
        // voir pour faire péter la compilation de la chaine : ce serait plutôt une étape d'installation
        if(progressDialog->value()>=progressDialog->maximum()-1) progressDialog->setMaximum(int(double(progressDialog->maximum())*1.2));
        (*num)++;
        (*avancement)+=(*num)>remaining ? 0.2 : 1.0;
        progressDialog->setValue(int(*avancement));
        // améliorable en lisant le début du découpage et en divisant le progrés par 2 ou qq chose comme ça
        process->readAllStandardOutput();
        // faire une estimation initiale via fileNumber*2 puis une fois qu'on a récupéré les infos ajuster via setMaximum : non inutile, je crois que ce qui prends du temps c'est la première partie, on peut considérer qu'il reste fileNumber/10 étape ensuite, qu'on peut remplir d'un coup
    });
    process->start("bash facedetect/source/chaineSimplifie.sh donnees/photos donnees/photosDecoupees donnees/informations");
    void (QProcess:: *f)(int) = &QProcess::finished;
    connect(process,f,[this,progressDialog](int){
        emit reloadPhotos();
        progressDialog->setValue(progressDialog->maximum());
        progressDialog->end();
        QMessageBox::information(this,"Détection terminé","La détection de visage est terminée");// indiquer des infos (nombre de photo dont on va vraiment fait la détection, sur combien, combien de temps pris,...)
    });
}

void MainWindow::recognize()
{
    ProgressDialog * progressDialog=new ProgressDialog("Reconnaissance","Reconnaissance en cours...", 0, 5,0, this);
    progressDialog->start();
    QProcess *process = new QProcess();
    connect(process,&QProcess::readyReadStandardOutput,[progressDialog,process](){
        progressDialog->setValue(progressDialog->value()+1);
        process->readAllStandardOutput();
    });
    process->start("bash facerecognition/source/chaineSimplifie.sh donnees/informations donnees/photosDecoupees donnees/modele donnees/intermediaire");
    void (QProcess:: *f)(int) = &QProcess::finished;
    connect(process,f,[this,progressDialog](int){
        emit reloadPhotos();
        progressDialog->setValue(progressDialog->maximum());
        progressDialog->end();
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

void MainWindow::setAdapterIdentificationNonReconnues(SignalListAdapter<Identification *> *adapter)
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
