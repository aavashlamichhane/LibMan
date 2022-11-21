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
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("127.0.0.1");
    database.setUserName("root");
    database.setPassword("rampyari1234");
    database.setDatabaseName("libman");

    if(QSqlDatabase::database.open())
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
            qry.prepare("INSERT INTO userbase(username,password,first_name,middle_name,last_name,date_of_birth,user_email,phone_number)""VALUES(:username,:password,:fN,:mN,:lN,:dob,:email,:pN");
            qry.bindValue(":username",user);
            qry.bindValue(":password",password);
            qry.bindValue(":fN",fN);
            qry.bindValue(":mN",mN);
            qry.bindValue(":lN",lN);
            qry.bindValue(":dob",dob);
            qry.bindValue(":email",email);
            qry.bindValue(":pN",pNum);

            if(qry.exec())
            {
                QMessageBox::information(this,"Sign Up","Signed up successfully.");
            }
            else
            {
                QMessageBox::warning(this,"Sign Up","Signed up failed.");
            }
        }
    }

}

