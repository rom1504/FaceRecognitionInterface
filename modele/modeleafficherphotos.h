#ifndef MODELEAFFICHERPHOTOS_H
#define MODELEAFFICHERPHOTOS_H

#include <QAbstractListModel>
#include "modele/photo.h"

class ModeleAfficherPhotos : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit ModeleAfficherPhotos(QList<Photo*> photos,QObject *parent = 0);
    QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;
    int rowCount (const QModelIndex & = QModelIndex()) const;
    bool setData ( const QModelIndex & index, const QVariant & value, int role = Qt::EditRole ) ;
    Qt::ItemFlags flags ( const QModelIndex & index ) const;
    QList<bool> valides() const;
    
signals:
    
private:
    QList<Photo*> mPhotos;
    QList<bool> mValides;
    
};

#endif // MODELEAFFICHERPHOTOS_H
