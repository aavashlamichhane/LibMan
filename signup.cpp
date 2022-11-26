#include "signup.h"
#include "ui_mainwindow.h"
#include "ui_signup.h"
#include "mainwindow.h"

MainWindow *login;
int countDigits(long long n)
{
   int a=0;
   while(n!=0)
   {
       a++;
       n=n/10;
   }
   return a;
}
SignUp::SignUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("127.0.0.1");
    database.setUserName("root");
    database.setPassword("rampyari1234");
    database.setDatabaseName("libman");
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


void SignUp::on_pushButton_clicked()
{
    if(database.open())
    {
        QString fN = ui->lineEdit_fN->text();
        QString mN = ui->lineEdit_mN->text();
        QString lN = ui->lineEdit_lN->text();
        QString user = ui->lineEdit_user->text();
        QString email = ui->lineEdit_email->text();
        long long pNum1=ui->lineEdit_pNum->text().toLongLong();
        QString pNum = ui->lineEdit_pNum->text();
        QString sex = ui->comboBox_sex->currentText();
        QString dob = ui->dateEdit_dob->text();
        QString password = ui->lineEdit_password->text();
        QString cpassword = ui->lineEdit_cpassword->text();

        if(password!=cpassword)
        {
            QMessageBox::warning(this,"Error","Password doesn't match. Please try again.");
        }
        else if(countDigits(pNum1)!=10)
        {
            QMessageBox::warning(this,"Error","Phone number is not correct. Please try again.");
        }
        else
        {
            QSqlQuery qry(database);
            qry.prepare("INSERT INTO userbase(username,password,first_name,middle_name,last_name,user_email,date_of_birth,phone_number,sex)""VALUES(:username,:password,:first_name,:middle_name,:last_name,:user_email,:date_of_birth,:phone_number,:sex)");
            qry.bindValue(":username",user);
            qry.bindValue(":password",password);
            qry.bindValue(":first_name",fN);
            qry.bindValue(":middle_name",mN);
            qry.bindValue(":last_name",lN);
            qry.bindValue(":date_of_birth",dob);
            qry.bindValue(":user_email",email);
            qry.bindValue(":phone_number",pNum);
            qry.bindValue(":sex",sex);

            if(qry.exec())
            {
                QMessageBox::information(this,"Sign Up","Signed up successfully.");
                QSqlDatabase::removeDatabase("QMYSQL");
            }
            else
            {
                QMessageBox::warning(this,"Sign Up","Signed up failed.");
                qDebug() << qry.lastError().text()<<Qt::endl;
                QSqlDatabase::removeDatabase("QMYSQL");
            }
        }
        QSqlDatabase::removeDatabase("QMYSQL");
    }
    database.close();
}

