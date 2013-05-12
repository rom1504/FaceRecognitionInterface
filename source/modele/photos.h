#ifndef PHOTOS_H
#define PHOTOS_H

#include <QObject>
#include <QList>
#include <QMap>
#include <functional>
#include "photo.h"

class Photos : public QObject
{
    Q_OBJECT
public:
    explicit Photos(QObject *parent = 0);
    const QList<QString> & personnes() const;
    void ajouterPhoto(QString nomFichier, QString personne,QString dossier);
    void chargerPhotos(QString dossier,std::function<bool(QString)> filtre=[](QString){return true;});
    const QList<Photo *> photosDe(QString personne) const;
    
signals:
    void beginRemoveRows(int debut,int fin);
    void endRemoveRows();
    
public slots:


protected:
    QMap<QString,QList<Photo*> > mPhotos;
    QStringList mPersonnes;
    
};

#endif // PHOTOS_H
