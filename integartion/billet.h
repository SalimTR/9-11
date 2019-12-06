#ifndef BILLET_H
#define BILLET_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class billet
{  int code;
   QDate date;
   QString destination;
public:

    billet();
    billet(int,QDate,QString);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    QSqlQueryModel * trier();
    bool modifier(int,QDate,QString);
};

#endif
