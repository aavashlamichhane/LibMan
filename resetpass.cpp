#include "resetpass.h"
#include "ui_resetpass.h"

resetpass::resetpass(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::resetpass)
{
    ui->setupUi(this);
}

resetpass::~resetpass()
{
    delete ui;
}