#ifndef PERSONNEMAPVIEWER_HXX
#define PERSONNEMAPVIEWER_HXX

#include "personnemapviewer.h"
#include "ui_personnemapviewer.h"
#include "vue/afficherpersonnes.h"

template <class T,class ViewerType> PersonneMapViewer<T,ViewerType>::PersonneMapViewer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PersonneMapViewer),
    mViewer(new ViewerType())
{
    ui->setupUi(this);
    ui->horizontalLayout->addWidget(mViewer);
    ui->horizontalLayout->setStretch(1,1);
    ui->horizontalLayout->setStretch(2,1);
}

template <class T,class ViewerType> void PersonneMapViewer<T,ViewerType>::setModel(PersonneMap<T> * personneMap)
{
    mPersonneMap=personneMap;
    ui->afficherPersonnes->setModel(new SignalListAdapter<QString>(mPersonneMap->getPersonnes()));
    connect(ui->afficherPersonnes,&AfficherPersonnes::afficherPersonne,this,&PersonneMapViewer<T,ViewerType>::afficherPersonne);
}

template <class T,class ViewerType> void PersonneMapViewer<T,ViewerType>::afficherPersonne(QString personne)
{
    mViewer->setModel(new SignalListAdapter<T>(mPersonneMap->getList(personne)));
}


template <class T,class ViewerType> PersonneMapViewer<T,ViewerType>::~PersonneMapViewer()
{
    delete ui;
}


#endif // PERSONNEMAPVIEWER_HXX
