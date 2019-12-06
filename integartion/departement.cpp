#include "departement.h"
#include <QDebug>

Departement::Departement()
{
    id=numEmp=0;
    nom=chef="";
}

Departement::Departement(int id,QString nom,QString chef,int numEmp)
{
this->id=id;
this->nom=nom;
this->chef=chef;
this->numEmp=numEmp;
}
int Departement::get_id(){return id;}
QString Departement::get_nom(){return nom;}
QString Departement::get_chef(){return chef;}
int Departement::get_numEmp(){return numEmp;}
bool Departement::ajouter()
{
    QSqlQuery query;
    QString res1= QString::number(id);
    QString res2= QString::number(numEmp);
    query.prepare("INSERT INTO departement (id, nom, chef, numEmp) "
                        "VALUES (:id, :nom, :chef, :numEmp)");
    query.bindValue(":id", res1);
    query.bindValue(":nom", nom);
    query.bindValue(":chef", chef);
    query.bindValue("numEmp", res2);

    return    query.exec();
}

QSqlQueryModel * Departement::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from departement");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("chef"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("numEmp"));
return model;
}

bool Departement::supprimer(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("Delete from departement where id = :id ");
    query.bindValue(":id", res);
    return    query.exec();
}

bool Departement::modifier(int id,QString nom,QString chef,int numEmp)
{
    QSqlQuery query;
    QString res= QString::number(id);
    QString res1= QString::number(numEmp);
    query.prepare("update departement set nom=:nom,chef=:chef,numEmp=:numEmp where id=:id");
    query.bindValue(":id", res);
    query.bindValue(":nom", nom);
    query.bindValue(":chef", chef);
    query.bindValue(":numEmp", res1);
    return    query.exec();
}

QSqlQueryModel *Departement::trier(QString)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from departement order by nom");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("chef"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("numEmp"));
        return model;
}

QSqlQueryModel *Departement::rechercher(QString a)
{
    QSqlQueryModel * query=new QSqlQueryModel();
    query->setQuery("select * from departement where (nom like '%"+a+"%')");
    return    query;
}
