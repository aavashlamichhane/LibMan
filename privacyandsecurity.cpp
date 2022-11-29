#include "privacyandsecurity.h"
#include "ui_privacyandsecurity.h"

privacyandsecurity::privacyandsecurity(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::privacyandsecurity)
{
    ui->setupUi(this);
    this->setWindowTitle("LibMan");
}

privacyandsecurity::~privacyandsecurity()
{
    delete ui;
}
