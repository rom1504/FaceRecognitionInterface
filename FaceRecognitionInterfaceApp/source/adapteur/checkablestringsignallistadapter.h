#ifndef CHECKABLESTRINGSIGNALLISTADAPTER_H
#define CHECKABLESTRINGSIGNALLISTADAPTER_H

#include <QObject>
#include <QMap>

#include "adapter/qstringsignallistadapter.h"

class CheckableStringSignalListAdapter : public SignalListAdapter<QString>
{
    Q_OBJECT
public:
    explicit CheckableStringSignalListAdapter(SignalList<QString> * list,QObject *parent = 0);
    QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
    Qt::ItemFlags flags(const QModelIndex & index) const;
    QMap<QString,bool> checkList() const;
    
private:
    QMap<QString,bool> mCheckList;
    
};

#endif // CHECKABLESTRINGSIGNALLISTADAPTER_H
