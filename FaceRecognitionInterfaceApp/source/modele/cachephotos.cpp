#include <QPixmapCache>
#include <QDebug>

#include "cachephotos.h"

void CachePhotos::getPhoto(QString chemin, QPixmap &pm)
{
    if (!QPixmapCache::find(chemin, pm))
    {

        if(chemin.section("_",-1)=="thumb")
        {
            QPixmap photo;
            getPhoto(chemin.section("_",0,-2),photo);
            if(!photo.isNull())
            {
                pm=photo.scaledToWidth(200);
                QPixmapCache::insert(chemin,pm);
            }
        }
        else if(chemin.section("_",-1)=="thumb2")
        {
            QPixmap photo;
            getPhoto(chemin.section("_",0,-2),photo);
            if(!photo.isNull())
            {
                pm=photo.scaledToWidth(160);
                QPixmapCache::insert(chemin,pm);
            }
        }
        else
        {
            pm.load(chemin);
            QPixmapCache::insert(chemin, pm);
        }
    }
}
