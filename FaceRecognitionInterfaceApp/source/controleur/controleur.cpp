#include <QDebug>

#include "controleur.h"
#include "adapteur/photosignallistadapter.h"
#include "vue/identificationeditor.h"

Controleur::Controleur(QObject *parent) :
    QObject(parent)
{
    mMainWindow=new MainWindow();
    mPhotos=new Photos();
    mPhotos->chargerPhotos("donnees/photos","donnees/informations");
    IdentificationEditor::mPersonnes=new SignalListAdapter<QString>(&(mPhotos->personnes()));


    mMainWindow->setAdapterIdentificationNonReconnues(new SignalListAdapter<Identification*>(&(mPhotos->identificationsNonReconnus())));
    mMainWindow->setAdapterIdentificationNonValidees(&(mPhotos->identificationsNonValidees()));
    mMainWindow->setAdapterIdentificationDe(&(mPhotos->identificationsDe()));
    mMainWindow->setAdapterPhotoDe(&(mPhotos->photosDe()));

    connect(mMainWindow,&MainWindow::reloadPhotos,[this](){
        mPhotos->clear();
        mPhotos->chargerPhotos("donnees/photos","donnees/informations");
    });

}

void Controleur::run()
{
    mMainWindow->run();
}
