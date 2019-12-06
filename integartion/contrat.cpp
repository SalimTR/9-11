#include "contrat.h"
#include "avion.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDate>
class contratData : public QSharedData
{
public:

};

Contrat::Contrat()
{
id=0;
date=QDate::currentDate();
nom_societe="";
matricule="";

}
Contrat::Contrat(int id,QDate date,QString nom_societe,QString matricule)

{
this->id=id;
this->date=date;
this->nom_societe=nom_societe;
this->matricule=matricule;

}


Contrat &Contrat::operator=(const Contrat &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

Contrat::~Contrat()
{



}

bool Contrat::ajouter()
{

    QSqlQuery query;
    //QString res=QString::number(mat);
    query.prepare("INSERT INTO contrat (id,date,nom_societe,matricule) VALUES (:id,:date,:nom_societe,:matricule)");
    query.bindValue(":id",id);
    query.bindValue(":date",date);
    query.bindValue(":nom_societe",nom_societe);
    query.bindValue(":matricule",matricule);
    return query.exec();



}
bool Contrat::supprimer(int id)
{

    QSqlQuery query;
    query.prepare("DELETE * FROM contrat WHERE id = :id");
    query.bindValue(":id",id);
    return query.exec();


}
bool modifier(int id,QDate date,QString nom_societe,QString matricule,int id_modif)
{
    QSqlQuery query;
   query.prepare("update contrat set id=:id,date=:date,nom_societe=:nom_societe,matricule=:matricule where id=:id_modif");
   query.bindValue(":id",id);
   query.bindValue(":date",date);
   query.bindValue(":nom_societe",nom_societe);
   query.bindValue(":matricule",matricule);
   query.bindValue(":id_modif",id_modif);
   return query.exec();

}
QSqlQueryModel * Contrat::afficher()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from contrat");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("date"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("nom_societe"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("matricule"));

    return model;


}
