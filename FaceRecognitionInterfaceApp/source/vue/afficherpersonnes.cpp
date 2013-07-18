#include "afficherpersonnes.h"
#include "ui_afficherpersonnes.h"

#include <QTimer>
#include <QDebug>

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


void AfficherPersonnes::setModel(SignalListAdapter<QString> *qstringSignalListAdapter)
{
    ui->listViewPersonne->setModel(qstringSignalListAdapter);
    connect(ui->listViewPersonne->selectionModel(),&QItemSelectionModel::currentChanged,[this](const QModelIndex &,const QModelIndex &){afficherPersonneCourante();});
}

void AfficherPersonnes::afficherPersonneCourante()
{
    emit afficherPersonne(ui->listViewPersonne->model()->data(ui->listViewPersonne->selectionModel()->currentIndex()).toString());
}
