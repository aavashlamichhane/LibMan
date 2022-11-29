#include "helpandsupport.h"
#include "ui_helpandsupport.h"

helpandsupport::helpandsupport(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::helpandsupport)
{
    ui->setupUi(this);
    this->setWindowTitle("LibMan");
}

helpandsupport::~helpandsupport()
{
    delete ui;
}
