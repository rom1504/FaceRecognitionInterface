#include "photosignallistadapter.h"


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
        QPixmap image;
        CachePhotos::getPhoto(mList->get(index.row())->nomFichier()+"_thumb",image);
        return image;
    }
    else return QVariant();
}
