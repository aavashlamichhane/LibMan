#include "editprofile.h"
#include "ui_editprofile.h"
#include "userinfo.h"

UserInfo *info1;

editProfile::editProfile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editProfile)
{
    ui->setupUi(this);
}

editProfile::~editProfile()
{
    delete ui;
}

void editProfile::on_pushButton_2_clicked()
{
    hide();
    info1=new UserInfo(this);
    info1->show();
}

