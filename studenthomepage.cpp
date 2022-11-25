#include "studenthomepage.h"
#include "ui_studenthomepage.h"
#include"mainwindow.h"

studentHomePage::studentHomePage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::studentHomePage)
{
    ui->setupUi(this);
    QSqlDatabase data = QSqlDatabase::addDatabase("QMYSQL","sHome");
    data.setHostName("127.0.0.1");
    data.setUserName("root");
    data.setPassword("rampyari1234");
    data.setDatabaseName("libman");
    data.open();
    QSqlQuery query(data);
    extern QString usernameg;
    QString aux;
    query.prepare("SELECT username FROM userbase WHERE username=:username");
    query.bindValue(":username",usernameg);
    query.exec();
    query.first();
    aux = query.value(0).toString() ;
    ui->label_name->setText(aux);
    if(!query.isActive())
    {
        QMessageBox::information(0,"Bad Query", "BAD Query. It's not active");
    }
}

studentHomePage::~studentHomePage()
{
    delete ui;
}

void studentHomePage::on_pushButton_settings_clicked()
{
    hide();
    settings =new Settings(this);
    settings->show();
}


void studentHomePage::on_pushButton_user_clicked()
{
    hide();
    info = new UserInfo(this);
    info->show();
}




