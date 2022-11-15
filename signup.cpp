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
        QString user = ui->lineEdit_user->text();
        QString email = ui->lineEdit_email->text();
        QString pNum = ui->lineEdit_pNum->text();
        QString dob = ui->dateEdit_dob->text();
        QString password = ui->lineEdit_password->text();
        QString cpassword = ui->lineEdit_cpassword->text();
        if(password!=cpassword)
        {
            QMessageBox::warning(this,"Error","Password doesn't match. Please try again.");
        }
        else
        {
            QSqlQuery qry;
            qry.prepare("INSERT INTO userbase(username,password,first_name,middle_name,last_name,date_of_birth,user_email,phone_number)");

        }
    }

}

