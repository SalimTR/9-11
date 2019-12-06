#include "voyageur.h"
#include <QDebug>

voyageur::voyageur()
{
     cin="";
        tel="";
         nom="";
         prenom="";
}

voyageur::voyageur(QString cin,QString tel,QString nom,QString prenom)
{
    this->cin=cin;
        this->tel=tel;
        this->nom=nom;
        this->prenom=prenom;
}
bool voyageur::ajouter()
{
QSqlQuery query;
QString res1= cin;
QString res2= tel;
query.prepare("INSERT INTO voyageurs (cin, tel, nom,prenom) "
                    "VALUES (:cin, :tel, :nom,:prenom)");
query.bindValue(":cin", res1);
query.bindValue(":tel", res2);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);

return    query.exec();
}

QSqlQueryModel * voyageur::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from voyageurs");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("tel "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("prenom"));
    return model;
}

bool voyageur::supprimer(QString cin)
{
QSqlQuery query;
QString res= cin;
query.prepare("Delete from voyageurs where cin = :cin ");
query.bindValue(":cin", res);
return    query.exec();
}

bool voyageur::modifier(QString cin,QString tel,QString nom,QString prenom)
{
    QSqlQuery query;
    QString res= cin;
    QString res2= tel;
    query.prepare("update voyageurs set tel=:tel,nom=:nom,prenom=:prenom where cin=:cin");
    query.bindValue(":cin", res);
    query.bindValue(":tel", res2);
     query.bindValue(":nom", nom);
      query.bindValue(":prenom", prenom);
    return    query.exec();
}
QSqlQueryModel * voyageur::chercher(QString cin)
{QSqlQueryModel * model= new QSqlQueryModel();
 QString res= cin;
 model->setQuery("select * from voyageurs where cin='"+res+"'");
return model;
}
