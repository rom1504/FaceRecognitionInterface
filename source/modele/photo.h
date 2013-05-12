#ifndef PHOTO_H
#define PHOTO_H

#include <QObject>
#include <QPixmap>

class Photo : public QObject
{
    Q_OBJECT
public:
    explicit Photo(QString nomFichier, QString personne,QString dossier="sortie", QObject *parent = 0);
    
    const QPixmap & image() const;
    const QString nomFichier() const;

signals:
    
public slots:

private:
    QString mNomFichier;
    QPixmap mImage;
    
};

#endif // PHOTO_H
