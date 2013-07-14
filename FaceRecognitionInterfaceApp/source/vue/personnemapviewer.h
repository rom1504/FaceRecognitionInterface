#ifndef PERSONNEMAPVIEWER_H
#define PERSONNEMAPVIEWER_H

#include <QWidget>

#include "modele/personnemap.h"

namespace Ui {
class PersonneMapViewer;
}


// hum ça devient moche... voir pour limiter l'utilisation des templates...q
template <class T,class ViewerType,class ModelType> class PersonneMapViewer : public QWidget
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
