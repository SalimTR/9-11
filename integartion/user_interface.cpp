#include "user_interface.h"
#include "ui_user_interface.h"

user_interface::user_interface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::user_interface)
{
    ui->setupUi(this);
}

user_interface::~user_interface()
{
    delete ui;
}
