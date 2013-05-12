#include "afficherphotos.h"
#include "ui_afficherphotos.h"

AfficherPhotos::AfficherPhotos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AfficherPhotos)
{
    ui->setupUi(this);

}

AfficherPhotos::~AfficherPhotos()
{
    delete ui;
}

void AfficherPhotos::setModel(ModeleAfficherPhotos * modeleValiderPhotos)
{
    ui->listViewPhoto->setModel(modeleValiderPhotos);
}
