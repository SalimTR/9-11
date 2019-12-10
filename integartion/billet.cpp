#include "billet.h"
#include <QDebug>
#include <QDate>
billet::billet()
{
    code=0;
    date="";
    destination="";

}

billet::billet(int code,QString date,QString destination)
{
this->code=code;
this->date=date;
this->destination=destination;
}
bool billet::ajouter()
{
QSqlQuery query;
QString res1= QString::number(code);
query.prepare("INSERT INTO billets (code, date_d, destination) "
                    "VALUES (:code, :date, :destination)");
query.bindValue(":code", res1);
query.bindValue(":date", date);
query.bindValue(":destination", destination);

return    query.exec();
}

QSqlQueryModel * billet::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from billets");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("code"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("dates "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("destination"));
    return model;
}

bool billet::supprimer(int code)
{
QSqlQuery query;
query.prepare("Delete from billets where code = :code ");
query.bindValue(":code", code);
return    query.exec();
}

bool billet::modifier(int code,QString date,QString destination)
{
    QSqlQuery query;
    query.prepare("update billets set date_d=:date,destination=:destination where code=:code");
    query.bindValue(":code", code);
    query.bindValue(":date", date);
    query.bindValue(":destination", destination);

    return    query.exec();
}

QSqlQueryModel * billet::trier()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from billets order by code");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("code"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("dates "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("destination"));
    return model;
}
