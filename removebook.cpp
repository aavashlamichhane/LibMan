#include "removebook.h"
#include "ui_removebook.h"


removebook::removebook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::removebook)
{
    ui->setupUi(this);
    this->setWindowTitle("LibMan");
    this->setWindowIcon(QIcon(":/rec/drive-download-20221026T014232Z-001/Logo no BG and text.png"));
}

removebook::~removebook()
{
    delete ui;


}

void removebook::on_pushButton_back_clicked()
{
    close();
}



void removebook::on_pushButton_clicked()
{
    daret = QSqlDatabase::addDatabase("QMYSQL","return");
    daret.setHostName("127.0.0.1");
    daret.setUserName("root");
    daret.setPassword("rampyari1234");
    daret.setDatabaseName("libman");
    daret.open();

    QString iN = ui->lineEdit_isbn->text();
    QSqlQuery qry_del(daret),qry_remo(daret);
    qry_del.prepare("SELECT isbn_no FROM books WHERE isbn_no=:isbn_no");
    qry_del.bindValue(":isbn_no",iN);
    if(!qry_del.exec())
        QMessageBox::warning(this,"Remove","Try again");
    else
    {
        if(!qry_del.next())
            QMessageBox::warning(this,"Remove","Book doesn't exist.");
        else
        {
            qry_remo.prepare("DELETE FROM books WHERE isbn_no=:isbn_no");
            if(qry_remo.exec())
                QMessageBox::information(this,"Remove","Book removed.");
            else
                QMessageBox::warning(this,"Remove","Book remove failed.");
        }
    }


}


void removebook::on_lineEdit_isbn_returnPressed()
{
    on_pushButton_clicked();
}

