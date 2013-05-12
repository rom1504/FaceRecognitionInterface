#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStringListModel>
#include "modele/modelevaliderphotos.h"
#include "modele/modeleafficherpersonne.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mAfficherOuValider(true)
{
    showMaximized();
    ui->setupUi(this);
    ui->horizontalLayout->setStretch(1,1);
    ui->horizontalLayout->setStretch(2,1);
    ui->validerPhotos->hide();
    ui->afficherPhotos->hide();

    connect(ui->actionAfficher_photos,&QAction::triggered,[this](){
        ui->validerPhotos->hide();
        emit afficherPhotos();
    });
    connect(ui->actionVerifier_reconnaissance,&QAction::triggered,[this](){
        ui->afficherPhotos->hide();
        emit verifierReconnaissance();
    });

    connect(ui->afficherPersonnes,&AfficherPersonnes::afficherPersonne,[this](QString personne){
        if(mAfficherOuValider)
        {
            ui->afficherPhotos->show();
            emit afficherPersonne(personne);
        }
        else
        {
            ui->validerPhotos->show();
            emit validerPersonne(personne);
        }
    });

    connect(ui->validerPhotos,&ValiderPhotos::valider,this,&MainWindow::validerPhotos);
}

void MainWindow::setModelAfficherPersonne(ModeleAfficherPersonne * modeleAfficherPersonne,bool afficherOuValider)
{
    mAfficherOuValider=afficherOuValider;
    ui->afficherPersonnes->setModel(modeleAfficherPersonne);
}

void MainWindow::setModelValiderPhotos(ModeleValiderPhotos * modeleValiderPhotos)
{
    ui->validerPhotos->setModel(modeleValiderPhotos);
}

void MainWindow::setModelAfficherPhotos(ModeleAfficherPhotos *modeleAfficherPhotos)
{
    ui->afficherPhotos->setModel(modeleAfficherPhotos);
}


MainWindow::~MainWindow()
{
    delete ui;
}
