#include "identification.h"

#include <QStringList>
#include <QDebug>

Identification::Identification(double x, double y, double w, double h, QString nomFichierDecoupee, Photo *photoAssocie, QString personne, bool valide, bool ignore, QObject *parent) :
    QObject(parent),
    mX(x),
    mY(y),
    mW(w),
    mH(h),
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
    mX=sections[0].toDouble();
    mY=sections[1].toDouble();
    mW=sections[2].toDouble();
    mH=sections[3].toDouble();
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
    return QString::number(mX)+tab+QString::number(mY)+tab+QString::number(mW)+tab+QString::number(mH)+tab+mNomFichierDecoupee+tab+mPersonne+tab+(mValide ? "1" : "0")+tab+(mIgnore ? "1" : "0");
}
