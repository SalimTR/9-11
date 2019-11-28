#ifndef DEPARTEMENT_H
#define DEPARTEMENT_H
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>

class Departement
{
private:
    int id;
    QString nom;
    QString chef;
    int numEmp;
public:
    Departement();
    Departement(int,QString,QString,int);
    int get_id();
    QString get_nom();
    QString get_chef();
    int get_numEmp();
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int);
    bool modifier(int,QString,QString,int);
    QSqlQueryModel *trier(QString);
    QSqlQueryModel *rechercher(QString);
};

#endif // DEPARTEMENT_H
