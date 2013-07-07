#ifndef QSTRINGSIGNALLISTADAPTER_H
#define QSTRINGSIGNALLISTADAPTER_H

#include <QString>

#include "signallistadapter.h"


class QStringSignalListAdapter : public SignalListAdapter<QString>
{
    Q_OBJECT
public:
    explicit QStringSignalListAdapter(SignalList<QString> * list,QObject *parent = 0);
    QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;

};

#endif // QSTRINGSIGNALLISTADAPTER_H
