#include "photos.h"
#include <QDir>
#include <cmath>
#include <iostream>
#include <QFile>
#include <QTextStream>

Photos::Photos(QString dossierSortie, QString dossierValide, QObject *parent) :
    QObject(parent),mDossierSortie(dossierSortie),mDossierValide(dossierValide)
{
    QFile fichierPhotosDejaValides("photosDejaValides.txt");
    fichierPhotosDejaValides.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream flux(&fichierPhotosDejaValides);
    while(!flux.atEnd()) mPhotosDejaValides<<flux.readLine();
    fichierPhotosDejaValides.close();
}

void Photos::ajouterPhoto(QString nomFichier,QString personne)
{
    mPhotos[personne]<<new Photo(nomFichier,personne,mDossierSortie);
}

bool Photos::valider(QString personne,QList<bool> valides)
{
    QFile fichierPhotosDejaValides("photosDejaValides.txt");
    fichierPhotosDejaValides.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append);
    QTextStream flux(&fichierPhotosDejaValides);
    const QList<Photo*> photos=premieresPhotosDe(personne);
    QDir dir;
    for(int i=0;i<valides.size();i++)
    {
        QString nDossier=mDossierValide+"/"+(valides[i] ? personne : "invalide");
        if(!dir.exists(nDossier)) dir.mkdir(nDossier);
        QFile::copy(mDossierSortie+"/"+personne+"/"+photos[i]->nomFichier(),nDossier+"/"+photos[i]->nomFichier());
        flux<<personne+"/"+photos[i]->nomFichier()<<endl;
    }
    fichierPhotosDejaValides.close();
    QList<Photo*> & listeComplete=mPhotos[personne];
    for(int i=0;i<valides.size();i++) listeComplete.removeFirst();
    if(listeComplete.isEmpty())
    {
        mPhotos.remove(personne);
        mPersonnes.removeAll(personne);
        emit dataChanged();
        return true;
    }
    return false;
}

void Photos::chargerPhotos()
{
    QDir dir(mDossierSortie);
    for(QString personne : dir.entryList(QDir::Dirs))
    {
        if(personne!="." && personne!="..")
        {
            QDir dirPersonne(mDossierSortie+"/"+personne);
            for(QString nomFichier : dirPersonne.entryList(QDir::Files)) if(!mPhotosDejaValides.contains(personne+"/"+nomFichier)) ajouterPhoto(nomFichier,personne);
            if(mPhotos.contains(personne)) mPersonnes<<personne;
        }
    }
}

const QList<QString> & Photos::personnes() const
{
    return mPersonnes;
}

QList<Photo*> Photos::premieresPhotosDe(QString personne,int nombre) const
{
    const QList<Photo*> & listeComplete=mPhotos[personne];
    int taille=std::min(nombre,listeComplete.size());
    QList<Photo*> liste;
    std::copy(listeComplete.begin(),listeComplete.begin()+taille,std::back_inserter(liste));
    return liste;
}
