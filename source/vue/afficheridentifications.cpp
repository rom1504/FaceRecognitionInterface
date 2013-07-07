#include "afficheridentifications.h"
#include "ui_afficheridentifications.h"

AfficherIdentifications::AfficherIdentifications(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AfficherIdentifications)
{
    ui->setupUi(this);
    ui->listView->setViewMode(QListView::IconMode);
}


void AfficherIdentifications::setModel(IdentificationSignalListAdapter * adapter)
{
    ui->listView->setModel(adapter);
}

AfficherIdentifications::~AfficherIdentifications()
{
    delete ui;
}
