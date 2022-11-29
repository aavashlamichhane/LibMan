#include "returnbook.h"
#include "ui_returnbook.h"
#include "adminpannel.h"

adminpannel *pan;

returnBook::returnBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::returnBook)
{
    ui->setupUi(this);
    ui->dateEdit_issue->setDate(QDate::currentDate());
    this->setWindowTitle("LibMan");
    this->setWindowIcon(QIcon(":/rec/drive-download-20221026T014232Z-001/Logo no BG and text.png"));
}

returnBook::~returnBook()
{
    delete ui;
}




void returnBook::on_pushButton_clicked()
{
    daret = QSqlDatabase::addDatabase("QMYSQL","return");
    daret.setHostName("127.0.0.1");
    daret.setUserName("root");
    daret.setPassword("rampyari1234");
    daret.setDatabaseName("libman");
    daret.open();

    QString uN=ui->lineEdit_user->text();
    QString isbn=ui->lineEdit_isbn->text();
    QDate dret=ui->dateEdit_issue->date();

    QSqlQuery qry_ret(daret),qry_book(daret),qry_upt(daret),qry_upt1(daret);
    qry_ret.prepare("SELECT * FROM borrows WHERE username=:username AND isbn_no=:isbn_no");
    qry_ret.bindValue(":username",uN);
    qry_ret.bindValue(":isbn_no",isbn);
    qry_ret.exec();
    if(!qry_ret.next())
        QMessageBox::warning(this,"Return","Book not issued to given user.");
    else if(!dret.isValid())
        QMessageBox::warning(this,"Error","Invalid Date.");
    else
    {
        qry_upt.prepare("UPDATE borrows SET date_returned=:date_returned WHERE username=:username AND isbn_no=:isbn_no");
        qry_book.prepare("SELECT num_copies FROM books WHERE isbn_no=:isbn_no");
        qry_book.bindValue(":isbn_no",isbn);
        qry_upt.bindValue(":username",uN);
        qry_upt.bindValue(":isbn_no",isbn);
        qry_upt.bindValue(":date_returned",dret);

        if(qry_upt.exec() && qry_book.exec())
        {
            qry_book.next();
            qry_upt1.prepare("UPDATE books SET num_copies=:num_copies WHERE isbn_no=:isbn_no");
            int copies=qry_book.value(0).toString().toInt();
            copies++;
            qry_upt1.bindValue(":isbn_no",isbn);
            qry_upt1.bindValue(":num_copies",copies);
            qry_upt1.exec();
            QMessageBox::information(this,"Return","Book returned successfully.");
        }
        else
            QMessageBox::warning(this,"Return","Book return failed.");
    }

}


void returnBook::on_pushButton_back_clicked()
{
    close();
}

