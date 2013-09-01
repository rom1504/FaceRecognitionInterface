#include "afficherphotos.h"
#include "ui_afficherphotos.h"

AfficherPhotos::AfficherPhotos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AfficherPhotos)
{
    ui->setupUi(this);
}


void AfficherPhotos::setModel(QAbstractItemModel *adapter)
{
    ui->listView->setModel(adapter);
}

AfficherPhotos::~AfficherPhotos()
{
    delete ui;
}
