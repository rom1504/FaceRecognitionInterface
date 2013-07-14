#include "identificationeditor.h"
#include "ui_identificationeditor.h"

#include <QTimer>
#include <QDebug>
#include <QCompleter>

QStringSignalListAdapter * IdentificationEditor::mPersonnes;

IdentificationEditor::IdentificationEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IdentificationEditor),
    mIdentification(nullptr)
{
    ui->setupUi(this);
}

Identification * IdentificationEditor::getIdentification() const
{
    return mIdentification;
}

void IdentificationEditor::setIdentification(Identification * identification)
{
    mIdentification=identification;
    ui->pushButtonInvalider->hide();
    ui->pushButtonValider->hide();
    ui->lineEditPersonne->hide();
    ui->pushButtonIdentifier->hide();
    if(!mIdentification->valide() && mIdentification->identifie())
    {
        connect(ui->pushButtonValider,&QPushButton::clicked,mIdentification,&Identification::valider);
        connect(ui->pushButtonInvalider,&QPushButton::clicked,mIdentification,&Identification::invalider);
        ui->pushButtonInvalider->show();
        ui->pushButtonValider->show();
    }
    if(!mIdentification->valide() && !mIdentification->identifie())
    {
        ui->pushButtonIdentifier->show();
        ui->lineEditPersonne->show();
        QCompleter * completer=new QCompleter(mPersonnes);
        completer->setCaseSensitivity(Qt::CaseInsensitive);
        ui->lineEditPersonne->setCompleter(completer);
        connect(ui->pushButtonIdentifier,&QPushButton::clicked,this,&IdentificationEditor::identifier);
        connect(ui->lineEditPersonne,&QLineEdit::returnPressed,this,&IdentificationEditor::identifier);
        QTimer::singleShot(0, ui->lineEditPersonne, SLOT(setFocus()));
    }
}

void IdentificationEditor::identifier()
{
    mIdentification->identifier(ui->lineEditPersonne->text());
    mIdentification->valider();// ou intégrer dans le modèle ? je pense que ça va comme ça ... : y réfléchir
}

IdentificationEditor::~IdentificationEditor()
{
    delete ui;
}
