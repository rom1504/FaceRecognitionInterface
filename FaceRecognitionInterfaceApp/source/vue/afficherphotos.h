#ifndef AFFICHERPHOTOS_H
#define AFFICHERPHOTOS_H

#include <QWidget>
#include <QListView>

#include "adapteur/photosignallistadapter.h"
#include "vue/photoview.h"

namespace Ui {
class AfficherPhotos;
}

class AfficherPhotos : public QWidget
{
    Q_OBJECT
    
public:
    explicit AfficherPhotos(QWidget *parent = 0);
    void setModel(QAbstractItemModel * adapter);
    ~AfficherPhotos();
    
private:
    Ui::AfficherPhotos *ui;
    QListView * mListView;
    PhotoView * mPhotoView;

};

#endif // AFFICHERPHOTOS_H
