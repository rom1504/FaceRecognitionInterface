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

signals:

private:
    QList<Photo*> mPhotos;
    
};

#endif // MODELEAFFICHERPHOTOS_H
