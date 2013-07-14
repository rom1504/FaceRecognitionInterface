#ifndef PHOTOSIGNALLISTADAPTER_H
#define PHOTOSIGNALLISTADAPTER_H

#include "adapter/signallistadapter.h"
#include "modele/photo.h"
#include "modele/cachephotos.h"

class PhotoSignalListAdapter : public SignalListAdapter<Photo*>
{
    Q_OBJECT
public:
    explicit PhotoSignalListAdapter(SignalList<Photo*> * list,QObject *parent = 0);
    QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;
    static CachePhotos mCachePhotos;
    
private:
    
};

#endif // PHOTOSIGNALLISTADAPTER_H
