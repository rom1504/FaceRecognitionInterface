#ifndef AFFICHERPHOTOS_H
#define AFFICHERPHOTOS_H

#include <QWidget>

#include "adapteur/photosignallistadapter.h"

namespace Ui {
class AfficherPhotos;
}

class AfficherPhotos : public QWidget
{
    Q_OBJECT
    
public:
    explicit AfficherPhotos(QWidget *parent = 0);
    void setModel(SignalListAdapter<Photo*> * adapter);
    ~AfficherPhotos();
    
private:
    Ui::AfficherPhotos *ui;
};

#endif // AFFICHERPHOTOS_H
