#include "modeleafficherpersonne.h"
#include <iostream>

ModeleAfficherPersonne::ModeleAfficherPersonne(Photos * photos,QObject *parent) :
    QAbstractListModel(parent),mPhotos(photos)
{
    connect(mPhotos,&Photos::beginRemoveRows,[this](int debut,int fin){beginRemoveRows(QModelIndex(),debut,fin);});
    connect(mPhotos,&Photos::endRemoveRows,this,&ModeleAfficherPersonne::endRemoveRows);
}

QVariant ModeleAfficherPersonne::data ( const QModelIndex & index, int role) const
{
    if (!index.isValid())
         return QVariant();

     if (index.row() >= mPhotos->personnes().size())
         return QVariant();

     if(role == Qt::DisplayRole) return mPhotos->personnes()[index.row()];
     else return QVariant();
}

int ModeleAfficherPersonne::rowCount (const QModelIndex &) const
{
    return mPhotos->personnes().size();
}

