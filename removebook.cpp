#include "removebook.h"
#include "ui_removebook.h"

removebook::removebook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::removebook)
{
    ui->setupUi(this);
}

removebook::~removebook()
{
    delete ui;
}
