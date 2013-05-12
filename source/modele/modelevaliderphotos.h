#ifndef MODELEVALIDERPHOTOS_H
#define MODELEVALIDERPHOTOS_H

#include <QAbstractListModel>
#include "modele/photo.h"

class ModeleValiderPhotos : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit ModeleValiderPhotos(QList<Photo*> photos,QObject *parent = 0);
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

#endif // MODELEVALIDERPHOTOS_H
