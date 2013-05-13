#include "controleur.h"

Controleur::Controleur(QObject *parent) :
    QObject(parent)
{
    mMainWindow=new MainWindow();
    mPhotosAffichees=new Photos();
    mPhotosAffichees->chargerPhotos("donnees/valide");
    mMainWindow->setModelAfficherPersonne(new ModeleAfficherPersonne(mPhotosAffichees),true);

    connect(mMainWindow,&MainWindow::validerPersonne,[this](QString personne){
        mPersonne=personne;
        mMainWindow->setModelValiderPhotos(new ModeleValiderPhotos(mPhotosAValider->premieresPhotosDe(mPersonne)));
    });

    connect(mMainWindow,&MainWindow::afficherPersonne,[this](QString personne){
        mPersonne=personne;
        mMainWindow->setModelAfficherPhotos(new ModeleAfficherPhotos(mPhotosAffichees->photosDe(mPersonne)));
    });

    connect(mMainWindow,&MainWindow::validerPhotos,[this](QList<bool> valides){
        if(!mPhotosAValider->valider(mPersonne,valides)) mMainWindow->setModelValiderPhotos(new ModeleValiderPhotos(mPhotosAValider->premieresPhotosDe(mPersonne)));
    });

    connect(mMainWindow,&MainWindow::afficherPhotos,[this](){
        mPhotosAffichees=new Photos();
        mPhotosAffichees->chargerPhotos("donnees/valide");
        mMainWindow->setModelAfficherPersonne(new ModeleAfficherPersonne(mPhotosAffichees),true);
    });


    connect(mMainWindow,&MainWindow::verifierReconnaissance,[this](){
        mPhotosAValider=new PhotosAValider();
        mPhotosAValider->chargerPhotos();
        mMainWindow->setModelAfficherPersonne(new ModeleAfficherPersonne(mPhotosAValider),false);
    });
}

void Controleur::run()
{
    mMainWindow->show();
}
