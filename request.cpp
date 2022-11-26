#include "request.h"
#include "ui_request.h"

Request::Request(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Request)
{
    ui->setupUi(this);
}

Request::~Request()
{
    delete ui;
}

int countDigitss(long long n)
{
   int a=0;
   while(n!=0)
   {
       a++;
       n=n/10;
   }
   return a;
}
void Request::on_pushButton_clicked()
{
    drequest = QSqlDatabase::addDatabase("QMYSQL","Request");
    drequest.setHostName("127.0.0.1");
    drequest.setUserName("root");
    drequest.setPassword("rampyari1234");
    drequest.setDatabaseName("libman");

    if(drequest.open())
    {
        QString bN=ui->lineEdit_name->text();
        QString aN=ui->lineEdit_aname->text();
        QDate date=ui->dateEdit->date();
        QString pub=ui->lineEdit_pub->text();
        long long chk = ui->lineEdit_num->text().toLongLong();
        QString iN=ui->lineEdit_num->text();
        if(countDigitss(chk)!=13)
            QMessageBox::warning(this,"Error","ISBN number is not correct. Please try again.");
        else
        {
            QSqlQuery qry(drequest);
            qry.prepare("INSERT INTO request(isbn_num,book_name,author_name,date,publication)""VALUES(:isbn_num,:book_name,:author_name,:date,:publication)");
            qry.bindValue(":book_name",bN);
            qry.bindValue(":author_name",aN);

            qry.bindValue(":isbn_num",iN);
            qry.bindValue(":date",date);
            qry.bindValue(":publication",pub);


            if(qry.exec())
            {
                QMessageBox::information(this,"Request","Book request successful.");
                QSqlDatabase::removeDatabase("QMYSQL");
                //hide();
                //hp2=new HomePage(this);
               // hp2->show();

            }
            else
            {
                qDebug() << qry.lastError().text()<<Qt::endl;
                QMessageBox::warning(this,"Request","Book request failed.");
                QSqlDatabase::removeDatabase("QMYSQL");

            }
        }
        QSqlDatabase::removeDatabase("QMYSQL");
        }
}


