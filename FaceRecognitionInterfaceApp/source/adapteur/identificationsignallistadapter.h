#ifndef IDENTIFICATIONSIGNALLISTADAPTER_H
#define IDENTIFICATIONSIGNALLISTADAPTER_H

#include "modele/identification.h"
#include "modele/cachephotos.h"

#include "adapter/signallistadapter.h"


class IdentificationSignalListAdapter : public SignalListAdapter<Identification*>
{
    Q_OBJECT
public:
    explicit IdentificationSignalListAdapter(SignalList<Identification *> *list, QObject *parent = 0);
    QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;
    Qt::ItemFlags flags(const QModelIndex & index) const;
    static CachePhotos mCachePhotos;
    
private:

    
};

#endif // IDENTIFICATIONSIGNALLISTADAPTER_H
