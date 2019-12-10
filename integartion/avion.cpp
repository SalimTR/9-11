#include "avion.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "mainwindow.h"

avion::avion()
{
mat="";
comp="";
model="";
}

avion::avion(QString mat,QString comp,QString model )
{
this->mat=mat;
this->comp=comp;
this->model=model;
}


QString avion::get_matricule()
{

    return this->mat;
}
QString avion::get_compagne()
{
    return this->comp;

}
QString avion::get_model()
{
    return this->model;

}

bool avion::ajouter()
{
    QSqlQuery query;
    //QString res=QString::number(mat);
    query.prepare("INSERT INTO avions (matricule,compagne,model) VALUES (:mat,:comp,:model)");
    query.bindValue(":mat",mat);
    query.bindValue(":comp",comp);
    query.bindValue(":model",model);
    return query.exec();

}
QSqlQueryModel * avion::afficher()
{
   QSqlQueryModel * model=new QSqlQueryModel();
   model->setQuery("select * from avions");
   model->setHeaderData(0,Qt::Horizontal,QObject::tr("matricule"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("compagne"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("model"));
   return model;



}
QSqlQueryModel * avion::trier()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from avions order by matricule asc");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("matricule"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("compagne"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("model"));
return model;

}


bool avion::supprimer(QString mat)
{
    QSqlQuery query;
    //QString res=QString::number(mat);
    query.prepare("DELETE  FROM avions WHERE matricule = :mat");
    query.bindValue(":mat",mat);
    return query.exec();

}
bool avion::modifier(QString mat,QString comp,QString model,QString mat_modif)
{
     QSqlQuery query;
    query.prepare("update AVIONS set matricule=:mat,compagne=:comp,model=:model where matricule=:mat_modif");
    query.bindValue(":mat",mat);
    query.bindValue(":comp",comp);
    query.bindValue(":model",model);
    query.bindValue(":mat_modif",mat_modif);
    return query.exec();

}


QSqlQueryModel * avion::statistic()
{
    QSqlQueryModel * model=new QSqlQueryModel();
       model->setQuery("select compagne,(count(compagne)*100/ (select count(*)from avions)) as pourcentage from avions group by compagne");
       model->setHeaderData(0,Qt::Horizontal,QObject::tr("compagne"));
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("percentage"));
       return model;


}
