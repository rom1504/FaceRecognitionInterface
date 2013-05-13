#ifndef PHOTOSAVALIDER_H
#define PHOTOSAVALIDER_H

#include <QObject>
#include <QList>
#include <QSet>
#include <QMap>
#include "photo.h"
#include "photos.h"

class PhotosAValider : public Photos
{
    Q_OBJECT
public:
    explicit PhotosAValider(QString dossierSortie="donnees/sortie",QString dossierValide="donnees/valide",QObject *parent = 0);
    void ajouterPhoto(QString nomFichier, QString personne);
    void chargerPhotos();
    QList<Photo*> premieresPhotosDe(QString personne,int nombre=20) const;

    /**
     * @brief valider valide les premieres photos
     * @param personne personne dont on valides les photos
     * @param valides liste de bool indiquant si cette photo a bien été reconnu ou pas
     * @return si on a tout validé alors true sinon false
     */
    bool valider(QString personne,QList<bool> valides);
    
signals:
    
public slots:
    
private:
    QString mDossierSortie;
    QString mDossierValide;
    QSet<QString> mPhotosDejaValides;
};

#endif // PHOTOSAVALIDER_H
