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
    QPixmap p;
    CachePhotos::getPhoto(mAdapter->data(mAdapter->index(num,0),FullItemRole).value<Photo*>()->nomFichier()+"_decent",p);
    ui->photoLabel->setPixmap(p);
    mCurrent=num;
}

PhotoView::~PhotoView()
{
    delete ui;
}
