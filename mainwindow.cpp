#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*QSqlDatabase dab = QSqlDatabase::addDatabase("QMYSQL","LibMan");
    dab.setHostName("127.0.0.1");
    dab.setUserName("root");
    dab.setPassword("rampyari1234");
    dab.setDatabaseName("libman");
    if(dab.open())
    {

    }
    else
    {
       QMessageBox::warning(this,"Connection","Database not connected.");
    }*/

}

MainWindow::~MainWindow()
{
    //QSqlDatabase db = QSqlDatabase::database();
    //db.close();
    //QSqlDatabase::removeDatabase(db.());
    delete ui;
}



void MainWindow::on_pushButton_6_clicked()
{
    //QSqlDatabase db = QSqlDatabase::database("libman");
    //db.close();
    //QSqlDatabase::removeDatabase("libman");
    hide();
    signup=new SignUp(this);
    signup->show();
}


void MainWindow::on_Login_3_clicked()
{
    QSqlDatabase dab = QSqlDatabase::addDatabase("QMYSQL","LibMan");
    dab.setHostName("127.0.0.1");
    dab.setUserName("root");
    dab.setPassword("rampyari1234");
    dab.setDatabaseName("libman");
    dab.open();
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
        while(query_login.next())
        {
            QString usernamedb=query_login.value(0).toString();
            QString passworddb=query_login.value(1).toString();
            if(usernamedb==username && passworddb==password)
            {
                hide();
                homepage=new HomePage(this);
                homepage->show();
            }
            else
            {
                QMessageBox::warning(this,"Login","Username and password do not match.");
            }
        }
    }

}





void MainWindow::on_pushButton_5_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("rampyari1234");
    db.setDatabaseName("libman");
    if(db.open())
    {
        QMessageBox::information(this,"Connection","connected successfully.");

    }
    else
    {
        QMessageBox::information(this,"Connection","not connected.");
    }
}

