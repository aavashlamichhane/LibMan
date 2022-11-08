#include "userinfo.h"
#include "ui_userinfo.h"
#include "homepage.h"

HomePage *hp;

UserInfo::UserInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserInfo)
{
    ui->setupUi(this);
}

UserInfo::~UserInfo()
{
    delete ui;
}

void UserInfo::on_pushButton_editprofile_clicked()
{
    hide();
    ep=new editProfile(this);
    ep->show();
}


void UserInfo::on_pushButton_home_clicked()
{
    hide();
    hp=new HomePage(this);
    hp->show();
}

