#include "adminconfig.h"
#include "ui_adminconfig.h"

adminConfig::adminConfig(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminConfig)
{
    ui->setupUi(this);
}

adminConfig::~adminConfig()
{
    delete ui;
}
