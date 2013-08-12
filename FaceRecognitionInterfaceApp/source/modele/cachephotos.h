#ifndef CACHEPHOTOS_H
#define CACHEPHOTOS_H

#include <QString>
#include <QPixmap>
#include <QMap>

/**
 * @brief La classe CachePhotos permet de s'affranchir du stockage des photos : dans les autres classes du modèles on se contente de stocker le chemin, c'est seulement lors de l'affichage qu'on récupère les vraies images via cette classe (sans les recharges à chaque fois grace à la qmap)
 */
class CachePhotos
{
public:
    /**
     * @brief getPhoto récupère la photo associé à un chemin (si elle n'est pas stocké alors on la crée)
     * @param chemin chemin d'une photo
     * @return l'image voulue
     */
    static void getPhoto(QString chemin,QPixmap & pm);

};

#endif // CACHEPHOTOS_H
