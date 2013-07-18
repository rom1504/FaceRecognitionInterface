#ifndef QSTRINGSIGNALLISTADAPTER_H
#define QSTRINGSIGNALLISTADAPTER_H

#include <QString>

#include "adapter/signallistadapter.h"


template<> class SignalListAdapter<QString> : public SignalListAdapterBase<QString>
{
public:
    explicit SignalListAdapter(SignalList<QString> * list,QObject *parent = 0);
    QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;

};

#endif // QSTRINGSIGNALLISTADAPTER_H
