#ifndef IDENTIFICATIONEDITOR_H
#define IDENTIFICATIONEDITOR_H

#include <QWidget>

#include "modele/identification.h"
#include "adapter/qstringsignallistadapter.h"

namespace Ui {
class IdentificationEditor;
}

class IdentificationEditor : public QWidget
{
    Q_OBJECT
    
public:
    explicit IdentificationEditor(QWidget *parent = 0);

    Q_PROPERTY(Identification* enum READ getIdentification WRITE setIdentification USER true)

    Identification * getIdentification() const;
    void setIdentification(Identification * identification);
    static SignalListAdapter<QString> * mPersonnes;// comment changer ça ?

    ~IdentificationEditor();

private:
    void identifier();
    
private:
    Ui::IdentificationEditor *ui;
    Identification * mIdentification;
};

#endif // IDENTIFICATIONEDITOR_H
