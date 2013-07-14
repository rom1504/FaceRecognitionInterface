#include "controleur/controleur.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controleur c;
    c.run();

    return a.exec();
}
