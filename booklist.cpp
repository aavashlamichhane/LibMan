#include "booklist.h"
#include "ui_booklist.h"

booklist::booklist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::booklist)
{
    ui->setupUi(this);
    this->setWindowTitle("LibMan");
    dalb = QSqlDatabase::addDatabase("QMYSQL","BList");
    dalb.setHostName("127.0.0.1");
    dalb.setUserName("root");
    dalb.setPassword("rampyari1234");
    dalb.setDatabaseName("libman");
    dalb.open();
    QSqlQueryModel *modal=new QSqlQueryModel();
    QSqlQuery *qry= new QSqlQuery(dalb);

    qry->prepare("SELECT isbn_no,title,author,pages,published_date,published_by,num_copies FROM books ORDER BY title");

    qry->exec();
    modal->setQuery(*qry);
    modal->setHeaderData(0, Qt::Horizontal, tr("ISBN"));
    modal->setHeaderData(1, Qt::Horizontal, tr("Book Title    "));
    modal->setHeaderData(2, Qt::Horizontal, tr("Author   "));
    modal->setHeaderData(3, Qt::Horizontal, tr("No. of pages"));
    modal->setHeaderData(4, Qt::Horizontal, tr("Published Year"));
    modal->setHeaderData(5, Qt::Horizontal, tr("Publication"));
    modal->setHeaderData(6, Qt::Horizontal, tr("Number of Copies"));
    ui->tableView->setModel(modal);
    ui->tableView->resizeColumnsToContents();
}

booklist::~booklist()
{
    delete ui;
}
