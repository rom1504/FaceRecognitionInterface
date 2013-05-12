#include "controleur.h"

Controleur::Controleur(QObject *parent) :
    QObject(parent)
{
    mMainWindow=new MainWindow();
    mPhotos=new Photos();
    mPhotos->chargerPhotos();
    mMainWindow->setModel(mPhotos);
}

void Controleur::run()
{
    mMainWindow->show();
}
