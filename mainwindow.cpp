#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employes.h"
#include "departement.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_ajouter_clicked()
{
    int cin = ui->lineEditCin->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_depart->text();
    int age= ui->lineEdit_age->text().toInt();
    int tel= ui->lineEdit_tel->text().toInt();
    QString adresse= ui->lineEdit_adresse->text();
    QString departement= ui->lineEdit_depart->text();
  Employes e(cin,nom,prenom,age,tel,adresse,departement);
  bool test=e.ajouter();
  if(test)
{ui->listView->setModel(tmpDepartement.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une ligne"),
                  QObject::tr("ligne ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une ligne"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
