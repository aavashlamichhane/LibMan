#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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




