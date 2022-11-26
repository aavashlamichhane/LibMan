#include "bookissue.h"
#include "ui_bookissue.h"

bookissue::bookissue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bookissue)
{
    ui->setupUi(this);
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

}

