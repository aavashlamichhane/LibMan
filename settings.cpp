
#include "settings.h"
#include "ui_settings.h"
#include "mainwindow.h"
#include "homepage.h"

HomePage *hps;
MainWindow *mp;
Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
}

Settings::~Settings()
{
    delete ui;
}

void Settings::on_pushButton_logout_clicked()
{
    hide();
    mp=new MainWindow(this);
    mp->show();
}


void Settings::on_pushButton_home_clicked()
{
    hide();
    hps=new HomePage(this);
    hps->show();
}

