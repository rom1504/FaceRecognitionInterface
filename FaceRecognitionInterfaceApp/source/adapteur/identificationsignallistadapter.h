#ifndef IDENTIFICATIONSIGNALLISTADAPTER_H
#define IDENTIFICATIONSIGNALLISTADAPTER_H

#include "modele/identification.h"
#include "modele/cachephotos.h"

#include "adapter/signallistadapter.h"


template<> class SignalListAdapter<Identification*> : public SignalListAdapterBase<Identification*>
{
public:
    explicit SignalListAdapter(SignalList<Identification *> *list, QObject *parent = 0);
    QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;
    Qt::ItemFlags flags(const QModelIndex & index) const;
    static CachePhotos mCachePhotos;
    
private:

    
};
//#include "identificationsignallistadapter.hxx"

#endif // IDENTIFICATIONSIGNALLISTADAPTER_H
