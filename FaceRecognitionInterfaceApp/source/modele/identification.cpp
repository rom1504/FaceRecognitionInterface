#include "identification.h"

#include <QStringList>
#include <QDebug>

Identification::Identification(double x, double y, double w, double h, QString nomFichierDecoupee, Photo *photoAssocie, QString personne, bool valide, bool ignore, QObject *parent) :
    QObject(parent),
    mRect(x,y,w,h),
    mNomFichierDecoupee(nomFichierDecoupee),
    mPersonne(personne),
    mValide(valide),
    mIgnore(ignore),
    mPhotoAssocie(photoAssocie)
{
    joindre();
}

Identification::Identification(QString chaine,Photo *photoAssocie,QObject * parent) : QObject(parent)
{

    QStringList sections(chaine.trimmed().split("\t"));
    mRect=QRect(sections[0].toInt(),sections[1].toInt(),sections[2].toInt(),sections[3].toInt());
    mNomFichierDecoupee=sections.size()>4 ? sections[4] : "";
    mPersonne=sections.size()>5 ? sections[5] : "";
    mValide=sections.size()>6 ? (sections[6]=="1" ? true : false) : false;
    mIgnore=sections.size()>7 ? (sections[7]=="1" ? true : false) : false;
    mPhotoAssocie=photoAssocie;
    joindre();
}

void Identification::joindre()
{
    connect(this,&Identification::sidentifie,this,&Identification::modifie);
    connect(this,&Identification::svalide,this,&Identification::modifie);
    connect(this,&Identification::sinvalide,this,&Identification::modifie);
    connect(this,&Identification::signore,this,&Identification::modifie);
}


bool Identification::containsPoint(QPoint p) const
{
    return mRect.contains(p);
}

QRect Identification::rect() const
{
    return mRect;
}

QString Identification::nomFichierDecoupee() const
{
    return mNomFichierDecoupee;
}

QString Identification::personne() const
{
    return mPersonne;
}

bool Identification::identifie() const
{
    return mPersonne!="";
}


bool Identification::valide() const
{
    return mValide;
}

bool Identification::ignore() const
{
    return mIgnore;
}

void Identification::identifier(QString personne)
{
    mPersonne=personne;
    emit sidentifie();
}


void Identification::invalider()
{
    mValide=false;
    emit sinvalide();
    mPersonne="";
}

void Identification::valider()
{
    mValide=true;
    emit svalide();
}

Photo * Identification::photoAssocie() const
{
    return mPhotoAssocie;
}

void Identification::ignorer()
{
    mIgnore=true;
    emit signore();
}


QString Identification::toQString() const
{
    QString tab=QString("\t");
    return QString::number(mRect.left())+tab+QString::number(mRect.top())+tab+QString::number(mRect.width())+tab+QString::number(mRect.height())+tab+mNomFichierDecoupee+tab+mPersonne+tab+(mValide ? "1" : "0")+tab+(mIgnore ? "1" : "0");
}
