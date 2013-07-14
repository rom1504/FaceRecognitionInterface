#include "qstringsignallistadapter.h"

QStringSignalListAdapter::QStringSignalListAdapter(SignalList<QString> *list, QObject *parent) :
    SignalListAdapter(list,parent)
{
}

QVariant QStringSignalListAdapter::data ( const QModelIndex & index, int role ) const
{
    if (!index.isValid())
         return QVariant();

     if (index.row() >= mList->nombre())
         return QVariant();

     if(role == Qt::DisplayRole || role == Qt::EditRole) return mList->get(index.row());
     else return QVariant();
}
