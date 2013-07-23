#include <QDebug>
#include <QTime>

#include "progressdialog.h"
#include "ui_progressdialog.h"



ProgressDialog::ProgressDialog(QString title, QString description, int minimum, int maximum, int value, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProgressDialog)
{
    ui->setupUi(this);
    setWindowTitle(title);
    ui->labelDescription->setText(description);
    ui->progressBar->setMinimum(minimum);
    ui->progressBar->setMaximum(maximum);
    ui->progressBar->setValue(value);
    updateETA();
}

void ProgressDialog::setValue(int value)
{
    ui->progressBar->setValue(value);
    updateETA();
}

QString mSecToQString(int msec)
{
    int s=msec/1000;
    int h=s/3600;
    int m=(s-h*3600)/60;
    s=s-h*3600-m*60;
    return QString::number(h)+":"+QString::number(m)+":"+QString::number(s);
}

void ProgressDialog::updateETA()
{
    double avancement=(double(ui->progressBar->value())-double(ui->progressBar->minimum()))/(double(ui->progressBar->maximum())-double(ui->progressBar->minimum()));
    int msEllapsed=mSinceBegining.elapsed();
    ui->labelTempsEcoule->setText(mSecToQString(msEllapsed));

    int msRestant=avancement==0 ? 0 : msEllapsed*(1/avancement-1);
    ui->labelTempsRestant->setText(mSecToQString(msRestant));
    // j'ai : temps écoulé et avancement (0..1)
    // je veux : temps restant
    // pour ça : temps total
    // temps écoulé = temps total * avancement
    // donc temps total = temps écoulé / avancement
    // temps restant = temps total - temps écoulé
    // temps restant = temps écoulé / avancement -temps écoulé
    // temps restant = temps écoulé (1/avancement -1)
}

double ProgressDialog::value() const
{
    return ui->progressBar->value();
}

void ProgressDialog::setMinimum(int minimum)
{
    ui->progressBar->setMinimum(minimum);
    updateETA();
}

void ProgressDialog::setMaximum(int maximum)
{
    ui->progressBar->setMaximum(maximum);
    updateETA();
}


int ProgressDialog::maximum() const
{
    return ui->progressBar->maximum();
}

int ProgressDialog::minimum() const
{
    return ui->progressBar->minimum();
}

void ProgressDialog::start()
{
    show();
    mSinceBegining.start();
}

void ProgressDialog::end()
{
    hide();
}

ProgressDialog::~ProgressDialog()
{
    delete ui;
}
