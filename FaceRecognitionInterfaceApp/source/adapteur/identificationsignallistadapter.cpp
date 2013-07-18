#include <QDebug>

#include "identificationsignallistadapter.h"

CachePhotos SignalListAdapter<Identification*>::mCachePhotos;

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

    if(role == Qt::DecorationRole)
    {
        QPixmap image=mCachePhotos.getPhoto(mList->get(index.row())->nomFichierDecoupee());
        if(!image.isNull()) image=image.scaledToWidth(200);
        return image;
    }
    if (role == Qt::EditRole) return QVariant::fromValue(mList->get(index.row()));
    return QVariant();
}

Qt::ItemFlags SignalListAdapter<Identification*>::flags(const QModelIndex & index) const
{
    Identification * identification=mList->get(index.row());
    return identification->valide() && identification->identifie() ?  Qt::ItemIsEnabled|Qt::ItemIsSelectable : Qt::ItemIsEnabled|Qt::ItemIsSelectable|Qt::ItemIsEditable;
}
