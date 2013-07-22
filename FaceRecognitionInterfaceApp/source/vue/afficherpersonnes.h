#ifndef AFFICHERPERSONNES_H
#define AFFICHERPERSONNES_H

#include <QWidget>
#include "adapter/qstringsignallistadapter.h"

namespace Ui {
class AfficherPersonnes;
}

class AfficherPersonnes : public QWidget
{
    Q_OBJECT
    
public:
    explicit AfficherPersonnes(QWidget *parent = 0);
    ~AfficherPersonnes();

    void setModel(SignalListAdapter<QString> *qstringSignalListAdapter);

signals:
    void afficherPersonne(QString personne);

private slots:
    void afficherPersonneCourante();
    
private:
    Ui::AfficherPersonnes *ui;
};

#endif // AFFICHERPERSONNES_H
