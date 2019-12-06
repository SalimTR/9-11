#include "billet.h"
#include <QDebug>
#include <QDate>
billet::billet()
{
    code=0;
    date=QDate::currentDate();
    destination="";

}

billet::billet(int code,QDate date,QString destination)
{
this->code=code;
this->date=date;
this->destination=destination;
}
bool billet::ajouter()
{
QSqlQuery query;
QString res1= QString::number(code);
query.prepare("INSERT INTO billet (code, date_d, destination) "
                    "VALUES (:code, :date, :destination)");
query.bindValue(":code", res1);
query.bindValue(":date", date);
query.bindValue(":destination", destination);

return    query.exec();
}

QSqlQueryModel * billet::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from billet");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("code"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("dates "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("destination"));
    return model;
}

bool billet::supprimer(int code)
{
QSqlQuery query;
QString res= QString::number(code);
query.prepare("Delete from billet where code = :code ");
query.bindValue(":code", res);
return    query.exec();
}

bool billet::modifier(int code,QDate date,QString destination)
{
    QSqlQuery query;
    QString res= QString::number(code);
    query.prepare("update billet set date_d=:date,destination=:destination where code=:code");
    query.bindValue(":code", res);
    query.bindValue(":date", date);
    query.bindValue(":destination", destination);

    return    query.exec();
}

QSqlQueryModel * billet::trier()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from billet order by code");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("code"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("dates "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("destination"));
    return model;
}
