#include "chkreq.h"
#include "ui_chkreq.h"

chkreq::chkreq(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chkreq)
{
    ui->setupUi(this);
    dala = QSqlDatabase::addDatabase("QMYSQL","rList");
    dala.setHostName("127.0.0.1");
    dala.setUserName("root");
    dala.setPassword("rampyari1234");
    dala.setDatabaseName("libman");
    dala.open();
    QSqlQueryModel *modal=new QSqlQueryModel();
    QSqlQuery *qry= new QSqlQuery(dala);

    qry->prepare("SELECT * FROM request");

    qry->exec();
    modal->setQuery(*qry);
    modal->setHeaderData(0, Qt::Horizontal, tr("Book Name"));
    modal->setHeaderData(1, Qt::Horizontal, tr("Author"));
    modal->setHeaderData(2, Qt::Horizontal, tr("Date Published"));
    modal->setHeaderData(3, Qt::Horizontal, tr("Publication"));
    modal->setHeaderData(4, Qt::Horizontal, tr("ISBN"));

    ui->tableView->setModel(modal);
}

chkreq::~chkreq()
{
    delete ui;
}
