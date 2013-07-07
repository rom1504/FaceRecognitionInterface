#include <QDebug>

#include "controleur.h"
#include "adapteur/photosignallistadapter.h"

Controleur::Controleur(QObject *parent) :
    QObject(parent)
{
    mMainWindow=new MainWindow();
    mPhotos=new Photos();
    mPhotos->chargerPhotos("donnees/photos","donnees/informations");
    IdentificationSignalListAdapter::mCachePhotos=mCachePhotos;
    PhotoSignalListAdapter::mCachePhotos=mCachePhotos;


    mMainWindow->setAdapterIdentificationNonReconnues(new IdentificationSignalListAdapter(&(mPhotos->identificationsNonReconnus())));
    mMainWindow->setAdapterIdentificationNonValidees(&(mPhotos->identificationsNonValidees()));
    mMainWindow->setAdapterIdentificationDe(&(mPhotos->identificationsDe()));
    mMainWindow->setAdapterPhotoDe(&(mPhotos->photosDe()));

}

void Controleur::run()
{
    mMainWindow->show();
}
