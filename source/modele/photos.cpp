#include "photos.h"
#include "photo.h"
#include <QDir>
#include <QDebug>


Photos::Photos(QObject *parent) :
    QObject(parent)
{
}

void Photos::ajouterPhoto(QString nomFichier,QString nomFichierInformation)
{
    Photo * photo=new Photo(nomFichier,nomFichierInformation);
    const QList<Identification *> & identifications = photo->identifications();
    for(Identification * identification : identifications)
    {
        if(!identification->identifie()) mIdentificationsNonReconnus.ajout(identification);
        else
        {
            QString personne=identification->personne();
            mPersonnes<<personne;
            if(!identification->valide()) mIdentificationsNonValidees.ajout(personne,identification);
            else
            {
                mIdentificationsDe.ajout(personne,identification);
                mPhotosDe.ajout(personne,photo);
            }
        }
        connect(identification,&Identification::sidentifie,[this](){
            Identification * identification=dynamic_cast<Identification*>(sender());
            mIdentificationsNonReconnus.suppression(identification);// marche ?? devrait marcher oui
            mIdentificationsNonValidees.ajout(identification->personne(),identification);
        });
        connect(identification,&Identification::svalide,[this](){
            Identification * identification=dynamic_cast<Identification*>(sender());
            mIdentificationsNonValidees.suppression(identification->personne(),identification);// marche ?? devrait marcher oui
            mIdentificationsDe.ajout(identification->personne(),identification);
            if(!mPhotosDe.contient(identification->personne(),identification->photoAssocie())) mPhotosDe.ajout(identification->personne(),identification->photoAssocie());
        });

        connect(identification,&Identification::sinvalide,[this](){
            Identification * identification=dynamic_cast<Identification*>(sender());
            mIdentificationsNonValidees.suppression(identification->personne(),identification);// marche ?? devrait marcher oui
            mIdentificationsNonReconnus.ajout(identification);
        });
    }
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

const QSet<QString> & Photos::personnes() const
{
    return mPersonnes;
}

PersonneMap<Identification*> & Photos::identificationsNonValidees()
{
    return mIdentificationsNonValidees;
}
