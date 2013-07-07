#include "cachephotos.h"

CachePhotos::CachePhotos()
{
}


QPixmap & CachePhotos::getPhoto(QString chemin)
{
    if(!mPhotos.contains(chemin)) mPhotos[chemin]=QPixmap(chemin);
    return mPhotos[chemin];
}
