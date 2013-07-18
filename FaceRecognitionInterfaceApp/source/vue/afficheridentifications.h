#ifndef AFFICHERIDENTIFICATIONS_H
#define AFFICHERIDENTIFICATIONS_H

#include <QWidget>

#include "adapteur/identificationsignallistadapter.h"

namespace Ui {
class AfficherIdentifications;
}

class AfficherIdentifications : public QWidget
{
    Q_OBJECT
    
public:
    explicit AfficherIdentifications(QWidget *parent = 0);
    void setModel(SignalListAdapter<Identification*> * adapter);
    ~AfficherIdentifications();
    
private:
    Ui::AfficherIdentifications *ui;
};

#endif // AFFICHERIDENTIFICATIONS_H
