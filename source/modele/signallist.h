#ifndef SIGNALLIST_H
#define SIGNALLIST_H

#include <QObject>
#include <functional>

class SignalListBase : public QObject
{
    Q_OBJECT
public:
    SignalListBase(QObject * parent=0);

signals:
    void debutAjout(int position);
    void finAjout(int position);
    void debutSupression(int position);
    void finSupression(int position);
    void beginReset();
    void endReset();
};
//when ready put all this on a different module ( / library ) and possibly use it inside sale contract filler
template <class T> class SignalList : public SignalListBase
{
public:
    SignalList(std::function<bool(T,T)> comp,bool ordered=false,QObject * parent=0); // could inherit with for ordered instead of if (slower) parameterization
    SignalList();
    void ajout(T element);
    void suppression(T element);
    int nombre() const;
    T get(int numero);
    T get(int numero) const;
    bool contient(T element) const;
    void clear();
// add begin load and end load maybe (and not emit anything except beginreset and endreset between those) ?

private:
    QList<T> mList;
    bool mOrdered;
    std::function<bool(T,T)> mComp;
};
#include "signallist.hxx"

#endif // SIGNALLIST_H
