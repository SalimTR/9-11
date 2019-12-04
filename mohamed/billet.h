#ifndef BILLET_H
#define BILLET_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class billet
{  int code;
   QString date;
   QString destination;
public:

    billet();
    billet(int,QString,QString);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
   QSqlQueryModel * trier();
    bool modifier(int,QString,QString);
};

#endif
