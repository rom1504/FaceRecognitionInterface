#ifndef PERSONNEMAP_HXX
#define PERSONNEMAP_HXX

#include "personnemap.h"

template <class T> PersonneMap<T>::PersonneMap(QObject * parent) : QObject(parent),mPersonnes(new SignalList<QString>([](QString a,QString b){return a>=b;},true))
{

}

template <class T> void PersonneMap<T>::ajout(QString personne,T element)
{
    if(!mPersonnes->contient(personne))
    {
        mPersonnes->ajout(personne);
        mMap.insert(personne,new SignalList<T>());
    }
    mMap[personne]->ajout(element);
}


template <class T> void PersonneMap<T>::clear()
{
    for(SignalList<T>* list : mMap.values()) list->clear();
    mPersonnes->clear();
    mMap.clear();
}


template <class T> bool PersonneMap<T>::contient(QString personne,T element) const
{
    return mMap.contains(personne) && mMap[personne]->contient(element);
}

template <class T> SignalList<T> *PersonneMap<T>::getList(QString personne)
{
    return mMap[personne];
}

template <class T> SignalList<QString> *PersonneMap<T>::getPersonnes()
{
    return mPersonnes;
}

template <class T> void PersonneMap<T>::suppression(QString personne,T element)
{
    mMap[personne]->suppression(element);
    if(mMap[personne]->nombre()==0)
    {
        mPersonnes->suppression(personne);
        mMap.remove(personne);
    }
}

template <class T> QString PersonneMap<T>::getPersonne(int numero) const
{
    return mPersonnes->get(numero);
}

template <class T> int PersonneMap<T>::nombrePersonne() const
{
    return mPersonnes->nombre();
}

template <class T> T PersonneMap<T>::getElement(QString personne,int numero)
{
    return mMap[personne]->get(numero);
}

template <class T> int PersonneMap<T>::nombreElement(QString personne)
{
    return mMap[personne]->nombre();
}


#endif // PERSONNEMAP_HXX
