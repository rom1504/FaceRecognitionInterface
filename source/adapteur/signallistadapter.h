#ifndef SIGNALLISTADAPTER_H
#define SIGNALLISTADAPTER_H

#include <QAbstractListModel>
#include "../modele/signallist.h"

template <class T> class SignalListAdapter : public QAbstractListModel
{
public:
    explicit SignalListAdapter(SignalList<T> * list,QObject *parent = 0);
    int rowCount (const QModelIndex & = QModelIndex()) const;

    
protected:
    SignalList<T> * mList;

};

#include "signallistadapter.hxx"

#endif // SIGNALLISTADAPTER_H
