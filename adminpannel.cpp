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
    close();
    newbook = new entry(this);
    newbook->show();
}


void adminpannel::on_pushButton_issuebook_clicked()
{
    close();
    issue = new bookissue(this);
    issue->show();
}


void adminpannel::on_pushButton_returnbook_clicked()
{
    close();
    returnbook=new returnBook(this);
    returnbook->show();
}

