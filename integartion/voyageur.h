#ifndef VOYAGEUR_H
#define VOYAGEUR_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class voyageur
{QString cin;
    QString tel;
    QString nom;
    QString prenom;

public:

    voyageur();
    voyageur(QString,QString,QString,QString);
    QString getcin(){return cin;}
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel *chercher(QString cin);

    bool supprimer(QString);
    bool modifier(QString,QString,QString,QString);
    ~voyageur(){}

};

#endif // VOYAGEUR_H
