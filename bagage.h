#ifndef BAGAGE_H
#define BAGAGE_H
#include <QString>
#include <QTableView>
#include <QSqlQueryModel>
#include <QTableView>

class Bagage
{
    int idVoy ;
    int code;
    QString poids;
public:
    Bagage();
    Bagage(int, int, QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    void supprimer(int code);
    bool modifier();
    QSqlQueryModel* trierpoids();
    void clearTable(QTableView* table);
    void searchRegexp(QTableView *table, QString x);
    bool recherche(int code);
    ~Bagage(){};
};

#endif // BAGAGE_H
