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
    ui->listView->setModel(tmpEmployes.afficher());
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
{ui->listView->setModel(tmpEmployes.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une employé"),
                  QObject::tr("employé ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une employé"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_2_clicked()
{
    QString nom = ui->lineEdit_5->text();
                ui->listView->setModel(tmpEmployes.rechercher(nom));
}

void MainWindow::on_pushButton_clicked()
{
    QString l = ui->comboBox_2->currentText();
    ui->listView->setModel(tmpEmployes.trier(l));
}

void MainWindow::on_pushButton_3_clicked()
{
    int cin = ui->lineEdit->text().toInt();
        QString nom= ui->lineEdit_2->text();
        QString prenom= ui->lineEdit_3->text();
        int age= ui->lineEdit_4->text().toInt();
        int tel= ui->lineEdit_6->text().toInt();
        QString adresse= ui->lineEdit_7->text();
        QString departement= ui->lineEdit_8->text();
        Employes e(cin,nom,prenom,age,tel,adresse,departement);
        bool test=tmpEmployes.modifier(cin,nom,prenom,age,tel,adresse,departement);
        if(test)
        {ui->listView->setModel(tmpEmployes.afficher());//refresh
            QMessageBox::information(nullptr, QObject::tr("modifier un employé"),
                        QObject::tr("employe modifier.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("modifier un employé"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_4_clicked()
{
    int cin = ui->lineEdit_9->text().toInt();
    bool test=tmpEmployes.supprimer(cin);
    if(test)
    {ui->listView->setModel(tmpEmployes.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un employé"),
                    QObject::tr("employé supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une employé"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
void MainWindow::on_pushButton_5_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom_2->text();
    QString chef= ui->lineEdit_chef->text();
    int numEmp= ui->lineEdit_numemp->text().toInt();
  Departement e(id,nom,chef,numEmp);
  bool test=e.ajouter();
  if(test)
{ui->tableView->setModel(tmpDepartement.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un département"),
                  QObject::tr("département ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un departement"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_8_clicked()
{
    int id = ui->lineEdit_11->text().toInt();
        QString nom= ui->lineEdit_12->text();
        QString chef= ui->lineEdit_13->text();
        int numEmp= ui->lineEdit_14->text().toInt();
        Departement e(id,nom,chef,numEmp);
        bool test=tmpDepartement.modifier(id,nom,chef,numEmp);
        if(test)
        {ui->listView->setModel(tmpDepartement.afficher());//refresh
            QMessageBox::information(nullptr, QObject::tr("modifier un département"),
                        QObject::tr("département modifier.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("modifier un département"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}
