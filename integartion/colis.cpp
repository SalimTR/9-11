#include "colis.h"
#include <QSqlQuery>
#include <QVariant>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>

colis::colis()
{
    code= 0;
    pays= "";
    ville= "";
    type= "";
}

colis::colis(int code, QString pays, QString ville, QDate datec, QString type)
{
    this->code= code;
    this->pays= pays;
    this->ville= ville;
    this->datec= datec;
    this->type= type;
}

bool colis::ajouter()
{
    QSqlQuery query;
    QString res1=QString::number(code);

          query.prepare("INSERT INTO colis (code, pays, ville, datec, type) "
                        "VALUES (:code,:pays,:ville,:datec,:type)");
          query.bindValue(":code", res1);
          query.bindValue(":pays", pays);
          query.bindValue(":ville", ville);
          query.bindValue(":datec", datec);
          query.bindValue(":type", type);
          return query.exec();
}

QSqlQueryModel* colis::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from colis");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("code"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("pays"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ville"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("datec"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("type"));
    return  model;
}

void colis::supprimer(int code)
{
    QSqlQuery query;
    query.prepare("DELETE FROM colis WHERE code=:code");
    QString res2=QString::number(code);
    query.bindValue(":code", res2);
    query.exec();
}

bool colis :: modifier()
{
    QSqlQuery query;
    QString res1=QString::number(code);
         query.prepare("UPDATE colis SET pays=:modifpays, ville=:modifville, datec=:modifdatec, type=:modiftype WHERE code =:modifcode;");
         query.bindValue(":modifpays",pays);
         query.bindValue(":modifville",ville);
         query.bindValue(":modifdatec",datec);
         query.bindValue(":modiftype",type);
         query.bindValue(":modifcode",res1);
         return query.exec();
}

QSqlQueryModel * colis :: trierdate()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from colis ORDER BY poids");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("code"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("pays"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ville"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("type"));
    return model;
}

void colis::clearTable(QTableView *table)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->clear();
    table->setModel(model);
}

void colis::searchRegexp(QTableView *table, QString x)
{
   QSqlQueryModel *model=new QSqlQueryModel();
   QSqlQuery *query =new QSqlQuery;
   query->prepare("select * from colis where regexp_like(pays,:pays);");
   query->bindValue(":pays",x);

   if(x==0)
   {
       qDebug("tawa 0");
       query->prepare("select * from colis;");
   }
   query->exec();
   model->setQuery(*query);
   table->setModel(model);
   table->show();
}

int colis :: nombreCategorie1()
{
    QSqlQuery query;
    query.prepare("select COUNT(*) from articles where type='Produit alimentaire'");
    query.exec();
    while(query.next())
    {
       return query.value(0).toInt();
    }
}

int colis :: nombreCategorie2()
{
    QSqlQuery query;
    query.prepare("select COUNT(*) from colis where type='Medicaments'");
    query.exec();
    while(query.next())
    {
       return query.value(0).toInt();
    }
}

int colis :: nombreCategorie3()
{
    QSqlQuery query;
    query.prepare("select COUNT(*) from colis where type='Produit fragile'");
    query.exec();
    while(query.next())
    {
       return query.value(0).toInt();
    }
}

int colis :: nombreCategorie4()
{
    QSqlQuery query;
    query.prepare("select COUNT(*) from colis where type='Vetement'");
    query.exec();
    while(query.next())
    {
       return query.value(0).toInt();
    }
}

int colis :: nombreCategorie5()
{
    QSqlQuery query;
    query.prepare("select COUNT(*) from colis where type='Drogue'");
    query.exec();
    while(query.next())
    {
       return query.value(0).toInt();
    }
}

int colis :: nombreCategorie6()
{
    QSqlQuery query;
    query.prepare("select COUNT(*) from colis where type='Objet'");
    query.exec();
    while(query.next())
    {
       return query.value(0).toInt();
    }
}
