#ifndef PHOTOSIGNALLISTADAPTER_H
#define PHOTOSIGNALLISTADAPTER_H

#include "adapter/signallistadapter.h"
#include "modele/photo.h"
#include "modele/cachephotos.h"

template<> class SignalListAdapter<Photo*> : public SignalListAdapterBase<Photo*>
{
public:
    explicit SignalListAdapter(SignalList<Photo*> * list,QObject *parent = 0);
    QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;

private:
    
};

#endif // PHOTOSIGNALLISTADAPTER_H
