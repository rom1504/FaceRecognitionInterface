#include "qstringsignallistadapter.h"

SignalListAdapter<QString>::SignalListAdapter(SignalList<QString> *list, QObject *parent) :
    SignalListAdapterBase(list,parent)
{
}

QVariant SignalListAdapter<QString>::data ( const QModelIndex & index, int role ) const
{
    if (!index.isValid())
         return QVariant();

     if (index.row() >= mList->nombre())
         return QVariant();

     if(role == Qt::DisplayRole || role == Qt::EditRole) return mList->get(index.row());
     else return QVariant();
}
