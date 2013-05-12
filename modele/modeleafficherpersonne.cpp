#include "modeleafficherpersonne.h"

ModeleAfficherPersonne::ModeleAfficherPersonne(Photos * photos,QObject *parent) :
    QAbstractListModel(parent),mPhotos(photos)
{
    connect(mPhotos,&Photos::dataChanged,[this](){
        beginResetModel();
        endResetModel();// utiliser un beginRemoveRows + indexOf ?? (est ce plus efficace ? semble pas sur...)
    });
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
