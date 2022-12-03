#include "issuerecords.h"
#include "ui_issuerecords.h"

IssueRecords::IssueRecords(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IssueRecords)
{
    ui->setupUi(this);
    this->setWindowTitle("LibMan");
    this->setWindowIcon(QIcon(":/rec/drive-download-20221026T014232Z-001/Logo no BG and text.png"));
    daib = QSqlDatabase::addDatabase("QMYSQL","IList");
    daib.setHostName("127.0.0.1");
    daib.setUserName("root");
    daib.setPassword("rampyari1234");
    daib.setDatabaseName("libman");
    daib.open();
    QSqlQuery *qry= new QSqlQuery(daib);

    qry->prepare("SELECT * FROM borrows ORDER BY record_no");

    qry->exec();
    modal->setQuery(*qry);
    modal->setHeaderData(0, Qt::Horizontal, tr("Record Number"));
    modal->setHeaderData(1, Qt::Horizontal, tr("Username"));
    modal->setHeaderData(2, Qt::Horizontal, tr("Book Title"));
    modal->setHeaderData(3, Qt::Horizontal, tr("ISBN"));
    modal->setHeaderData(4, Qt::Horizontal, tr("Date Taken"));
    modal->setHeaderData(5, Qt::Horizontal, tr("Date Returned"));
    modal->setHeaderData(6, Qt::Horizontal, tr("Expiry Date"));
    ui->tableView->setModel(modal);
    ui->tableView->resizeColumnsToContents();
}

IssueRecords::~IssueRecords()
{
    delete ui;
}

void IssueRecords::on_pushButton_update_clicked()
{
    QSqlQuery *un= new QSqlQuery(daib);
    if(ui->comboBox->currentText()=="Username")
    {
        un->prepare("SELECT * FROM borrows WHERE username=:username ORDER BY date_taken");
        un->bindValue(":username",ui->lineEdit->text());
        un->exec();
        modal->setQuery(*un);
        modal->setHeaderData(0, Qt::Horizontal, tr("Record Number"));
        modal->setHeaderData(1, Qt::Horizontal, tr("Username"));
        modal->setHeaderData(2, Qt::Horizontal, tr("Book Title"));
        modal->setHeaderData(3, Qt::Horizontal, tr("ISBN"));
        modal->setHeaderData(4, Qt::Horizontal, tr("Date Taken"));
        modal->setHeaderData(5, Qt::Horizontal, tr("Date Returned"));
        modal->setHeaderData(6, Qt::Horizontal, tr("Expiry Date"));
        ui->tableView->setModel(modal);
        ui->tableView->resizeColumnsToContents();
    }
    else if(ui->comboBox->currentText()=="ISBN")
    {
        un->prepare("SELECT * FROM borrows WHERE isbn_no=:isbn_no ORDER BY date_taken");
        un->bindValue(":isbn_no",ui->lineEdit->text());
        un->exec();
        modal->setQuery(*un);
        modal->setHeaderData(0, Qt::Horizontal, tr("Record Number"));
        modal->setHeaderData(1, Qt::Horizontal, tr("Username"));
        modal->setHeaderData(2, Qt::Horizontal, tr("Book Title"));
        modal->setHeaderData(3, Qt::Horizontal, tr("ISBN"));
        modal->setHeaderData(4, Qt::Horizontal, tr("Date Taken"));
        modal->setHeaderData(5, Qt::Horizontal, tr("Date Returned"));
        modal->setHeaderData(6, Qt::Horizontal, tr("Expiry Date"));
        ui->tableView->setModel(modal);
        ui->tableView->resizeColumnsToContents();
    }

}


void IssueRecords::on_lineEdit_returnPressed()
{
    on_pushButton_update_clicked();
}

