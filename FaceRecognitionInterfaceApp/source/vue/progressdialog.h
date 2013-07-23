#ifndef PROGRESSDIALOG_H
#define PROGRESSDIALOG_H

#include <QDialog>
#include <QElapsedTimer>

namespace Ui {
class ProgressDialog;
}

class ProgressDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ProgressDialog(QString title,QString description,int minimum,int maximum,int value,QWidget *parent = 0);
    void setValue(int value);
    double value() const;
    void setMinimum(int minimum);
    void setMaximum(int maximum);
    int maximum() const;
    int minimum() const;
    void start();
    void end();
    ~ProgressDialog();

private:
    void updateETA();
    
private:
    Ui::ProgressDialog *ui;
    QElapsedTimer mSinceBegining;

};

#endif // PROGRESSDIALOG_H
