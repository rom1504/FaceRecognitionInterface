#ifndef AFFICHERPHOTOS_H
#define AFFICHERPHOTOS_H

#include <QWidget>
#include "modele/modeleafficherphotos.h"

namespace Ui {
class AfficherPhotos;
}

class AfficherPhotos : public QWidget
{
    Q_OBJECT
    
public:
    explicit AfficherPhotos(QWidget *parent = 0);
    ~AfficherPhotos();
    void setModel(ModeleAfficherPhotos * modeleValiderPhotos);

signals:
    
private:
    Ui::AfficherPhotos *ui;
};

#endif // AFFICHERPHOTOS_H
