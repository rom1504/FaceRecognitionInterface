#ifndef PERSONNEMAPVIEWER_H
#define PERSONNEMAPVIEWER_H

#include <QWidget>

#include "modele/personnemap.h"

namespace Ui {
class PersonneMapViewer;
}


// voir pour enlever aussi le ViewerType (faire un viewer générique spécialisé dans les 3 types voulus)
template <class T,class ViewerType> class PersonneMapViewer : public QWidget
{
public:
    explicit PersonneMapViewer(QWidget *parent = 0);
    void setModel(PersonneMap<T> * personneMap);
    ~PersonneMapViewer();

private:
    void afficherPersonne(QString personne);
    
private:
    Ui::PersonneMapViewer *ui;
    PersonneMap<T> * mPersonneMap;
    ViewerType * mViewer;

};

#include "personnemapviewer.hxx"

#endif // PERSONNEMAPVIEWER_H
