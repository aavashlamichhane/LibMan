#include "booklist.h"
#include "ui_booklist.h"

booklist::booklist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::booklist)
{
    ui->setupUi(this);
    dalb = QSqlDatabase::addDatabase("QMYSQL","BList");
    dalb.setHostName("127.0.0.1");
    dalb.setUserName("root");
    dalb.setPassword("rampyari1234");
    dalb.setDatabaseName("libman");
    dalb.open();
    QSqlQueryModel *modal=new QSqlQueryModel();
    QSqlQuery *qry= new QSqlQuery(dalb);

    qry->prepare("SELECT isbn_no,title,author,pages,published_date,published_by,num_copies FROM books");

    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
}

booklist::~booklist()
{
    delete ui;
}
