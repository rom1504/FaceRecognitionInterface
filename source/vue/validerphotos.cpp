#include "validerphotos.h"
#include "ui_validerphotos.h"

ValiderPhotos::ValiderPhotos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ValiderPhotos)
{
    ui->setupUi(this);

    connect(ui->pushButtonValider,&QPushButton::clicked,[this](){emit valider(mModeleValiderPhotos->valides());});
}

ValiderPhotos::~ValiderPhotos()
{
    delete ui;
}

void ValiderPhotos::setModel(ModeleValiderPhotos *modeleValiderPhotos)
{
    mModeleValiderPhotos=modeleValiderPhotos;
    ui->listViewPhoto->setModel(modeleValiderPhotos);
}
