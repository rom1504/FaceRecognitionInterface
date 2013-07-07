#include "photosignallistadapter.h"

CachePhotos PhotoSignalListAdapter::mCachePhotos;

PhotoSignalListAdapter::PhotoSignalListAdapter(SignalList<Photo *> *list, QObject *parent) :
    SignalListAdapter(list,parent)
{
}

QVariant PhotoSignalListAdapter::data ( const QModelIndex & index, int role ) const
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
