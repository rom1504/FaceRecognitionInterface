#include <QDebug>

#include "identificationsignallistadapter.h"

CachePhotos IdentificationSignalListAdapter::mCachePhotos;

IdentificationSignalListAdapter::IdentificationSignalListAdapter(SignalList<Identification *> *list, QObject *parent) :
    SignalListAdapter(list,parent)
{
}

QVariant IdentificationSignalListAdapter::data ( const QModelIndex & index, int role ) const
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
    else return QVariant();
}
