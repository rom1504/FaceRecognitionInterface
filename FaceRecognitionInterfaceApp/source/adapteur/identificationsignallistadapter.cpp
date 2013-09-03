#include <QDebug>
#include <QBrush>

#include "identificationsignallistadapter.h"


SignalListAdapter<Identification*>::SignalListAdapter(SignalList<Identification *> *list, QObject *parent) :
    SignalListAdapterBase(list,parent)
{
}

QVariant SignalListAdapter<Identification*>::data ( const QModelIndex & index, int role ) const
{
    if (!index.isValid())
     return QVariant();

    if (index.row() >= mList->nombre())
       return QVariant();

    if(role==FullItemRole) return QVariant::fromValue(mList->get(index.row()));
    if(role == Qt::DecorationRole)
    {
        QPixmap image;
        CachePhotos::getPhoto(mList->get(index.row())->nomFichierDecoupee()+"_thumb",image);
//        return QBrush(image);
//        return QVariant();
        return image;
    }
//    if(role == Qt::SizeHintRole)
//    {
//        return QSize(200,200);
//    }
//    if(role == Qt::DisplayRole)
//    {
//        return "salut !";
//    }
    if (role == Qt::EditRole) return QVariant::fromValue(mList->get(index.row()));
    return QVariant();
}

Qt::ItemFlags SignalListAdapter<Identification*>::flags(const QModelIndex & index) const
{
    Identification * identification=mList->get(index.row());
    return identification->valide() && identification->identifie() ?  Qt::ItemIsEnabled|Qt::ItemIsSelectable : Qt::ItemIsEnabled|Qt::ItemIsSelectable|Qt::ItemIsEditable;
}
