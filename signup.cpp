#include "signup.h"
#include "ui_mainwindow.h"
#include "ui_signup.h"
#include "mainwindow.h"

MainWindow *login;
SignUp::SignUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);
}

SignUp::~SignUp()
{
    delete ui;
}

void SignUp::on_commandLinkButton_clicked()
{
    hide();
    login= new MainWindow(this);
    login->show();
}


void SignUp::on_pushButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("rampyari1234");
    db.setDatabaseName("libman");

    if(db.open())
    {
        QString fN = ui->lineEdit_fN->text();
        QString mN = ui->lineEdit_mN->text();
        QString lN = ui->lineEdit_lN->text();
        QString fN = ui->lineEdit_fN->text();
    }

}

