#include "employes.h"
#include <QDebug>
#include <QSqlQueryModel>
#include <QSqlQuery>

Employes::Employes()
{
    cin=age=tel=0;
    nom=prenom=adresse=departement="";
}

Employes::Employes(int cin,QString nom,QString prenom,int age,int tel,QString adresse,QString departement)
{
    this->cin=cin;
    this->nom=nom;
    this->prenom=prenom;
    this->age=age;
    this->tel=tel;
    this->adresse=adresse;
    this->departement=departement;
}

int Employes::get_cin(){return cin;}
QString Employes::get_nom(){return nom;}
QString Employes::get_prenom(){return prenom;}
int Employes::get_age(){return age;}
int Employes::get_tel(){return tel;}
QString Employes::get_adresse(){return adresse;}
QString Employes::get_departement(){return departement;}

bool Employes::ajouter()
{
    QSqlQuery query;
    QString res1= QString::number(cin);
    QString res2= QString::number(age);
    QString res3= QString::number(tel);
    query.prepare("INSERT INTO EMPLOYES (cin, nom, prenom, age, tel, adresse, departement) "
                        "VALUES (:cin, :nom, :prenom, :age, :tel, :adresse, :departement)");
    query.bindValue(":cin",res1);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":age",res2);
    query.bindValue(":tel",res3);
    query.bindValue(":adresse",adresse);
    query.bindValue(":departement",departement);
    return    query.exec();
}

QSqlQueryModel * Employes::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from EMPLOYES");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("tel"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("departement"));
    return model;
    }
bool Employes::supprimer(int cin)
{
QSqlQuery query;
QString res= QString::number(cin);
query.prepare("Delete from employes where cin = :cin ");
query.bindValue(":cin", res);
return    query.exec();
}

bool Employes::modifier(int cin,QString nom,QString prenom,int age,int tel,QString adresse,QString departement)
{
QSqlQuery query;
QString res= QString::number(cin);
QString res1= QString::number(age);
QString res2= QString::number(tel);
query.prepare("update employes set nom=:nom,prenom=:prenom,age=:age,tel=:tel,adresse=:adresse,departement=:departement where cin=:cin");
query.bindValue(":cin", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":age", res1);
query.bindValue(":tel", res2);
query.bindValue(":adresse", adresse);
query.bindValue(":departement", departement);
return    query.exec();
}
QSqlQueryModel *Employes::trier(QString x)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    qDebug()<<x<<endl;
    if(x=="Nom")
        model->setQuery("select cin,nom,prenom,age,tel,adresse,departement from employes order by nom");
    else if(x=="Prénom")
        model->setQuery("select cin, nom, prenom, age, tel, adresse, departement from employes order by prenom");
    else if (x=="Departement")
        model->setQuery("select cin, nom, prenom, age, tel, adresse, departement from employes order by departement");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("tel"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("departement"));
        return model;
}
QSqlQueryModel* Employes::rechercher(QString a)
{
    QSqlQueryModel * query=new QSqlQueryModel();
    query->setQuery("select * from employes where (nom like '%"+a+"%' or prenom like '%"+a+"%' ) ");
    return    query;
}
