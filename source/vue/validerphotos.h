#ifndef ValiderPhotos_H
#define ValiderPhotos_H

#include <QWidget>
#include "modele/modelevaliderphotos.h"

namespace Ui {
class ValiderPhotos;
}

class ValiderPhotos : public QWidget
{
    Q_OBJECT
    
public:
    explicit ValiderPhotos(QWidget *parent = 0);
    ~ValiderPhotos();

    void setModel(ModeleValiderPhotos * modeleValiderPhotos);

signals:
    void valider(QList<bool> valides);

private:
    Ui::ValiderPhotos *ui;
    ModeleValiderPhotos * mModeleValiderPhotos;
};

#endif // ValiderPhotos_H
