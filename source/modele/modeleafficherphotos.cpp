#include "modeleafficherphotos.h"

ModeleAfficherPhotos::ModeleAfficherPhotos(QList<Photo*> photos,QObject *parent) :
    QAbstractListModel(parent),mPhotos(photos)
{
}

QVariant ModeleAfficherPhotos::data ( const QModelIndex & index, int role) const
{
    if (!index.isValid())
         return QVariant();

     if (index.row() >= mPhotos.size())
         return QVariant();

     if(role == Qt::DecorationRole)
     {
        QPixmap image=mPhotos[index.row()]->image();
        if(!image.isNull()) image=image.scaledToWidth(200);
        return image;
     }
     else return QVariant();
}

int ModeleAfficherPhotos::rowCount (const QModelIndex &) const
{
    return mPhotos.size();
}
