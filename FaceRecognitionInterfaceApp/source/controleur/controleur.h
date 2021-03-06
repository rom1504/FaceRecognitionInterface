#ifndef CONTROLEUR_H
#define CONTROLEUR_H

#include <QObject>
#include "vue/mainwindow.h"
#include "modele/photos.h"
#include "modele/cachephotos.h"

class Controleur : public QObject
{
    Q_OBJECT
public:
    explicit Controleur(QObject *parent = 0);

    void run();
    
signals:
    
public slots:
    
private:
    MainWindow * mMainWindow;
    Photos * mPhotos;
    QString mPersonne;

};

#endif // CONTROLEUR_H
