#include "userinfo.h"
#include "ui_userinfo.h"
#include "homepage.h"
#include "studenthomepage.h"

HomePage *hp;
studentHomePage *shps;

UserInfo::UserInfo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserInfo)
{
    ui->setupUi(this);
    this->setWindowTitle("LibMan");
    this->setWindowIcon(QIcon(":/rec/drive-download-20221026T014232Z-001/Logo no BG and text.png"));
    data_info = QSqlDatabase::addDatabase("QMYSQL","Info");
    data_info.setHostName("127.0.0.1");
    data_info.setUserName("root");
    data_info.setPassword("rampyari1234");
    data_info.setDatabaseName("libman");
    data_info.open();
    QSqlQuery query(data_info);
    extern QString usernameg;
    QString fN,mN,lN,uN,pN,sex,dob,job,eM,fullN,key;
    query.prepare("SELECT username,first_name,middle_name,last_name,user_email,date_of_birth,phone_number,sex,user_key FROM userbase WHERE username=:username");
    //query.prepare("SELECT username FROM userbase WHERE username=:username,first_name=:first_name,middle_name=:middle_name,last_name=:last_name,user_email=:user_email,date_of_birth=:date_of_birth,phone_number=:phone_number,sex=:sex");
    query.bindValue(":username",usernameg);
    query.exec();
    query.first();
    fN= query.value(1).toString() ;
    mN= query.value(2).toString();
    lN= query.value(3).toString();
    uN=query.value(0).toString();
    eM=query.value(4).toString();
    dob=query.value(5).toString();
    pN=query.value(6).toString();
    sex=query.value(7).toString();
    key=query.value(8).toString();


    if(mN=="-")
    fullN=fN+" "+lN;
    else
    fullN=fN+" "+mN+" "+lN;
    ui->label_name->setText(fullN);
    ui->label_username->setText("@"+uN);
    ui->label_mail->setText(eM);
    ui->label_age->setText(dob);
    ui->label_phone->setText(pN);
    ui->label_sex->setText(sex);
    if(key=="0")
    ui->label_job->setText("Customer");
    else
    ui->label_job->setText("Staff");
}

UserInfo::~UserInfo()
{
    delete ui;
}
void UserInfo::on_pushButton_editprofile_clicked()
{
    hide();
    ep=new editProfile();
    ep->showMaximized();
}


void UserInfo::on_pushButton_home_clicked()
{
    extern QString check;

    if(check=="1")
    {
        hide();
        hp=new HomePage();
        hp->showMaximized();
    }
    else
    {
        hide();
        shps=new studentHomePage();
        shps->showMaximized();

    }
}
