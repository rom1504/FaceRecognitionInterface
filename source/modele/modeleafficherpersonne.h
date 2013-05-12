#ifndef MODELEAFFICHERPERSONNE_H
#define MODELEAFFICHERPERSONNE_H

#include <QAbstractListModel>
#include "modele/photos.h"

class ModeleAfficherPersonne : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit ModeleAfficherPersonne(Photos * photos,QObject *parent = 0);
    QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;
    int rowCount (const QModelIndex & = QModelIndex()) const;
    
signals:
    
public slots:

private:
    Photos * mPhotos;
    
};

#endif // MODELEAFFICHERPERSONNE_H
