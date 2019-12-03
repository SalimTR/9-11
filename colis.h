#ifndef COLIS_H
#define COLIS_H
#include <QString>
#include <QSqlQueryModel>
#include <QDate>
#include <QTableView>

class colis
{
    int code;
    QString pays ;
    QString ville ;
    QDate datec ;
    QString type;
public:
    colis();
    colis(int, QString, QString, QDate, QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    void supprimer(int code);
    bool modifier();
    QSqlQueryModel* trierdate();
    void clearTable(QTableView* table);
    void searchRegexp(QTableView *table, QString x);
    int nombreCategorie1();
    int nombreCategorie2();
    int nombreCategorie3();
    int nombreCategorie4();
    int nombreCategorie5();
    int nombreCategorie6();

    ~colis(){};
};

#endif // COLIS_H
