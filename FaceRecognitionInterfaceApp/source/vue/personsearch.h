#ifndef PERSONSEARCH_H
#define PERSONSEARCH_H

#include <QDialog>

#include "adapter/qstringsignallistadapter.h"
#include "adapteur/checkablestringsignallistadapter.h"

namespace Ui {
class PersonSearch;
}

class PersonSearch : public QDialog
{
    Q_OBJECT
    
public:
    explicit PersonSearch(QWidget *parent = 0);
    ~PersonSearch();

    static QStringList * get();

public:
    static SignalList<QString> * mPersonnes;


private:
    QStringList * getPersons();

private:
    Ui::PersonSearch *ui;
    CheckableStringSignalListAdapter * mPersonAdapter;
};

#endif // PERSONSEARCH_H
