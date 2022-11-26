#include "adminpannel.h"
#include "ui_adminpannel.h"
#include "homepage.h"

HomePage *home;

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


void adminpannel::on_pushButton_promote_clicked()
{
    close();
    prom = new promote(this);
    prom->show();
}


void adminpannel::on_pushButton_updatebook_clicked()
{
    close();
    upd = new UpdateBook(this);
    upd->show();
}


void adminpannel::on_pushButton_clicked()
{
   close();
   home = new HomePage(this);
   home->show();
}

