#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"homepage.h"
#include"studenthomepage.h"
#include<QMessageBox>


QString usernameg;
QString check;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlDatabase dab = QSqlDatabase::addDatabase("QMYSQL","LibMan");
    dab.setHostName("127.0.0.1");
    dab.setUserName("root");
    dab.setPassword("rampyari1234");
    dab.setDatabaseName("libman");
    dab.open();

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_6_clicked()
{
    hide();
    signup=new SignUp(this);
    signup->show();
}


void MainWindow::on_Login_3_clicked()
{

    QString username=ui->username_login->text();
    QString password=ui->password_login->text();
    QSqlQuery query_login(QSqlDatabase::database("LibMan"));
    query_login.prepare(QString("SELECT * FROM userbase WHERE username=:username AND password=:password"));
    query_login.bindValue(":username",username);
    query_login.bindValue(":password",password);
    if(!query_login.exec())
    {
        QMessageBox::warning(this,"Login","Try Again.");
    }
    else
    {
        if(query_login.next())
        {
            QString usernamedb=query_login.value(0).toString();
            QString passworddb=query_login.value(1).toString();
            if(usernamedb==username && passworddb==password)
            {
                usernameg=usernamedb;
                QSqlQuery query_login1(QSqlDatabase::database("LibMan"));
                query_login1.prepare("SELECT username,user_key FROM userbase WHERE username=:username");
                query_login1.bindValue(":username",usernamedb);
                query_login1.exec();
                query_login1.first();
                check=query_login1.value(1).toString();
                if(check=="1")
                {
                    hide();
                    homepage=new HomePage(this);
                    homepage->show();
                }
                else
                {
                    hide();
                    shomepage=new studentHomePage(this);
                    shomepage->show();

                }

            }

        }
        else
           QMessageBox::warning(this,"Login","Username and password do not match.");
    }

}





void MainWindow::on_pushButton_5_clicked()
{

}


void MainWindow::on_Login_3_pressed()
{
    MainWindow::on_Login_3_clicked();
}

