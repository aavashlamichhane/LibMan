#include "homepage.h"
#include "ui_homepage.h"
#include"mainwindow.h"


#include<QMessageBox>

HomePage::HomePage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HomePage)
{
    ui->setupUi(this);
    QSqlDatabase data = QSqlDatabase::addDatabase("QMYSQL","Home");
    data.setHostName("127.0.0.1");
    data.setUserName("root");
    data.setPassword("rampyari1234");
    data.setDatabaseName("libman");
    data.open();
    QSqlQuery query(data);
    extern QString usernameg;
    QString aux;
    query.prepare("SELECT username FROM userbase WHERE username=:username");
    query.bindValue(":username",usernameg);
    query.exec();
    query.first();
    aux = query.value(0).toString() ;
    ui->label_name->setText(aux);
    if(!query.isActive())
    {
        QMessageBox::information(0,"Bad Query", "BAD Query. It's not active");
    }
}

HomePage::~HomePage()
{
    delete ui;
}

void HomePage::on_pushButton_settings_clicked()
{
    hide();
    settings =new Settings(this);
    settings->show();
}


void HomePage::on_pushButton_user_clicked()
{
    hide();
    info = new UserInfo(this);
    info->show();
}


void HomePage::on_pushButton_adminpanel_clicked()
{
    hide();
    newbook =new entry(this);
    newbook->show();
}



void HomePage::on_pushButton_search_clicked()
{
    data.open();

    QString title=ui->lineEdit_search->text();
    QSqlQuery query_search(QSqlDatabase::database("LibMan"));
    query_search.prepare(QString("SELECT * FROM books WHERE title=:title"));
    query_search.bindValue(":title",title);

    while(query_search.next())
    {
        QString bookname=query_search.value(0).toString();

        int check=QString :: compare(title,bookname,Qt::CaseInsensitive);

        if(check==0)
        {
            if(ui->scrollcontent->layout()!=NULL)
            {
                QLayoutItem *item;

                while((item=ui->scrollcontent->layout()->takeAt(0))!=NULL)
                {
                    delete item->widget();
                    delete item;
                }
                delete ui->scrollcontent->layout();
            }

        }
        else
        {

        }
    }

}

