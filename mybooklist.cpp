#include "mybooklist.h"
#include "ui_mybooklist.h"

mybooklist::mybooklist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mybooklist)
{
    ui->setupUi(this);
}

mybooklist::~mybooklist()
{
    delete ui;
}

void mybooklist::on_pushButton_load_clicked()
{
    mybooklist conn;
    QSqlQueryModel * model=new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery * qry=new QSqlQuery(conn.db);

            qry->prepare("Select * from books");

            qry->exec();
            model->setQuery(*qry);
            ui->tableView->setModel(model);

    conn.connClose();
    qDebug() <<(model->rowCount());
}

