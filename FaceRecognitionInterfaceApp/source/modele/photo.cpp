#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QSet>
#include <QStringList>

#include "photo.h"

Photo::Photo(QString nomFichier,QString nomFichierInformation,QObject * parent) : QObject(parent),mNomFichierInformation(nomFichierInformation),mNomFichier(nomFichier)
{
    chargerIdentification();
}


void Photo::ajouterIdentification(QString s)
{
    Identification * identification=new Identification(s,this);
//    qDebug()<<identification->toQString();
    ajouterIdentification(identification);
}

void Photo::ajouterIdentification(Identification * identification)
{
    connect(identification,&Identification::modifie,this,&Photo::enregistrer);
    mIdentifications<<identification;
}

const QList<Identification *> & Photo::identifications() const
{
    return mIdentifications;
}


bool Photo::containsPersons(QStringList *persons) const
{
    QSet<QString> s1,s2;
    for(QString person : *persons) s1<<person;
    for(Identification * identification : mIdentifications) s2<<identification->personne();
    return s2.contains(s1);
}


void Photo::chargerIdentification()
{
    QFile fichier(mNomFichierInformation);
    if (!fichier.open(QIODevice::ReadOnly | QIODevice::Text)) return;
    QTextStream in(&fichier);
    while (!in.atEnd())
    {
        QString ligne=in.readLine();
        ajouterIdentification(ligne);
    }
    fichier.close();
}



void Photo::enregistrer() const
{
    QFile fichier(mNomFichierInformation);
    if (!fichier.open(QIODevice::WriteOnly | QIODevice::Text)) return;
    QTextStream out(&fichier);
    for(Identification * i : mIdentifications) out<<i->toQString()<<"\n";
    fichier.close();
}


QString Photo::nomFichier() const
{
    return mNomFichier;
}
