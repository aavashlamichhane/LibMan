#include "studenthomepage.h"
#include "ui_studenthomepage.h"

studentHomePage::studentHomePage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::studentHomePage)
{
    ui->setupUi(this);
    /*QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("rampyari1234");
    db.setDatabaseName("libman");
    if(db.open())
    {
        query_stdhome = new QSqlQueryModel();
        query_stdhome->setQuery("SELECT * FROM books");
        ui->tableView_new->setModel(query_stdhome);
    }
    else
    {
       QMessageBox::warning(this,"Connection","Database not connected.");
    }*/
}

studentHomePage::~studentHomePage()
{
    delete ui;
}
