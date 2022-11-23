#include "entry.h"
#include "ui_entry.h"
#include "homepage.h"

HomePage *hp2;

entry::entry(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::entry)
{
    ui->setupUi(this);
}

entry::~entry()
{
    delete ui;
}

void entry::on_pushButton_2_clicked()
{
    hide();
    hp2=new HomePage(this);
    hp2->show();
}


void entry::on_pushButton_clicked()
{
    dEntry = QSqlDatabase::addDatabase("QMYSQL");
    dEntry.setHostName("127.0.0.1");
    dEntry.setUserName("root");
    dEntry.setPassword("rampyari1234");
    dEntry.setDatabaseName("libman");

    if(dEntry.open())
    {
        QString bN = ui->lineEdit_name->text();
        QString aN = ui->lineEdit_author->text();
        QString pD = ui->dateEdit_pdate->text();
        QString iN = ui->lineEdit_isbn->text();
        QString pB = ui->lineEdit_pub->text();
        QString nC = ui->lineEdit_copies->text();
        QString des = ui->textEdit_description->toPlainText();

            QSqlQuery qry(dEntry);
            qry.prepare("INSERT INTO books(username,password,first_name,middle_name,last_name,user_email,date_of_birth,phone_number)""VALUES(:username,:password,:first_name,:middle_name,:last_name,:user_email,:date_of_birth,:phone_number)");
            qry.bindValue(":username",user);
            qry.bindValue(":password",password);
            qry.bindValue(":first_name",fN);
            qry.bindValue(":middle_name",mN);
            qry.bindValue(":last_name",lN);
            qry.bindValue(":date_of_birth",dob);
            qry.bindValue(":user_email",email);
            qry.bindValue(":phone_number",pNum);

            if(qry.exec())
            {
                QMessageBox::information(this,"Sign Up","Signed up successfully.");
                QSqlDatabase::removeDatabase("QMYSQL");
            }
            else
            {
                QMessageBox::warning(this,"Sign Up","Signed up failed.");
                QSqlDatabase::removeDatabase("QMYSQL");
            }
        }
        QSqlDatabase::removeDatabase("QMYSQL");
    }
    dEntry.close();
}

