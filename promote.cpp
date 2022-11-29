#include "promote.h"
#include "ui_promote.h"
#include "adminpannel.h"

adminpannel *apl;

promote::promote(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::promote)
{
    ui->setupUi(this);
    this->setWindowTitle("LibMan");
}

promote::~promote()
{
    delete ui;
}

void promote::on_pushButton_clicked()
{
    dap = QSqlDatabase::addDatabase("QMYSQL","promote");
    dap.setHostName("127.0.0.1");
    dap.setUserName("root");
    dap.setPassword("rampyari1234");
    dap.setDatabaseName("libman");
    dap.open();

    QString uN=ui->lineEdit_user->text();

    QSqlQuery qry_pr(dap),qry_up(dap);

    qry_pr.prepare("SELECT user_key FROM userbase WHERE username=:username");
    qry_pr.bindValue(":username",uN);
    if(!qry_pr.exec())
    {
        QMessageBox::warning(this,"Promotion","Promotion failed.");
    }
    else
    {
        if(qry_pr.next())
        {
            int a=qry_pr.value(0).toString().toInt();
            if(a==1)
                QMessageBox::information(this,"Promotion","Given user aldeary has admin access.");
            else
            {
                qry_up.prepare("UPDATE userbase SET user_key=1 WHERE username=:username");
                qry_up.bindValue(":username",uN);
                if(qry_up.exec())
                    QMessageBox::information(this,"Promotion","Promotion successful.");
                else
                    QMessageBox::warning(this,"Promotion","Promotion failed.");
            }
        }
    }

}




void promote::on_pushButton_back_clicked()
{
    close();
}

