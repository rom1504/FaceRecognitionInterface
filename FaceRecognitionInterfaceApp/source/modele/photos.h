#ifndef PHOTOS_H
#define PHOTOS_H

#include <QObject>
#include <QList>
#include <QMap>
#include <functional>
#include <QSet>

#include "photo.h"
#include "identification.h"
#include "personnemap.h"

/**
 * @brief La classe Photos regroupe toutes les photos et leurs informations associées : les noms de fichiers des photos et les identifications liées à ces photos, cette classe permet aussi de faire les opérations voulues sur les identifications
 */
class Photos : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Photos un constructeur simple
     * @param parent fourni au QObject
     */
    explicit Photos(QObject *parent = 0);
    /**
     * @brief personnes fournit la liste des personnes dans les photos (utile pour la reconnaissance manuelle)
     * @return sous la forme d'une liste de string
     */
    SignalList<QString> &personnes();
    /**
     * @brief chargerPhotos permet de charger toutes les photos d'un dossier
     * @param dossier le chemin du dossier
     * @param dossierInformation le chemin du dossier contenant les fichiers informations
     */
    void chargerPhotos(QString dossier,QString dossierInformation);

    void clear();

    PersonneMap<Identification *> & identificationsDe();
    PersonneMap<Photo *> & photosDe();
    SignalList<Photo*> & photos();
    SignalList<Identification*> & identificationsNonReconnus();
    PersonneMap<Identification*> & identificationsNonValidees();

private:
    /**
     * @brief ajouterPhoto permet d'ajouter une photo
     * @param nomFichier le chemin de la photo
     * @param nomFichierInformations le chemin du fichier d'information
     */
    void ajouterPhoto(QString nomFichier, QString nomFichierInformation);

protected:
    // doit permettre d'accéder facilement aux :
    // - identifications pour la reconnaissance : pas indexées
    // - identifications pour la validation : indéxées par la personne
    // - identifications déjà validées : indexées par la personne
    // - photos déjà validées : indexées par la personne

    /**
     * @brief mIdentificationsNonReconnus contient toutes les identifications non reconnues
     */
    SignalList<Identification*> mIdentificationsNonReconnus;
    /**
     * @brief mIdentificationsNonValidees contient les identifications non validées, associées aux personnes
     */
    PersonneMap<Identification*> mIdentificationsNonValidees;
    /**
     * @brief mIdentificationsDe contient les identifications associées aux personnes (validées et reconnues)
     */
    PersonneMap<Identification*>  mIdentificationsDe;
    /**
     * @brief mPhotosDe contient les photos associées aux personnes (validées et reconnues)
     */
    PersonneMap<Photo*>  mPhotosDe;

    SignalList<Photo*> mPhotos;

    /**
     * @brief mPersonnes contient l'ensemble des personnes (utilisé pour proposer des personnes pour la reconnaissance manuelle)
     */
    SignalList<QString> mPersonnes;
    
};

#endif // PHOTOS_H
