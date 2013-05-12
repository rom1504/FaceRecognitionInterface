#include "photosAValider.h"
#include <QDir>
#include <cmath>
#include <iostream>
#include <QFile>
#include <QTextStream>

PhotosAValider::PhotosAValider(QString dossierSortie, QString dossierValide, QObject *parent) :
    Photos(parent),mDossierSortie(dossierSortie),mDossierValide(dossierValide)
{
    QFile fichierPhotosDejaValides("photosDejaValides.txt");
    fichierPhotosDejaValides.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream flux(&fichierPhotosDejaValides);
    while(!flux.atEnd()) mPhotosDejaValides<<flux.readLine();
    fichierPhotosDejaValides.close();
}

void PhotosAValider::ajouterPhoto(QString nomFichier,QString personne)
{
    Photos::ajouterPhoto(nomFichier,personne,mDossierSortie);
}

bool PhotosAValider::valider(QString personne,QList<bool> valides)
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
        int debut=mPersonnes.indexOf(personne);
        int fin=mPersonnes.lastIndexOf(personne);
        emit beginRemoveRows(debut,fin);
        mPhotos.remove(personne);
        mPersonnes.removeAll(personne);
        emit endRemoveRows();
        return true;
    }
    return false;
}

void PhotosAValider::chargerPhotos()
{
    Photos::chargerPhotos(mDossierSortie,[this](QString chemin){return !mPhotosDejaValides.contains(chemin);});
}

QList<Photo*> PhotosAValider::premieresPhotosDe(QString personne,int nombre) const
{
    const QList<Photo*> & listeComplete=mPhotos[personne];
    int taille=std::min(nombre,listeComplete.size());
    QList<Photo*> liste;
    std::copy(listeComplete.begin(),listeComplete.begin()+taille,std::back_inserter(liste));
    return liste;
}
