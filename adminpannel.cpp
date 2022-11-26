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

void adminpannel::on_pushButton_addbook_clicked()
{
    hide();
    newbook = new entry(this);
    newbook->show();
}


void adminpannel::on_pushButton_issuebook_clicked()
{
    hide();
    issue = new bookissue(this);
    issue->show();
}

