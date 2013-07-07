#ifndef PERSONNEMAP_H
#define PERSONNEMAP_H

#include <QString>
#include <QMap>
#include <QList>
#include <QObject>
#include "signallist.h"

class PersonneMapBase : public QObject
{
    Q_OBJECT
public:
    PersonneMapBase(QObject * parent=0);

signals:
    void debutAjoutPersonne(int position);
    void finAjoutPersonne(int position);
    void debutSupressionPersonne(int position);
    void finSupressionPersonne(int position);


    void debutAjoutElement(QString personne,int position);
    void finAjoutElement(QString personne,int position);
    void debutSuppressionElement(QString personne,int position);
    void finSuppressionElement(QString personne,int position);
};

template <class T> class PersonneMap : public PersonneMapBase
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

private:
    SignalList<QString> * mPersonnes;
    QMap<QString,SignalList<T>*> mMap;
};

#include "personnemap.hxx"

#endif // PERSONNEMAP_H
