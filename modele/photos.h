#ifndef PHOTOS_H
#define PHOTOS_H

#include <QObject>
#include <QList>
#include <QSet>
#include <QMap>
#include "photo.h"

class Photos : public QObject
{
    Q_OBJECT
public:
    explicit Photos(QString dossierSortie="sortie",QString dossierValide="valide",QObject *parent = 0);
    void ajouterPhoto(QString nomFichier, QString personne);
    void chargerPhotos();
    QList<Photo*> premieresPhotosDe(QString personne,int nombre=20) const;
    const QList<QString> & personnes() const;
    bool valider(QString personne,QList<bool> valides);
    
signals:
    void dataChanged();
    
public slots:
    
private:
    QMap<QString,QList<Photo*> > mPhotos;
    QStringList mPersonnes;
    QString mDossierSortie;
    QString mDossierValide;
    QSet<QString> mPhotosDejaValides;
};

#endif // PHOTOS_H
