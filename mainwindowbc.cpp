#include "mainwindowbc.h"
#include "ui_mainwindowbc.h"
#include "bagage.h"
#include "colis.h"
#include <QDate>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
QT_CHARTS_USE_NAMESPACE

MainWindowBC::MainWindowBC(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindowBC)
{
    ui->setupUi(this);
}

MainWindowBC::~MainWindowBC()
{
    delete ui;
}

Bagage b;
colis c;

void MainWindowBC::on_butBag_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    this->ui->tableView->setModel(b.afficher());
}

void MainWindowBC::on_butAjout_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindowBC::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindowBC::on_butModif_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindowBC::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindowBC::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}



void MainWindowBC::on_pushButton_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindowBC::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindowBC::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindowBC::on_pushButton_clicked()
{
    int idVoy= ui->idvoy->text().toInt();
    int code= ui->codeb->text().toInt();
    QString poids= ui->poidsb->text();
    Bagage b(idVoy,code,poids);
    bool test= b.ajouter();
    if(test)
         {
         QMessageBox::information(nullptr, QObject::tr("Ajouter un bagage"),
                           QObject::tr("Bagage ajouté.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);

         }
           else
               QMessageBox::critical(nullptr, QObject::tr("Ajouter un bagage"),
                           QObject::tr("Erreur !.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
    ui->codeb->clear();
    ui->idvoy->clear();
    ui->poidsb->clear();
    ui->stackedWidget->setCurrentIndex(5);

}

void MainWindowBC::on_butAff_clicked()
{

    this->ui->tableView->setModel(b.afficher());
}

void MainWindowBC::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindowBC::on_sup_clicked()
{
    int code= ui->codebs->text().toInt();
    b.supprimer(code);
    ui->codebs->clear();
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindowBC::on_pushButton_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindowBC::on_pushButton_13_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindowBC::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindowBC::on_butCol_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}


void MainWindowBC::on_butAjoutc_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void MainWindowBC::on_pushButton_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindowBC::on_butAffichc_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
    this->ui->tableView_3->setModel(c.afficher());
}

void MainWindowBC::on_butConfAjoutC_clicked()
{
    int code= ui->codec->text().toInt();
    QString pays= ui->pays->text();
    QString ville= ui->ville->text();
    QDate datec= ui->datec->date();
    QString type= ui->type->currentText();
    colis c(code, pays, ville, datec, type);
    bool test2= c.ajouter();
    if(test2)
         {
         QMessageBox::information(nullptr, QObject::tr("Ajouter un colis"),
                           QObject::tr("Colis ajouté.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);

         }
           else
               QMessageBox::critical(nullptr, QObject::tr("Ajouter un colis"),
                           QObject::tr("Erreur !.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
    ui->codec->clear();
    ui->pays->clear();
    ui->ville->clear();
    ui->datec->clear();
    ui->type->clear();
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindowBC::on_pushButton_14_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindowBC::on_butsupprc_clicked()
{
    int code= ui->codecs->text().toInt();
    c.supprimer(code);
    ui->codecs->clear();
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindowBC::on_butSupprc_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}

void MainWindowBC::on_pushButton_15_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindowBC::on_pushButton_16_clicked()
{
    int code=ui->modifcode->text().toInt();
    QString pays=ui->modifpays->text();
    QString ville=ui->modifville->text();
    QDate datec= ui->modifdatec->date();
    QString type=ui->modiftype->currentText();
    colis c(code,pays,ville,datec,type);
    bool test=c.modifier();
    if(test)
           {
             ui->tableView->setModel(c.afficher());
           QMessageBox::information(nullptr, QObject::tr("modifier un colis"),
                             QObject::tr("Colis modifiée.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);

           }
             else
        {
                 QMessageBox::critical(nullptr, QObject::tr("modifier un colis"),
                             QObject::tr("Erreur !.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
         }
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindowBC::on_pushButton_9_clicked()
{

    int idVoy=ui->modifidVoy->text().toInt();
    int code=ui->modifcodeb->text().toInt();
    QString poids=ui->modifpoids->text();
    Bagage b(idVoy ,code, poids);
    bool test=b.modifier();
    if(test)
           {
             ui->tableView->setModel(b.afficher());
           QMessageBox::information(nullptr, QObject::tr("modifier un bagage"),
                             QObject::tr("Bagage modifiée.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);

           }
             else{
                 QMessageBox::critical(nullptr, QObject::tr("modifier un bagage"),
                             QObject::tr("Erreur !.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
                }
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindowBC::on_butmodifc_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindowBC::on_toColis_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindowBC::on_tableView_clicked(const QModelIndex &index)
{
    this->ui->tableView->setModel(b.afficher());
}

void MainWindowBC::on_ddd_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    this->ui->tableView->setModel(b.afficher());
}

void MainWindowBC::on_ccc_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
    this->ui->tableView_3->setModel(c.afficher());
}
void MainWindowBC::on_butretourc_clicked(){}
void MainWindowBC::on_pushButton_17_clicked(){}

void MainWindowBC::on_butTri_clicked()
{
    Bagage b;
    bool test=true;
    if(test)
    {
        ui->tableView->setModel(b.trierpoids());
        QMessageBox::information(nullptr, QObject::tr("trier bagages"),
        QObject::tr("bagages tries.\n"
        "Voulez-vous enregistrer les modifications ?"),
        QMessageBox::Save
        |QMessageBox::Cancel,
        QMessageBox::Save);
    }
    else
    QMessageBox::critical(nullptr, QObject::tr("trier bagages"),
    QObject::tr("Erreur !.\n"
    "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindowBC::on_lineEdit_textChanged(const QString &arg1)
{
    Bagage b;
             b.clearTable(ui->tableView);
             QString mat=ui->lineEdit->text();
             b.searchRegexp(ui->tableView,mat);
}

void MainWindowBC::on_buttriC_clicked()
{
    colis c;
    bool test=true;
    if(test)
    {
        ui->tableView->setModel(c.trierdate());
        QMessageBox::information(nullptr, QObject::tr("trier colis"),
        QObject::tr("colis tries.\n"
        "Voulez-vous enregistrer les modifications ?"),
        QMessageBox::Save
        |QMessageBox::Cancel,
        QMessageBox::Save);
    }
    else
    QMessageBox::critical(nullptr, QObject::tr("trier colis"),
    QObject::tr("Erreur !.\n"
    "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindowBC::on_lineEdit_2_textChanged(const QString &arg1)
{
    colis c;
             c.clearTable(ui->tableView_3);
             QString matt=ui->lineEdit_2->text();
             c.searchRegexp(ui->tableView_3,matt);
}


void MainWindowBC::on_butStat_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
        QPieSeries *series = new QPieSeries();
            series->append("Produit alimentaire", c.nombreCategorie1());
            series->append("Medicaments", c.nombreCategorie2());
            series->append("Produit fragile", c.nombreCategorie3());
            series->append("Vetement", c.nombreCategorie4());
            series->append("Drogue", c.nombreCategorie5());
            series->append("Objet", c.nombreCategorie6());

            QPieSlice *slice = series->slices().at(1);
            slice->setExploded();
            slice->setLabelVisible();
            slice->setPen(QPen(Qt::darkGreen, 2));
            slice->setBrush(Qt::green);

            QChart *chart = new QChart();
            chart->addSeries(series);
            chart->setTitle("stat");
           // chart->legend()->hide();

            QChartView *chartView = new QChartView(chart);
            chartView->setRenderHint(QPainter::Antialiasing);

            setCentralWidget(chartView);
            resize(440,300);
            show();
}
