#include <QItemDelegate>
#include <QItemEditorFactory>

#include "afficheridentifications.h"
#include "ui_afficheridentifications.h"
#include "modele/identification.h"
#include "vue/identificationeditor.h"

AfficherIdentifications::AfficherIdentifications(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AfficherIdentifications)
{
    ui->setupUi(this);
    ui->listView->setViewMode(QListView::IconMode);

    QItemEditorFactory * factory=new QItemEditorFactory();
    factory->registerEditor((QVariant::Type)qMetaTypeId<Identification*>(), new QStandardItemEditorCreator<IdentificationEditor>());
    QItemDelegate * delegate=new QItemDelegate();
    delegate->setItemEditorFactory(factory);
    ui->listView->setItemDelegate(delegate);
}


void AfficherIdentifications::setModel(SignalListAdapter<Identification *> *adapter)
{
    ui->listView->setModel(adapter);
}

AfficherIdentifications::~AfficherIdentifications()
{
    delete ui;
}
