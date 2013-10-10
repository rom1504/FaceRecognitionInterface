#include <QDebug>

#include "controleur.h"
#include "adapteur/photosignallistadapter.h"
#include "vue/identificationeditor.h"
#include "vue/personsearch.h"

Controleur::Controleur(QObject *parent) :
    QObject(parent)
{
    QString directoryListFile="donnees/directoryList.txt";
    QString cheminPhotos="donnees/photos";
    QString cheminPhotoDecoupees="donnees/photosDecoupees";
    QString cheminInformation="donnees/informations";
    QString cheminIntermediaire="donnees/intermediaire";
    QString cheminModele="donnees/modele";


    mMainWindow=new MainWindow(directoryListFile,cheminPhotos,cheminPhotoDecoupees,cheminInformation,cheminIntermediaire,cheminModele);
    mPhotos=new Photos();
    mPhotos->chargerPhotos(cheminPhotos,cheminInformation);
    IdentificationEditor::mPersonnes=new SignalListAdapter<QString>(&(mPhotos->personnes()));
    PersonSearch::mPersonnes=&(mPhotos->personnes());


    mMainWindow->setAdapterIdentificationNonReconnues(new SignalListAdapter<Identification*>(&(mPhotos->identificationsNonReconnus())));
    mMainWindow->setAdapterIdentificationNonValidees(&(mPhotos->identificationsNonValidees()));
    mMainWindow->setAdapterIdentificationDe(&(mPhotos->identificationsDe()));
    mMainWindow->setAdapterPhotoDe(&(mPhotos->photosDe()));
    SignalListAdapter<Photo*> * photosAdapter=new SignalListAdapter<Photo*>(&(mPhotos->photos()));
    mMainWindow->setAdapterPhotos(photosAdapter);

    connect(mMainWindow,&MainWindow::reloadPhotos,[this,cheminPhotos,cheminInformation](){
        mPhotos->clear();
        mPhotos->chargerPhotos(cheminPhotos,cheminInformation);
    });

    connect(mMainWindow,&MainWindow::rechercher,[this,photosAdapter](QStringList * persons){
        SignalListFilter<Photo*> * adapter=new SignalListFilter<Photo*>();
        adapter->setSourceModel(photosAdapter);
        adapter->setFilter([persons](Photo * photo){return photo->containsPersons(persons);});
        mMainWindow->setAdapterSearch(adapter);
        mMainWindow->showSearchView();
    });

}

void Controleur::run()
{
    mMainWindow->run();
}
