#include "controleur/controleur.h"
#include <QApplication>
#include <QTranslator>
#include <QLibraryInfo>
#include <QDebug>

//#define LANG "en"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString locale = QLocale::system().name();
//    locale=LANG;
    QLocale::setDefault(QLocale(locale));

    QTranslator qtTranslator;
    qtTranslator.load("qt_" + locale,QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    QApplication::installTranslator(&qtTranslator);


    QTranslator translator;
    translator.load(QString(":/translation/FaceRecognitionInterface_") + locale);
    QApplication::installTranslator(&translator);

    Controleur c;
    c.run();

    return a.exec();
}
