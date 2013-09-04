#ifndef PHOTOVIEWER_H
#define PHOTOVIEWER_H

#include <QLabel>

#include "modele/photo.h"

class PhotoViewer : public QLabel
{
    Q_OBJECT
public:
    explicit PhotoViewer(QWidget *parent = 0);
    void setPhoto(Photo* photo);

protected:
    void mouseMoveEvent(QMouseEvent * event);
    void paintEvent(QPaintEvent * event);

private:
    QRect resizedRect(QRect rect) const;
    QPoint resizedPoint(QPoint p) const;
    
private:
    Photo* mPhoto;
    double mFx;
    double mFy;
    Identification* mCurrentIdentification;
    
};

#endif // PHOTOVIEWER_H
