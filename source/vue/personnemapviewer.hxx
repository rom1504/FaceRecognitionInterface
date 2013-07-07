#ifndef PERSONNEMAPVIEWER_HXX
#define PERSONNEMAPVIEWER_HXX

#include "personnemapviewer.h"
#include "ui_personnemapviewer.h"
#include "vue/afficherpersonnes.h"
#include "adapteur/qstringsignallistadapter.h"

template <class T,class ViewerType,class ModelType> PersonneMapViewer<T,ViewerType,ModelType>::PersonneMapViewer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PersonneMapViewer),
    mViewer(new ViewerType())
{
    ui->setupUi(this);
    ui->horizontalLayout->addWidget(mViewer);
    ui->horizontalLayout->setStretch(1,1);
    ui->horizontalLayout->setStretch(2,1);
}

template <class T,class ViewerType,class ModelType> void PersonneMapViewer<T,ViewerType,ModelType>::setModel(PersonneMap<T> * personneMap)
{
    mPersonneMap=personneMap;
    ui->afficherPersonnes->setModel(new QStringSignalListAdapter(mPersonneMap->getPersonnes()));
    connect(ui->afficherPersonnes,&AfficherPersonnes::afficherPersonne,[this](QString personne)
    {
        mViewer->setModel(new ModelType(mPersonneMap->getList(personne)));
    });
}

template <class T,class ViewerType,class ModelType> PersonneMapViewer<T,ViewerType,ModelType>::~PersonneMapViewer()
{
    delete ui;
}


#endif // PERSONNEMAPVIEWER_HXX
