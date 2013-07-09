#ifndef SIGNALLIST_HXX
#define SIGNALLIST_HXX

#include "signallist.h"


template <class T> SignalList<T>::SignalList(std::function<bool(T,T)> comp, bool ordered, QObject * parent) : SignalListBase(parent),mOrdered(ordered),mComp(comp)
{

}

template <class T> SignalList<T>::SignalList() : SignalList([](T,T){return false;})
{

}

template <class T> void SignalList<T>::ajout(T element)
{
    int numeroElement=mOrdered ? std::find_if(mList.begin(),mList.end(),[this,element](T a){return mComp(element,a);})-mList.begin() : mList.size()-1;
    emit debutAjout(numeroElement);
    mList.insert(numeroElement,element);
    emit finAjout(numeroElement);
}

template <class T> void SignalList<T>::suppression(T element)
{
    int numeroElement=mList.indexOf(element);
    emit debutSupression(numeroElement);
    mList.removeAt(numeroElement);
    emit finSupression(numeroElement);
}


template <class T> void SignalList<T>::clear()
{
    emit beginReset();
    mList.clear();
    emit endReset();
}


template <class T> bool SignalList<T>::contient(T element) const
{
    return mList.contains(element);
}

template <class T> int SignalList<T>::nombre() const
{
    return mList.size();
}

template <class T> T SignalList<T>::get(int numero)
{
    return mList.at(numero);
}


template <class T> T SignalList<T>::get(int numero) const
{
    return mList.at(numero);
}


#endif // SIGNALLIST_HXX
