#include "afficherphotos.h"
#include "ui_afficherphotos.h"

AfficherPhotos::AfficherPhotos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AfficherPhotos)
{
    ui->setupUi(this);
    mListView=new QListView();
    mListView->setViewMode(QListView::IconMode);

    mPhotoView=new PhotoView();

    ui->stackedWidget->addWidget(mListView);
    ui->stackedWidget->addWidget(mPhotoView);
}


void AfficherPhotos::setModel(QAbstractItemModel *adapter)
{
    ui->stackedWidget->setCurrentIndex(0);
    mListView->setModel(adapter);
    mPhotoView->setModel(adapter);
    connect(mListView,&QListView::clicked,[this](QModelIndex index){
        ui->stackedWidget->setCurrentIndex(1);
        mPhotoView->viewPhoto(index.row());
    });
    connect(mPhotoView,&PhotoView::up,[this](){ui->stackedWidget->setCurrentIndex(0);});
}

AfficherPhotos::~AfficherPhotos()
{
    delete ui;
}
