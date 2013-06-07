#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProgressDialog>
#include "modele/photos.h"
#include "modele/modelevaliderphotos.h"
#include "modele/modeleafficherpersonne.h"
#include "modele/modeleafficherphotos.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setModelAfficherPersonne(ModeleAfficherPersonne * modeleAfficherPersonne, bool afficherOuValider=true);
    void setModelValiderPhotos(ModeleValiderPhotos * modeleValiderPhotos);
    void setModelAfficherPhotos(ModeleAfficherPhotos * modeleAfficherPhotos);

signals:
    void afficherPersonne(QString personne);
    void validerPersonne(QString personne);
    void validerPhotos(QList<bool> valides);
    void verifierReconnaissance();
    void afficherPhotos();

public slots:
    void finir(int);

    
private:
    Ui::MainWindow *ui;
    bool mAfficherOuValider;
    //QProgressDialog * mProcessDialog;
};

#endif // MAINWINDOW_H
