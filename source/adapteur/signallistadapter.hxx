#ifndef SIGNALLISTADAPTER_HXX
#define SIGNALLISTADAPTER_HXX

#include "signallistadapter.h"

template <class T> SignalListAdapter<T>::SignalListAdapter(SignalList<T> *list, QObject *parent) : QAbstractListModel(parent),mList(list)
{
    connect(mList,&SignalListBase::debutAjout,[this](int numero){emit beginInsertRows(QModelIndex(),numero,numero);});
    connect(mList,&SignalListBase::finAjout,[this](int){emit endInsertRows();});// je pourrais supprimer le int de SignalListBase::finAjout
    connect(mList,&SignalListBase::debutSupression,[this](int numero){emit beginRemoveRows(QModelIndex(),numero,numero);});
    connect(mList,&SignalListBase::finSupression,[this](int){emit endRemoveRows();});
}

template <class T> int SignalListAdapter<T>::rowCount (const QModelIndex &) const
{
    if(mList==nullptr) return 0;
    return mList->nombre();
}

#endif // SIGNALLISTADAPTER_HXX
