#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProgressDialog>
#include "modele/photos.h"
#include "adapteur/qstringsignallistadapter.h"
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
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setAdapterIdentificationNonReconnues(IdentificationSignalListAdapter * adapter);
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
    PersonneMapViewer<Identification*,AfficherIdentifications,IdentificationSignalListAdapter> * mIdentificationsNonValideesViewer;
    PersonneMapViewer<Identification*,AfficherIdentifications,IdentificationSignalListAdapter> * mIdentificationsDeViewer;
    PersonneMapViewer<Photo*,AfficherPhotos,PhotoSignalListAdapter> * mPhotosDeViewer;
};

#endif // MAINWINDOW_H
