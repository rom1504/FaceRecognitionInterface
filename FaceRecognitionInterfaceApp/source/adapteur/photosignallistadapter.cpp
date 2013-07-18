#include "photosignallistadapter.h"

CachePhotos SignalListAdapter<Photo*>::mCachePhotos;

SignalListAdapter<Photo*>::SignalListAdapter(SignalList<Photo *> *list, QObject *parent) :
    SignalListAdapterBase(list,parent)
{
}

QVariant SignalListAdapter<Photo*>::data ( const QModelIndex & index, int role ) const
{
    if (!index.isValid())
     return QVariant();

    if (index.row() >= mList->nombre())
       return QVariant();

    if(role == Qt::DecorationRole)
    {
        QPixmap image=mCachePhotos.getPhoto(mList->get(index.row())->nomFichier());
        if(!image.isNull()) image=image.scaledToWidth(200);
        return image;
    }
    else return QVariant();
}
