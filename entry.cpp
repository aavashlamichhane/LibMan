#include "entry.h"
#include "ui_entry.h"
#include "homepage.h"

HomePage *hp2;

entry::entry(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::entry)
{
    ui->setupUi(this);
}

entry::~entry()
{
    delete ui;
}

void entry::on_pushButton_2_clicked()
{
    hide();
    hp2=new HomePage(this);
    hp2->show();
}

