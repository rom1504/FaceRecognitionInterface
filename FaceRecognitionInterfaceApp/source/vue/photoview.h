#ifndef PHOTOVIEW_H
#define PHOTOVIEW_H

#include <QWidget>
#include <QAbstractItemModel>

namespace Ui {
class PhotoView;
}

class PhotoView : public QWidget
{
    Q_OBJECT
    
public:
    explicit PhotoView(QWidget *parent = 0);
    void setModel(QAbstractItemModel * adapter);
    void viewPhoto(int num);
    ~PhotoView();

signals:
    void up();
    
private:
    Ui::PhotoView *ui;
    QAbstractItemModel * mAdapter;
    int mCurrent;
};

#endif // PHOTOVIEW_H
