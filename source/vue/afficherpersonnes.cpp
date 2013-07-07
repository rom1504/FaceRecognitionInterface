#include "afficherpersonnes.h"
#include "ui_afficherpersonnes.h"
#include <iostream>

AfficherPersonnes::AfficherPersonnes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AfficherPersonnes)
{
    ui->setupUi(this);
}

AfficherPersonnes::~AfficherPersonnes()
{
    delete ui;
}


void AfficherPersonnes::setModel(QStringSignalListAdapter *qstringSignalListAdapter)
{
    ui->listViewPersonne->setModel(qstringSignalListAdapter);
    connect(ui->listViewPersonne->selectionModel(),&QItemSelectionModel::currentChanged,[this](const QModelIndex &,const QModelIndex &){emit afficherPersonne(ui->listViewPersonne->model()->data(ui->listViewPersonne->selectionModel()->currentIndex()).toString());});
}
