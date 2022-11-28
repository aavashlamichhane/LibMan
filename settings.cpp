#include "settings.h"
#include "ui_settings.h"
#include "mainwindow.h"
#include "homepage.h"
#include "studenthomepage.h"

HomePage *hps;
MainWindow *mp;
studentHomePage *shp;

Settings::Settings(QWidget *parent) :
    QMainWindow(parent),
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
    close();
    mp=new MainWindow(this);
    mp->showMaximized();
}


void Settings::on_pushButton_home_clicked()
{
    extern QString check;

    if(check=="1")
    {
        close();
        hps=new HomePage(this);
        hps->showMaximized();
    }
    else
    {
        close();
        shp=new studentHomePage(this);
        shp->showMaximized();

    }
}


void Settings::on_pushButton_privacy_clicked()
{
    pvs=new privacyandsecurity(this);
    pvs->show();
}


void Settings::on_pushButton_help_clicked()
{
    hlps=new helpandsupport(this);
    hlps->show();
}


void Settings::on_pushButton_about_clicked()
{
    abt=new about(this);
    abt->show();
}
