#ifndef AFFICHERPERSONNES_H
#define AFFICHERPERSONNES_H

#include <QWidget>
#include "adapteur/qstringsignallistadapter.h"

namespace Ui {
class AfficherPersonnes;
}

class AfficherPersonnes : public QWidget
{
    Q_OBJECT
    
public:
    explicit AfficherPersonnes(QWidget *parent = 0);
    ~AfficherPersonnes();

    void setModel(QStringSignalListAdapter *qstringSignalListAdapter);

signals:
    void afficherPersonne(QString personne);
    
private:
    Ui::AfficherPersonnes *ui;
};

#endif // AFFICHERPERSONNES_H
