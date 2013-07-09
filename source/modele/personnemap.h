#ifndef PERSONNEMAP_H
#define PERSONNEMAP_H

#include <QString>
#include <QMap>
#include <QList>
#include <QObject>
#include "signallist.h"

template <class T> class PersonneMap : public QObject
{
public:
    PersonneMap(QObject * parent=0);
    void ajout(QString personne,T element);
    void suppression(QString personne,T element);
    QString getPersonne(int numero) const;
    int nombrePersonne() const;
    T getElement(QString personne,int numero);
    int nombreElement(QString personne);
    SignalList<T> * getList(QString personne);
    SignalList<QString> * getPersonnes();
    bool contient(QString personne,T element) const;
    void clear();

private:
    SignalList<QString> * mPersonnes;
    QMap<QString,SignalList<T>*> mMap;
};

#include "personnemap.hxx"

#endif // PERSONNEMAP_H
