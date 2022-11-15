#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
   // db.setHostName("127.0.0.1");
   // db.setUserName("root");
   // db.setPassword("rampyari1234");
   // db.setDatabaseName("libman");
   // if(db.open())
   // {
   //     sqlquery = new QSqlQueryModel();
   //     sqlquery->setQuery("SELECT * FROM books");
   //     ui->tableView->setModel(sqlquery);
   // }
   // else
   // {
   //    QMessageBox::warning(this,"Connection","Database not connected.");
   // }

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
    hide();
    homepage=new HomePage(this);
    homepage->show();
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

