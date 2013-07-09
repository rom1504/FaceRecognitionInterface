#ifndef SIGNALLISTADAPTER_HXX
#define SIGNALLISTADAPTER_HXX

#include "signallistadapter.h"

template <class T> SignalListAdapter<T>::SignalListAdapter(SignalList<T> *list, QObject *parent) : QAbstractListModel(parent),mList(list)
{
    connect(mList,&SignalListBase::debutAjout,[this](int numero){beginInsertRows(QModelIndex(),numero,numero);});
    connect(mList,&SignalListBase::finAjout,[this](int){endInsertRows();});// je pourrais supprimer le int de SignalListBase::finAjout
    connect(mList,&SignalListBase::debutSupression,[this](int numero){beginRemoveRows(QModelIndex(),numero,numero);});
    connect(mList,&SignalListBase::finSupression,[this](int){endRemoveRows();});
    connect(mList,&SignalListBase::beginReset,[this](){beginResetModel();});
    connect(mList,&SignalListBase::endReset,[this](){endResetModel();});
}

template <class T> int SignalListAdapter<T>::rowCount (const QModelIndex &) const
{
    if(mList==nullptr) return 0;
    return mList->nombre();
}

#endif // SIGNALLISTADAPTER_HXX
