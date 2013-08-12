#include <QDebug>

#include "controleur.h"
#include "adapteur/photosignallistadapter.h"
#include "vue/identificationeditor.h"

Controleur::Controleur(QObject *parent) :
    QObject(parent)
{
    QString cheminPhotos="donnees/photos";
    QString cheminPhotoDecoupees="donnees/photosDecoupees";
    QString cheminInformation="donnees/informations";
    QString cheminIntermediaire="donnees/intermediaire";
    QString cheminModele="donnees/modele";


    mMainWindow=new MainWindow(cheminPhotos,cheminPhotoDecoupees,cheminInformation,cheminIntermediaire,cheminModele);
    mPhotos=new Photos();
    mPhotos->chargerPhotos(cheminPhotos,cheminInformation);
    IdentificationEditor::mPersonnes=new SignalListAdapter<QString>(&(mPhotos->personnes()));


    mMainWindow->setAdapterIdentificationNonReconnues(new SignalListAdapter<Identification*>(&(mPhotos->identificationsNonReconnus())));
    mMainWindow->setAdapterIdentificationNonValidees(&(mPhotos->identificationsNonValidees()));
    mMainWindow->setAdapterIdentificationDe(&(mPhotos->identificationsDe()));
    mMainWindow->setAdapterPhotoDe(&(mPhotos->photosDe()));

    connect(mMainWindow,&MainWindow::reloadPhotos,[this,cheminPhotos,cheminInformation](){
        mPhotos->clear();
        mPhotos->chargerPhotos(cheminPhotos,cheminInformation);
    });

}

void Controleur::run()
{
    mMainWindow->run();
}
