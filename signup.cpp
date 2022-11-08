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

