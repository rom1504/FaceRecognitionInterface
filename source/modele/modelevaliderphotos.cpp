#include "modelevaliderphotos.h"
#include <iostream>

ModeleValiderPhotos::ModeleValiderPhotos(QList<Photo*> photos,QObject *parent) :
    QAbstractListModel(parent),mPhotos(photos)
{
    for(int i=0;i<mPhotos.size();i++) mValides<<true;
}

QVariant ModeleValiderPhotos::data ( const QModelIndex & index, int role) const
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
     else if(role == Qt::CheckStateRole)
     {
         return mValides[index.row()] ? Qt::Checked : Qt::Unchecked;
     }
     else return QVariant();
}

bool ModeleValiderPhotos::setData ( const QModelIndex & index, const QVariant & value, int role)
{
    if (index.isValid() && role == Qt::CheckStateRole)
    {
         if(index.column()!=0) return false;
         else
         {
             mValides[index.row()]=(value.toInt()==Qt::Checked);
             return true;
         }
    }
    return false;
}

Qt::ItemFlags ModeleValiderPhotos::flags ( const QModelIndex & index ) const
{
    return index.column()==0 ? Qt::ItemIsEnabled|Qt::ItemIsUserCheckable : Qt::ItemIsEnabled;
}

int ModeleValiderPhotos::rowCount (const QModelIndex &) const
{
    return mPhotos.size();
}

QList<bool> ModeleValiderPhotos::valides() const
{
    return mValides;
}