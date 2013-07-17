#include "photos.h"
#include "photo.h"
#include <QDir>
#include <QDebug>


Photos::Photos(QObject *parent) :
    QObject(parent),mPersonnes([](QString a,QString b){return a<b;},true)
{
}

void Photos::ajouterPhoto(QString nomFichier,QString nomFichierInformation)
{
    Photo * photo=new Photo(nomFichier,nomFichierInformation);
    const QList<Identification *> & identifications = photo->identifications();
    for(Identification * identification : identifications)
    {
        if(identification->ignore()) continue;
        if(!identification->identifie()) mIdentificationsNonReconnus.ajout(identification);
        else
        {
            QString personne=identification->personne();
            if(!mPersonnes.contient(personne)) mPersonnes.ajout(personne);
            if(!identification->valide()) mIdentificationsNonValidees.ajout(personne,identification);
            else
            {
                mIdentificationsDe.ajout(personne,identification);
                mPhotosDe.ajout(personne,photo);
            }
        }
        connect(identification,&Identification::sidentifie,[this,identification](){
            mIdentificationsNonReconnus.suppression(identification);
            mIdentificationsNonValidees.ajout(identification->personne(),identification);
            if(!mPersonnes.contient(identification->personne())) mPersonnes.ajout(identification->personne());
        });
        connect(identification,&Identification::svalide,[this,identification](){
            mIdentificationsNonValidees.suppression(identification->personne(),identification);
            mIdentificationsDe.ajout(identification->personne(),identification);
            if(!mPhotosDe.contient(identification->personne(),identification->photoAssocie())) mPhotosDe.ajout(identification->personne(),identification->photoAssocie());
        });

        connect(identification,&Identification::sinvalide,[this,identification](){
            mIdentificationsNonValidees.suppression(identification->personne(),identification);
            mIdentificationsNonReconnus.ajout(identification);
        });

        connect(identification,&Identification::signore,[this,identification](){
            if(!identification->valide() && identification->identifie()) mIdentificationsNonValidees.suppression(identification->personne(),identification);
            if(!identification->identifie()) mIdentificationsNonReconnus.suppression(identification);
        });
    }
}


void Photos::clear()
{
    mIdentificationsNonReconnus.clear();
    mIdentificationsNonValidees.clear();
    mIdentificationsDe.clear();
    mPhotosDe.clear();
    mPersonnes.clear();
}


SignalList<Identification *> &Photos::identificationsNonReconnus()
{
    return mIdentificationsNonReconnus;
}

PersonneMap<Identification*> & Photos::identificationsDe()
{
    return mIdentificationsDe;
}


PersonneMap<Photo *> & Photos::photosDe()
{
    return mPhotosDe;
}

void Photos::chargerPhotos(QString dossier, QString dossierInformation)
{
    QDir dir(dossier);
    for(QFileInfo infoFichier : dir.entryInfoList(QDir::Files)) ajouterPhoto(infoFichier.filePath(),dossierInformation+"/"+infoFichier.fileName()+".txt");
}

SignalList<QString> &Photos::personnes()
{
    return mPersonnes;
}

PersonneMap<Identification*> & Photos::identificationsNonValidees()
{
    return mIdentificationsNonValidees;
}
