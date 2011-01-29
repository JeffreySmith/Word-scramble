#include "admindialog.h"
#include "ui_admindialog.h"
#include <iostream>
AdminDialog::AdminDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminDialog)
{
    ui->setupUi(this);
    username="Jeffrey";
    password="1234";
}

AdminDialog::~AdminDialog()
{
    delete ui;

}
void AdminDialog::checkUsernamePassword()
{
    if(ui->userNameEntry->text()==username && ui->passwordEntry->text()==password)
    {
        admin=true;
        std::cout<<"Admin\n";
    }
    else
    {
        admin=false;
    }
}
