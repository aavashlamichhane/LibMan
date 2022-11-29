#include "adminpannel.h"
#include "ui_adminpannel.h"
#include "homepage.h"

HomePage *home;

adminpannel::adminpannel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adminpannel)
{
    ui->setupUi(this);
    this->setWindowTitle("LibMan");
    this->setWindowIcon(QIcon(":/rec/drive-download-20221026T014232Z-001/Logo no BG and text.png"));
}

adminpannel::~adminpannel()
{
    delete ui;
}


void adminpannel::on_pushButton_addbook_clicked()
{
    newbook = new entry(this);
    newbook->show();
}


void adminpannel::on_pushButton_issuebook_clicked()
{
    issue = new bookissue(this);
    issue->show();
}


void adminpannel::on_pushButton_returnbook_clicked()
{
    returnbook=new returnBook(this);
    returnbook->show();
}


void adminpannel::on_pushButton_promote_clicked()
{
    prom = new promote(this);
    prom->show();
}


void adminpannel::on_pushButton_updatebook_clicked()
{
    upd = new UpdateBook(this);
    upd->show();
}


void adminpannel::on_pushButton_clicked()
{
   close();
   home = new HomePage();
   home->showMaximized();
}

