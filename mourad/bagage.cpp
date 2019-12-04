#include "bagage.h"
#include <QSqlQuery>
#include <QVariant>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QTableView>

Bagage::Bagage()
{
    idVoy =0;
    code =0;
    poids ="";
}

Bagage::Bagage(int idVoy, int code, QString poids)
{
    this->idVoy =idVoy;
    this->code =code;
    this->poids =poids;
}

bool Bagage::ajouter()
{
    QSqlQuery query;
    QString res1=QString::number(idVoy);
    QString res2=QString::number(code);

          query.prepare("INSERT INTO bagage (idvoy, code, poids) "
                        "VALUES (:idVoy,:code,:poids)");
          query.bindValue(":idVoy", res1);
          query.bindValue(":code", res2);
          query.bindValue(":poids", poids);

          return query.exec();
}

QSqlQueryModel* Bagage::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from bagage");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idVoy"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("code"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("poids"));
    return  model;
}

void Bagage::supprimer(int code)
{
    QSqlQuery query;
    query.prepare("DELETE FROM bagage WHERE code=:code");
    QString res2=QString::number(code);
    query.bindValue(":code", res2);
    query.exec();
}

bool Bagage :: modifier()
{
    QSqlQuery query;
    QString res1=QString::number(idVoy);
         query.prepare("UPDATE bagage SET code=:modifcodeb, poids=:modifpoids WHERE idVoy =:modifidVoy;");
         query.bindValue(":modifidVoy",idVoy);
         query.bindValue(":lodifcodeb",res1);
         query.bindValue(":modifpoids",poids);
         return query.exec();
}

QSqlQueryModel * Bagage :: trierpoids()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from bagage ORDER BY poids");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("poids"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("idVoy"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("code"));
    return model;
}

void Bagage::clearTable(QTableView *table)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->clear();
    table->setModel(model);
}

void Bagage::searchRegexp(QTableView *table, QString x)
{
   QSqlQueryModel *model=new QSqlQueryModel();
   QSqlQuery *query =new QSqlQuery;
   query->prepare("select * from bagage where regexp_like(code,:code);");
   query->bindValue(":code",x);

   if(x==0)
   {
       qDebug("tawa 0");
       query->prepare("select * from bagage;");
   }
   query->exec();
   model->setQuery(*query);
   table->setModel(model);
   table->show();
}

bool Bagage:: recherche(int code)
{
    QSqlQuery query;
    query.prepare("select * from bagage where code=:code");
    query.bindValue(":code",code);
    return query.exec() ;
}
