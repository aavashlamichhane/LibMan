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
bool chkChara(QChar c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

bool chkEmaila(QString email)
{

    if (!chkChara(email[0]))
    {
        return 0;
    }

    int at =-1, dot =-1;

    for (int i = 0;
         i < email.length(); i++) {

        if (email[i] == '@') {

            at = i;
        }

        else if (email[i] == '.') {

            dot = i;
        }
    }

    if (at == -1 || dot == -1)
        return 0;

    if (at > dot)
        return 0;

    return !(dot >= (email.length() - 1));
}

editProfile::editProfile(QWidget *parent) :
    QMainWindow(parent),
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
    fN= query.value(1).toString();
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
    close();
    info1=new UserInfo(this);
    info1->showMaximized();
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
        QDate dob = ui->dateEdit->date();
        QString password = ui->lineEdit_pass->text();
        QString cpassword = ui->lineEdit_cpass->text();
        QSqlQuery chku(data_info),chke(data_info),chkp(data_info);
        chku.prepare("SELECT * FROM userbase WHERE username=:username");
        chku.bindValue(":username",user);
        chke.prepare("SELECT * FROM userbase WHERE user_email=:user_email");
        chke.bindValue(":user_email",email);
        chkp.prepare("SELECT * FROM userbase WHERE phone_number=:phone_number");
        chkp.bindValue(":phone_number",pNum);
        chku.exec();
        chkp.exec();
        chke.exec();

        if(password!=cpassword)
        {
            QMessageBox::warning(this,"Error","Password doesn't match. Please try again.");
        }
        else if(countDigitsss(num)!=10)
            QMessageBox::warning(this,"Error","Phone number is incorrect.");
        else if(!dob.isValid())
            QMessageBox::warning(this,"Error","Invalid Date.");
        else if(chku.next())
            QMessageBox::warning(this,"Error","Username already taken.");
        else if(chke.next())
            QMessageBox::warning(this,"Error","Email already used.");
        else if(chkp.next())
            QMessageBox::warning(this,"Error","Phone number already used.");
        else if(!chkEmaila(email))
            QMessageBox::warning(this,"Error","Invalid email.");
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
