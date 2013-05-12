#include "photo.h"
#include <iostream>

Photo::Photo(QString nomFichier, QString personne, QString dossier, QObject *parent) :
    QObject(parent),mNomFichier(nomFichier),mImage(dossier+"/"+personne+"/"+nomFichier)
{

}

const QPixmap & Photo::image() const
{
    return mImage;
}


const QString Photo::nomFichier() const
{
    return mNomFichier;
}
