#ifndef IDENTIFICATION_H
#define IDENTIFICATION_H

#include <QString>
#include <QObject>
//#include "photo.h"
class Photo;

// est ce que cette classe devrait référencer où on a trouver cette identification ?

/**
 * @brief La classe Identification stocke une identification : un rectangle, un fichier image découpée, une personne et des booléens pour savoir si la reconnaissance est validé ou bien si on ignore cette identification (on essaye pas de la reconnaitre : de déterminer sa personne)
 */
class Identification : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Identification constructeur normal : copie simplement les variables dans leurs attributs
     * @param x position en x
     * @param y position en y
     * @param w largeur
     * @param h hauteur
     * @param nomFichierDecoupee nom de l'image decoupée
     * @param personne personne reconnue
     * @param valide si la reconnaissance est valide ou non
     * @param ignore si on ignore la reconnaissance
     * @param photoAssocie photo qui contient l'identification
     */
    Identification(double x,double y,double w,double h,QString nomFichierDecoupee,Photo *photoAssocie,QString personne="",bool valide=false,bool ignore=false,QObject * parent=0);
    /**
     * @brief Identification constructeur à partir d'une chaine tirée du fichier .jpg.txt (dossier information)
     * @param chaine sous la forme x y w h nomFichierDeocupee personne valide ignore
     * @param photoAssocie photo qui contient l'identification
     */
    Identification(QString chaine,Photo *photoAssocie,QObject * parent=0);

    void joindre();

    /**
     * @brief identifier permet d'identifier une personne
     * @param personne nom de la personne
     */
    void identifier(QString personne);
    /**
     * @brief valider permet de valider la reconnaissance
     */
    void valider();
    /**
     * @brief invalider permet d'invalider la reconnaissance
     */
    void invalider();
    /**
     * @brief ignorer permet d'ignorer cette identification
     */
    void ignorer();
    /**
     * @brief personne personne identifié
     * @return  nom personne
     */
    QString personne() const;
    /**
     * @brief identifie est ce identifie
     * @return true si oui
     */
    bool identifie() const;
    /**
     * @brief valide est valide
     * @return true si oui
     */
    bool valide() const;
    /**
     * @brief ignore est ignore
     * @return true si oui
     */
    bool ignore() const;

    /**
     * @brief toQString permet d'exporter sous la forme x y w h nomFichierDeocupee personne valide ignore
     */
    QString toQString() const;
    /**
     * @brief photoAssocie photo associé à cette identification
     * @return un pointeur vers cette photo
     */
    Photo * photoAssocie() const;

    QString nomFichierDecoupee() const;

signals:
    /**
     * @brief modifie vient d'etre modifie
     */
    void modifie();
    /**
     * @brief signore vient d'etre ignore
     */
    void signore();
    /**
     * @brief svalide vient d'etre valide
     */
    void svalide();
    /**
     * @brief sinvalide vient d'etre invalide
     */
    void sinvalide();
    /**
     * @brief sidentifie vient d'etre identifie
     */
    void sidentifie();

private:
    /**
     * @brief mX position en x
     */
    double mX;
    /**
     * @brief mY position en y
     */
    double mY;
    /**
     * @brief mW largeur
     */
    double mW;
    /**
     * @brief mH hauteur
     */
    double mH;
    /**
     * @brief mNomFichierDecoupee nom du fichier découpé
     */
    QString mNomFichierDecoupee;
    /**
     * @brief mPersonne personne reconnue (peut etre nul)
     */
    QString mPersonne;
    /**
     * @brief mValide reconnaissance validé ou non
     */
    bool mValide;
    /**
     * @brief mIgnore identification ignorée ou non
     */
    bool mIgnore;
    /**
     * @brief mPhotoAssocie la photo qui contient cette identification
     */
    Photo * mPhotoAssocie;

};

#endif // IDENTIFICATION_H
