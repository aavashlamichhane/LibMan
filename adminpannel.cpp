#include "adminpannel.h"
#include "ui_adminpannel.h"

adminpannel::adminpannel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminpannel)
{
    ui->setupUi(this);
}

adminpannel::~adminpannel()
{
    delete ui;
}
