#include "photoview.h"
#include "ui_photoview.h"
#include "modele/photo.h"
#include "adapteur/photosignallistadapter.h"

PhotoView::PhotoView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PhotoView)
{
    mAdapter=nullptr;
    ui->setupUi(this);
}


void PhotoView::setModel(QAbstractItemModel * adapter)
{
    mAdapter=adapter;
    connect(ui->previousPushButton,&QPushButton::clicked,[this](){viewPhoto(mCurrent-1);});
    connect(ui->nextPushButton,&QPushButton::clicked,[this](){viewPhoto(mCurrent+1);});
    connect(ui->upPushButton,&QPushButton::clicked,[this](){emit up();});
}

void PhotoView::viewPhoto(int num)
{
    if(mAdapter==nullptr || num>=mAdapter->rowCount() || num<0) return;
    Photo * photo=mAdapter->data(mAdapter->index(num,0),FullItemRole).value<Photo*>();
    ui->photoLabel->setPhoto(photo);
    mCurrent=num;
    QStringList l;
    for(auto identification : photo->identifications()) if(identification->valide() && !identification->ignore()) l<<identification->personne();
    ui->personsLabel->setText("Sur cette photo : "+l.join(", "));
}

PhotoView::~PhotoView()
{
    delete ui;
}
