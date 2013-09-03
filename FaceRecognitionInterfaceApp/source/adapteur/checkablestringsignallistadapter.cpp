#include "checkablestringsignallistadapter.h"

CheckableStringSignalListAdapter::CheckableStringSignalListAdapter(SignalList<QString> * list,QObject *parent) :
    SignalListAdapter<QString>(list,parent)
{

}

QVariant CheckableStringSignalListAdapter::data ( const QModelIndex & index, int role ) const
{
    if (!index.isValid())
         return QVariant();

     if (index.row() >= mList->nombre())
         return QVariant();

     if(role==FullItemRole) return QVariant::fromValue(mList->get(index.row()));
     if(role == Qt::DisplayRole) return mList->get(index.row());
     if(role == Qt::CheckStateRole ) return mCheckList.contains(mList->get(index.row())) && mCheckList[mList->get(index.row())] ? Qt::Checked : Qt::Unchecked;
     else return QVariant();
}

bool CheckableStringSignalListAdapter::setData(const QModelIndex & index, const QVariant & value, int role)
{
    if (!index.isValid() || role != Qt::CheckStateRole) return false;
    mCheckList[mList->get(index.row())]=value.toInt()==Qt::Checked;
    return true;
}


QMap<QString,bool> CheckableStringSignalListAdapter::checkList() const
{
    return mCheckList;
}

Qt::ItemFlags CheckableStringSignalListAdapter::flags(const QModelIndex &) const
{
    return Qt::ItemIsEnabled|Qt::ItemIsSelectable|Qt::ItemIsUserCheckable;
}
