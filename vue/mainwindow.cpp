#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStringListModel>
#include "modele/modeleafficherphotos.h"
#include "modele/modeleafficherpersonne.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    showMaximized();
    ui->setupUi(this);
    ui->listViewPhoto->hide();
    ui->pushButtonPrecedent->hide();
    ui->pushButtonValider->hide();

    connect(ui->pushButtonPrecedent,&QPushButton::clicked,this,&MainWindow::precedent);

    connect(ui->pushButtonChoisirPersonne,&QPushButton::clicked,[this](){
        ui->listViewPersonne->hide();
        ui->pushButtonChoisirPersonne->hide();
        ui->pushButtonPrecedent->show();
        ui->pushButtonValider->show();
        ui->listViewPhoto->show();
        mPersonne=ui->listViewPersonne->model()->data(ui->listViewPersonne->selectionModel()->currentIndex()).toString();
        setModelPremieresPhotos();

    });

    connect(ui->pushButtonValider,&QPushButton::clicked,[this](){
        QList<bool> valides=mModeleAfficherPhotos->valides();
        if(mPhotos->valider(mPersonne,valides)) precedent();
        else setModelPremieresPhotos();
    });

}

void MainWindow::precedent()
{
    ui->listViewPhoto->hide();
    ui->pushButtonPrecedent->hide();
    ui->pushButtonValider->hide();
    ui->listViewPersonne->show();
    ui->pushButtonChoisirPersonne->show();
}

void MainWindow::setModelPremieresPhotos()
{
    QList<Photo*> premieresPhotos=mPhotos->premieresPhotosDe(mPersonne);
    mModeleAfficherPhotos=new ModeleAfficherPhotos(premieresPhotos);
    ui->listViewPhoto->setModel(mModeleAfficherPhotos);
}



void MainWindow::setModel(Photos * photos)
{
    mPhotos=photos;
    ui->listViewPersonne->setModel(new ModeleAfficherPersonne(photos));
}

MainWindow::~MainWindow()
{
    delete ui;
}
