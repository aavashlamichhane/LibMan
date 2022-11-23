#include "entry.h"
#include "ui_entry.h"
#include "homepage.h"
#include "mainwindow.h"

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
        QString nP = ui->lineEdit_page->text();
        QString des = ui->textEdit_description->toPlainText();

            QSqlQuery qry(dEntry);
            qry.prepare("INSERT INTO books(isbn_no,title,author,pages,published_date,published_by,num_copies,description)""VALUES(:isbn_no,:title,:author,:pages,:published_date,:published_by,:num_copies,:description)");
            qry.bindValue(":title",bN);
            qry.bindValue(":author",aN);
            qry.bindValue(":pages",nP);
            qry.bindValue(":isbn_no",iN);
            qry.bindValue(":published_date",pD);
            qry.bindValue(":published_by",pB);
            qry.bindValue(":num_copies",nC);
            qry.bindValue(":description",des);

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
                QMessageBox::warning(this,"Entry","Entry failed.");
                QSqlDatabase::removeDatabase("QMYSQL");
            }
        }
        QSqlDatabase::removeDatabase("QMYSQL");
}

