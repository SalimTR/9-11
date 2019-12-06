#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "user_interface.h"
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

void MainWindow::on_login_clicked()
{
    user_interface * a=new user_interface;
   this->hide();
    a->show();
}
