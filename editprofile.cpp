#include "editprofile.h"
#include "ui_editprofile.h"
#include "userinfo.h"
#include<QMessageBox>

UserInfo *info1;

int countDigitsss(long long n)
{
   int a=0;
   while(n!=0)
   {
       a++;
       n=n/10;
   }
   return a;
}
editProfile::editProfile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editProfile)
{
    ui->setupUi(this);
    data_info = QSqlDatabase::addDatabase("QMYSQL","Info");
    data_info.setHostName("127.0.0.1");
    data_info.setUserName("root");
    data_info.setPassword("rampyari1234");
    data_info.setDatabaseName("libman");
    data_info.open();
    QSqlQuery query(data_info);
    extern QString usernameg;
    QString fN,mN,lN,uN,pN,sex,job,eM,fullN,key,pass,cpass;
    QDate dob;
    query.prepare("SELECT username,first_name,middle_name,last_name,user_email,date_of_birth,phone_number,sex,password FROM userbase WHERE username=:username");
    query.bindValue(":username",usernameg);
    query.exec();
    query.first();
    fN= query.value(1).toString() ;
    mN= query.value(2).toString();
    lN= query.value(3).toString();
    uN=query.value(0).toString();
    eM=query.value(4).toString();
    dob=query.value(5).toDate();
    pN=query.value(6).toString();
    sex=query.value(7).toString();
    pass=query.value(8).toString();



    ui->lineEdit_fN->setText(fN);
    ui->lineEdit_mN->setText(mN);
    ui->lineEdit_lN->setText(lN);
    ui->lineEdit_user->setText(uN);
    ui->lineEdit_pH->setText(pN);
    ui->dateEdit->setDate(dob);
    int a;
    if(sex=="Male")
        a=0;
    else if(sex=="Female")
        a=1;
    else
        a=2;
    ui->comboBox_sex->setCurrentIndex(a);
    ui->lineEdit_pass->setText(pass);
    ui->lineEdit_cpass->setText(pass);
    ui->lineEdit_email->setText(eM);
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


void editProfile::on_pushButton_clicked()
{
    if(data_info.open())
    {
        QString fN = ui->lineEdit_fN->text();
        QString mN = ui->lineEdit_mN->text();
        QString lN = ui->lineEdit_lN->text();
        QString user = ui->lineEdit_user->text();
        QString email = ui->lineEdit_email->text();
        QString pNum = ui->lineEdit_pH->text();
        long long num = ui->lineEdit_pH->text().toLongLong();
        QString sex = ui->comboBox_sex->currentText();
        QString dob = ui->dateEdit->text();
        QString password = ui->lineEdit_pass->text();
        QString cpassword = ui->lineEdit_cpass->text();

        if(password!=cpassword)
        {
            QMessageBox::warning(this,"Error","Password doesn't match. Please try again.");
        }
        else if(countDigitsss(num)!=10)
            QMessageBox::warning(this,"Error","Phone number is incorrect.");
        else
        {
            QSqlQuery qry(data_info);
            extern QString usernameg;
            qry.prepare("UPDATE userbase SET username=:username,password=:password,first_name=:first_name,middle_name=:middle_name,last_name=:last_name,user_email=:user_email,date_of_birth=:date_of_birth,phone_number=:phone_number,sex=:sex WHERE username=:username1");
            qry.bindValue(":username",user);
            qry.bindValue(":password",password);
            qry.bindValue(":first_name",fN);
            qry.bindValue(":middle_name",mN);
            qry.bindValue(":last_name",lN);
            qry.bindValue(":date_of_birth",dob);
            qry.bindValue(":user_email",email);
            qry.bindValue(":phone_number",pNum);
            qry.bindValue(":sex",sex);
            qry.bindValue(":username1",usernameg);

            if(qry.exec())
            {
                QMessageBox::information(this,"Update","Updated successfully.");
                QSqlDatabase::removeDatabase("QMYSQL");
            }
            else
            {
                QMessageBox::warning(this,"Update","Update failed.");
                QSqlDatabase::removeDatabase("QMYSQL");
            }
        }
        QSqlDatabase::removeDatabase("QMYSQL");
    }
    data_info.close();
}
