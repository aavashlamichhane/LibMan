#include "updatebook.h"
#include "ui_updatebook.h"
#include "adminpannel.h"

adminpannel *panel;

UpdateBook::UpdateBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateBook)
{
    ui->setupUi(this);
    this->setWindowTitle("LibMan");
}

UpdateBook::~UpdateBook()
{
    delete ui;
}

void UpdateBook::on_pushButton_clicked()
{
    daub = QSqlDatabase::addDatabase("QMYSQL","Book_Update");
    daub.setHostName("127.0.0.1");
    daub.setUserName("root");
    daub.setPassword("rampyari1234");
    daub.setDatabaseName("libman");
    daub.open();

    QString iN = ui->lineEdit_num->text();
    int num=ui->lineEdit_copy->text().toInt();
    QSqlQuery qry_upd(daub),qry_upt(daub);
    qry_upd.prepare("SELECT num_copies FROM books WHERE isbn_no=:isbn_no");
    qry_upd.bindValue(":isbn_no",iN);
    if(!qry_upd.exec())
        QMessageBox::warning(this,"Update","Try again");
    else
    {
        if(!qry_upd.next())
            QMessageBox::warning(this,"Update","Book doesn't exist.");
        else
        {
            int copy= qry_upd.value(0).toString().toInt()+num;
            qry_upt.prepare("UPDATE books SET num_copies=:num_copies WHERE isbn_no=:isbn_no");
            qry_upt.bindValue(":num_copies",copy);
            qry_upt.bindValue(":isbn_no",iN);
            if(qry_upt.exec())
                QMessageBox::information(this,"Update","Book updated.");
            else
                QMessageBox::warning(this,"Update","Book update failed.");
        }
    }

}





void UpdateBook::on_pushButton_back_clicked()
{
    close();
}

