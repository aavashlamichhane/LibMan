#include "helpandsupport.h"
#include "ui_helpandsupport.h"

helpandsupport::helpandsupport(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::helpandsupport)
{
    ui->setupUi(this);
}

helpandsupport::~helpandsupport()
{
    delete ui;
}