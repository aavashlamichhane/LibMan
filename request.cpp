#include "request.h"
#include "ui_request.h"

Request::Request(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Request)
{
    ui->setupUi(this);
    this->setWindowTitle("LibMan");
    this->setWindowIcon(QIcon(":/rec/drive-download-20221026T014232Z-001/Logo no BG and text.png"));
}

Request::~Request()
{
    delete ui;
}

template<class tt>
int countDigitss(tt n)
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
        QString date=ui->lineEdit_year->text();
        QString pub=ui->lineEdit_pub->text();
        long long chk = ui->lineEdit_num->text().toLongLong();
        int year=ui->lineEdit_year->text().toInt();
        QString iN=ui->lineEdit_num->text();
        QSqlQuery qryc(drequest);
        qryc.prepare("SELECT * FROM books WHERE isbn_no=:isbn_no");
        qryc.bindValue(":isbn_no",iN);
        qryc.exec();
        if(countDigitss<long long>(chk)!=13)
            QMessageBox::warning(this,"Error","ISBN number is not correct. Please try again.");
        else if(qryc.next())
            QMessageBox::warning(this,"Error","Book already exists.");
        else if(countDigitss<int>(year)!=4)
            QMessageBox::warning(this,"Error","Year is not correct. Please try again.");
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
                close();
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


