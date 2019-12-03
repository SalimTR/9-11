#include "mainwindowbc.h"
#include <QMessageBox>
#include "connection.h"
#include <QApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    MainWindowBC w;

    try {c.createconnect();
        w.show();
    } catch (QString s)
    {qDebug()<<s;}

    return a.exec();


}







