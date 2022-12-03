#include "bookissue.h"
#include "ui_bookissue.h"
#include "adminpannel.h"

adminpannel *app;

bookissue::bookissue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bookissue)
{
    ui->setupUi(this);
    this->setWindowTitle("LibMan");
    this->setWindowIcon(QIcon(":/rec/drive-download-20221026T014232Z-001/Logo no BG and text.png"));
    ui->dateEdit_issue->setDate(QDate::currentDate());
    ui->dateEdit_expiry->setDate(QDate::currentDate().addDays(30));
}

bookissue::~bookissue()
{
    delete ui;
}


void bookissue::on_pushButton_clicked()
{
    dabook = QSqlDatabase::addDatabase("QMYSQL","issue");
    dabook.setHostName("127.0.0.1");
    dabook.setUserName("root");
    dabook.setPassword("rampyari1234");
    dabook.setDatabaseName("libman");
    dabook.open();

    QString uN=ui->lineEdit_user->text();
    QString isbn=ui->lineEdit_isbn->text();
    QDate diss=ui->dateEdit_issue->date();
    QDate dexp=ui->dateEdit_expiry->date();
    int a=1;

    QSqlQuery qry_user(dabook),qry_book(dabook),qry_in(dabook),qry_chk(dabook);
    qry_user.prepare(QString("SELECT username FROM userbase WHERE username=:username"));
    qry_book.prepare("SELECT isbn_no,title,num_copies FROM books WHERE isbn_no=:isbn_no");
    qry_chk.prepare("SELECT date_returned FROM borrows WHERE username=:username AND isbn_no=:isbn_no");
    qry_chk.bindValue(":username",uN);
    qry_chk.bindValue(":isbn_no",isbn);
    qry_user.bindValue(":username",uN);
    qry_book.bindValue(":isbn_no",isbn);
    qry_user.exec();
    qry_book.exec();
    qry_chk.exec();
    if(!qry_user.next())
        QMessageBox::warning(this,"Issue","Username does not match.");
    else if(!qry_book.next())
    {
        QMessageBox::warning(this,"Issue","Book does not match.");
        qDebug() << qry_book.lastError().text()<<Qt::endl;
    }
    else if(!(diss.isValid() && dexp.isValid()))
        QMessageBox::warning(this,"Error","Invalid Date.");
    else if(qry_chk.next())
    {
        QDate da=qry_chk.value(0).toDate();
        QDate daa(0000,00,00);
        if(da==daa)
            QMessageBox::warning(this,"Issue","Book already issued.");
        else
            goto hihi;
    }
    else if(a==0)
    {
        haha:
        QMessageBox::warning(this,"Issue","Book unavailable.");
    }
    else
    {
        hihi:
        QString title=qry_book.value(1).toString();
        int copies=qry_book.value(2).toString().toInt();
        if(copies==0)
            goto haha;
        copies--;
        qry_in.prepare("INSERT INTO borrows(username,book_name,isbn_no,date_taken,date_tobeReturned)""VALUES(:username,:book_name,:isbn_no,:date_taken,:date_tobeReturned)");
        qry_in.bindValue(":username",uN);
        qry_in.bindValue(":book_name",title);
        qry_in.bindValue(":isbn_no",isbn);
        qry_in.bindValue(":date_taken",diss);
        qry_in.bindValue(":date_tobeReturned",dexp);
        if(qry_in.exec())
        {
            QMessageBox::information(this,"Issue","Book issue successful.");
            QSqlQuery qry_cop(dabook);
            qry_cop.prepare("UPDATE books SET num_copies=:num_copies WHERE isbn_no=:isbn_no");
            qry_cop.bindValue(":num_copies",copies);
            qry_cop.bindValue(":isbn_no",isbn);
            qry_cop.exec();
            QSqlDatabase::removeDatabase("issue");

        }
        else
        {
            qDebug() << qry_in.lastError().text()<<Qt::endl<<title<<dexp;
            QMessageBox::warning(this,"Issue","Book issue failed.");
            QSqlDatabase::removeDatabase("issue");
        }
    }
}




void bookissue::on_pushButton_back_clicked()
{
    close();
}


void bookissue::on_lineEdit_user_returnPressed()
{
    on_pushButton_clicked();
}


void bookissue::on_lineEdit_isbn_returnPressed()
{
    on_pushButton_clicked();
}

