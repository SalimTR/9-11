#ifndef EMPLOYES_H
#define EMPLOYES_H
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>

class Employes
{
    int cin;
    QString nom;
    QString prenom;
    int age;
    int tel;
    QString adresse;
    QString departement;
public:
    Employes();
    Employes(int,QString,QString,int,int,QString,QString);
    int get_cin();
    QString get_nom();
    QString get_prenom();
    int get_age();
    int get_tel();
    QString get_adresse();
    QString get_departement();
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int);
    bool modifier(int,QString,QString,int,int,QString,QString);
    QSqlQueryModel * trier(QString);
    QSqlQueryModel * rechercher(QString);
};

#endif // EMPLOYES_H
