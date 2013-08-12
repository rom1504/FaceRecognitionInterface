#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProgressDialog>
#include "modele/photos.h"
#include "adapter/qstringsignallistadapter.h"
#include "adapteur/identificationsignallistadapter.h"
#include "adapteur/photosignallistadapter.h"
#include "vue/afficheridentifications.h"
#include "vue/afficherphotos.h"
#include "vue/personnemapviewer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QString cheminPhotos,QString cheminPhotoDecoupees,QString cheminInformation,QString cheminIntermediaire,QString cheminModele,QWidget *parent = 0);
    ~MainWindow();

    void setAdapterIdentificationNonReconnues(SignalListAdapter<Identification*> * adapter);
    void setAdapterIdentificationNonValidees(PersonneMap<Identification*> * adapter);
    void setAdapterPhotoDe(PersonneMap<Photo*> * adapter);
    void setAdapterIdentificationDe(PersonneMap<Identification*> * adapter);

    void run();

signals:
    void verifierReconnaissance();
    void reloadPhotos();

private:
    void detect();
    void recognize();
    
private:
    Ui::MainWindow *ui;
    PersonneMapViewer<Identification*,AfficherIdentifications> * mIdentificationsNonValideesViewer;
    PersonneMapViewer<Identification*,AfficherIdentifications> * mIdentificationsDeViewer;
    PersonneMapViewer<Photo*,AfficherPhotos> * mPhotosDeViewer;
    QString mCheminPhotos;
    QString mCheminPhotoDecoupees;
    QString mCheminInformation;
    QString mCheminIntermediaire;
    QString mCheminModele;
};

#endif // MAINWINDOW_H
