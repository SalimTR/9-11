#ifndef CONTRAT_H
#define CONTRAT_H

#include <QMainWindow>
#include <QObject>
#include <QSharedDataPointer>
#include <QWidget>
#include <QSqlQueryModel>
#include <QDate>
class contratData;

class Contrat
{
public:
    Contrat();
    Contrat(int,QDate,QString,QString);

    Contrat &operator=(const Contrat &);
    ~Contrat();
     bool ajouter();
     bool supprimer(int id);
     bool modifier(int id,QDate date,QString nom_societe,QString matricule,int id_modif);
     QSqlQueryModel * afficher();


private:
    QSharedDataPointer<contratData> data;
    int id;
    QDate date;
    QString nom_societe;
    QString matricule;
};

#endif // CONTRAT_H
