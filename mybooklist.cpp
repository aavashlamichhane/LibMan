#include "mybooklist.h"
#include "ui_mybooklist.h"

mybooklist::mybooklist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mybooklist)
{
    ui->setupUi(this);
    dal = QSqlDatabase::addDatabase("QMYSQL","List");
    dal.setHostName("127.0.0.1");
    dal.setUserName("root");
    dal.setPassword("rampyari1234");
    dal.setDatabaseName("libman");
    dal.open();
    QSqlQueryModel *modal=new QSqlQueryModel();
    QSqlQuery *qry= new QSqlQuery(dal);
    extern QString usernameg;
    qry->prepare("SELECT * FROM borrows WHERE username=:username");
    qry->bindValue(":username",usernameg);
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
}

mybooklist::~mybooklist()
{
    delete ui;
}

void mybooklist::on_pushButton_load_clicked()
{
//    mybooklist conn;
//    QSqlQueryModel * model=new QSqlQueryModel();

//    conn.connOpen();
//    QSqlQuery * qry=new QSqlQuery(conn.db);

//            qry->prepare("Select * from books");

//            qry->exec();
//            model->setQuery(*qry);
//            ui->tableView->setModel(model);

//    conn.connClose();
//    qDebug() <<(model->rowCount());
}

