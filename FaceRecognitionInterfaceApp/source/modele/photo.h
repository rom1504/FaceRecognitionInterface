#ifndef PHOTO_H
#define PHOTO_H

#include "identification.h"

/**
 * @brief La classe Photo stocke une photo (son nom de fichier) plus ses identifications, son nom de fichier d'information et enregistre et charge ces identifications dans ce fichier (quand elle change : enregistrement automatique)
 */
class Photo : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Photo constructeur simple
     * @param nomFichier fichier image
     * @param nomFichierInformation fichier information
     * @param parent pour le qobject
     */
    Photo(QString nomFichier,QString nomFichierInformation,QObject * parent=0);
    /**
     * @brief ajouterIdentification ajoute une identification
     * @param s sous le format du fichier information
     */
    void ajouterIdentification(QString s);
    /**
     * @brief ajouterIdentification ajoute une identification
     * @param identification pointeur d'identification
     */
    void ajouterIdentification(Identification * identification);
    /**
     * @brief identifications permet d'accéder aux identification
     * @return les identifications mais constante
     */
    const QList<Identification *> & identifications() const;
    /**
     * @brief nomFichier fichier photo
     * @return nom fichier photo
     */
    QString nomFichier() const;


    bool containsPersons(QStringList * persons) const;

private:
    /**
     * @brief chargerIdentification charge les identifications depuis le fichier information
     */
    void chargerIdentification();
    /**
     * @brief enregistrer enregistre les identifications dans le fichier information
     */
    void enregistrer() const;

private:
    /**
     * @brief mIdentifications identifications de cette photo
     */
    QList<Identification *> mIdentifications;
    /**
     * @brief mNomFichierInformation fichier information de l'image
     */
    QString mNomFichierInformation;
    /**
     * @brief mNomFichier fichier photo
     */
    QString mNomFichier;
};

Q_DECLARE_METATYPE (Photo*)

#endif // PHOTO_H
