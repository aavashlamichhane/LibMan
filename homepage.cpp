#include "homepage.h"
#include "ui_homepage.h"
HomePage::HomePage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HomePage)
{
    ui->setupUi(this);
}

HomePage::~HomePage()
{
    delete ui;
}

void HomePage::on_pushButton_settings_clicked()
{
    hide();
    settings =new Settings(this);
    settings->show();
}


void HomePage::on_pushButton_user_clicked()
{
    hide();
    info = new UserInfo(this);
    info->show();
}


void HomePage::on_pushButton_adminpanel_clicked()
{
    hide();
    newbook =new entry(this);
    newbook->show();
}

