#include "entry.h"
#include "ui_entry.h"
#include "homepage.h"
#include "adminpannel.h"
#include "mainwindow.h"

HomePage *hp2;
adminpannel *adm;
template<class t>
int countDigit(t n)
{
   int a=0;
   while(n!=0)
   {
       a++;
       n=n/10;
   }
   return a;
}
entry::entry(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::entry)
{
    ui->setupUi(this);
    this->setWindowTitle("LibMan");
    this->setWindowIcon(QIcon(":/rec/drive-download-20221026T014232Z-001/Logo no BG and text.png"));
}

entry::~entry()
{
    delete ui;
}




void entry::on_pushButton_clicked()
{
    dEntry = QSqlDatabase::addDatabase("QMYSQL","Entry");
    dEntry.setHostName("127.0.0.1");
    dEntry.setUserName("root");
    dEntry.setPassword("rampyari1234");
    dEntry.setDatabaseName("libman");

    if(dEntry.open())
    {
        QString bN = ui->lineEdit_name->text();
        QString aN = ui->lineEdit_author->text();
        QString pD = ui->lineEdit_year->text();
        int yr=ui->lineEdit_year->text().toInt();
        QString iN = ui->lineEdit_isbn->text();
        long long chk = ui->lineEdit_isbn->text().toLongLong();
        QString pB = ui->lineEdit_pub->text();
        QString nC = ui->lineEdit_copies->text();
        QString nP = ui->lineEdit_page->text();
        QString des = ui->textEdit_description->toPlainText();
        QDate today=QDate::currentDate();

        if(countDigit<long long>(chk)!=13)
            QMessageBox::warning(this,"Error","ISBN number is not correct. Please try again.");
        else if(countDigit<int>(yr)!=4)
            QMessageBox::warning(this,"Error","Date is not correct. Please try again.");
        else
        {
            QSqlQuery qry(dEntry);
            qry.prepare("INSERT INTO books(isbn_no,title,author,pages,published_date,published_by,num_copies,date_added)""VALUES(:isbn_no,:title,:author,:pages,:published_date,:published_by,:num_copies,:date_added)");
            qry.bindValue(":title",bN);
            qry.bindValue(":author",aN);
            qry.bindValue(":pages",nP);
            qry.bindValue(":isbn_no",iN);
            qry.bindValue(":published_date",pD);
            qry.bindValue(":published_by",pB);
            qry.bindValue(":num_copies",nC);
            qry.bindValue(":date_added",today);

            if(qry.exec())
            {
                QMessageBox::information(this,"Entry","Book entered");
                QSqlDatabase::removeDatabase("QMYSQL");
                //hide();
                //hp2=new HomePage(this);
               // hp2->show();

            }
            else
            {
                qDebug() << qry.lastError().text()<<Qt::endl;
                QMessageBox::warning(this,"Entry","Entry failed.");
                QSqlDatabase::removeDatabase("QMYSQL");

            }
        }
        QSqlDatabase::removeDatabase("QMYSQL");

    }
}







void entry::on_pushButton_2_clicked()
{
    close();
}


void entry::on_lineEdit_name_returnPressed()
{
    on_pushButton_clicked();
}


void entry::on_lineEdit_author_returnPressed()
{
    on_pushButton_clicked();
}


void entry::on_lineEdit_year_returnPressed()
{
    on_pushButton_clicked();
}


void entry::on_lineEdit_isbn_returnPressed()
{
    on_pushButton_clicked();
}


void entry::on_lineEdit_pub_returnPressed()
{
    on_pushButton_clicked();
}


void entry::on_lineEdit_copies_returnPressed()
{
    on_pushButton_clicked();
}


void entry::on_lineEdit_page_returnPressed()
{
    on_pushButton_clicked();
}

