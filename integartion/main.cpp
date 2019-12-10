#include "mainwindow.h"

#include <QApplication>
#include "connexion.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Connexion c;
    bool test=c.ouvrirConnexion();
    if(test)
    {
    w.show();
    }
    return a.exec();
}
