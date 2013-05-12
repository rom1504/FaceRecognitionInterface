#include "photos.h"
#include "photo.h"
#include <QDir>

Photos::Photos(QObject *parent) :
    QObject(parent)
{
}

void Photos::ajouterPhoto(QString nomFichier,QString personne,QString dossier)
{
    mPhotos[personne]<<new Photo(nomFichier,personne,dossier);
}

void Photos::chargerPhotos(QString dossier,std::function<bool(QString)> filtre)
{
    QDir dir(dossier);
    for(QString personne : dir.entryList(QDir::Dirs))
    {
        if(personne!="." && personne!="..")
        {
            QDir dirPersonne(dossier+"/"+personne);
            for(QString nomFichier : dirPersonne.entryList(QDir::Files)) if(filtre(personne+"/"+nomFichier)) ajouterPhoto(nomFichier,personne,dossier);
            if(mPhotos.contains(personne)) mPersonnes<<personne;
        }
    }
}

const QList<QString> & Photos::personnes() const
{
    return mPersonnes;
}

const QList<Photo*> Photos::photosDe(QString personne) const
{
    return mPhotos[personne];
}
