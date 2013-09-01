#include "personsearch.h"
#include "ui_personsearch.h"

SignalList<QString> * PersonSearch::mPersonnes;

PersonSearch::PersonSearch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PersonSearch)
{
    ui->setupUi(this);
    mPersonAdapter=new CheckableStringSignalListAdapter(PersonSearch::mPersonnes);
    ui->listView->setModel(mPersonAdapter);
}

PersonSearch::~PersonSearch()
{
    delete ui;
}

QStringList * PersonSearch::get()
{
    PersonSearch * personSearch=new PersonSearch();
    if(personSearch->exec() == QDialog::Accepted) return personSearch->getPersons();
    return nullptr;
}

QStringList * PersonSearch::getPersons()
{
    QMap<QString,bool> checkList=mPersonAdapter->checkList();
    QStringList * persons=new QStringList();
    for(auto s : checkList.keys()) if(checkList[s]) persons->append(s);
    return persons;
}
