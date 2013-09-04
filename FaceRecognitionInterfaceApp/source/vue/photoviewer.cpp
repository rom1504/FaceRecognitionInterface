#include <QDebug>
#include <QToolTip>
#include <QMouseEvent>
#include <QPainter>

#include "photoviewer.h"
#include "modele/cachephotos.h"

PhotoViewer::PhotoViewer(QWidget *parent) :
    QLabel(parent)
{
    setMouseTracking(true);
    mPhoto=nullptr;
}


void PhotoViewer::setPhoto(Photo* photo)
{
    mPhoto=photo;
    QPixmap p;
    CachePhotos::getPhoto(photo->nomFichier()+"_decent",p);
    setPixmap(p);

    QPixmap originalPixmap;
    CachePhotos::getPhoto(mPhoto->nomFichier(),originalPixmap);
    QPixmap resizedPixmap=*pixmap();
    mFx=double(originalPixmap.width())/double(resizedPixmap.width());
    mFy=double(originalPixmap.height())/double(resizedPixmap.height());
    mCurrentIdentification=nullptr;
}

void PhotoViewer::paintEvent(QPaintEvent * event)
{
    QPainter painter(this);
    painter.drawPixmap(pixmap()->rect(),*pixmap());
    painter.setBrush(Qt::NoBrush);
    painter.setPen(Qt::white);
//    for(Identification * identification : mPhoto->identifications())
//    {
//        if(!identification->valide() || identification->ignore()) continue;
//        painter.drawRect(resizedRect(identification->rect()));
//    }
    if(mCurrentIdentification!=nullptr)
    {
        QRect rect=resizedRect(mCurrentIdentification->rect());
//        painter.drawRect(rect);
        double a=double(rect.width())/2.0;
        a*=a;
        double b=double(rect.height())/2.0;
        b*=b;
        double r=sqrt(a+b)/1.2;
        painter.drawEllipse(rect.center(),int(r),int(r));
        QPoint ap=rect.center()+QPoint(-10,double(rect.height())/2.0+25);
        painter.drawText(ap,mCurrentIdentification->personne());
    }
    event->ignore();
}

QPoint PhotoViewer::resizedPoint(QPoint p) const
{
    QPoint ap;
    ap.setX(double(p.x())/mFx);
    ap.setY(double(p.y())/mFy);
    return ap;
}

QRect PhotoViewer::resizedRect(QRect rect) const
{
    QRect rect2;
    rect2.setX(double(rect.x())/mFx);
    rect2.setY(double(rect.y())/mFy);
    rect2.setWidth(double(rect.width())/mFx);
    rect2.setHeight(double(rect.height())/mFy);
    return rect2;
}

void PhotoViewer::mouseMoveEvent(QMouseEvent * event)
{
    if(mPhoto==nullptr)return;
    QPoint pos=event->pos();
    pos.setX(double(pos.x())*mFx);
    pos.setY(double(pos.y())*mFy);
    Identification * identification;
    if((identification=mPhoto->containsPersonAtPoint(pos))==nullptr)
    {
        if(mCurrentIdentification!=nullptr)
        {
            mCurrentIdentification=nullptr;
            repaint();
        }
        return;
    }
    if(mCurrentIdentification==identification) return;
//    QPoint ap=identification->rect().center()+QPoint(0,double(identification->rect().height())/2.0);
//    ap=mapToGlobal(resizedPoint(ap));
//    QToolTip::showText(ap,identification->personne(),this,resizedRect(identification->rect()));
    mCurrentIdentification=identification;
    repaint();
}
