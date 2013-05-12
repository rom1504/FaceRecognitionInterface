#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "modele/photos.h"
#include "modele/modeleafficherphotos.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    void setModel(Photos * photos);


    ~MainWindow();


private:
    void setModelPremieresPhotos();
    void precedent();
    
private:
    Ui::MainWindow *ui;
    Photos * mPhotos;
    ModeleAfficherPhotos * mModeleAfficherPhotos;
    QString mPersonne;
    // il faut vraiment faire un widget AfficherListePhotos et un widget AfficherListePersonne ...
};

#endif // MAINWINDOW_H
