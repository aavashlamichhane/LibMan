#include "studenthomepage.h"
#include "ui_studenthomepage.h"
#include"mainwindow.h"
#include <QSqlQueryModel>


studentHomePage::studentHomePage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::studentHomePage)
{
    ui->setupUi(this);
    data = QSqlDatabase::addDatabase("QMYSQL","sHome");
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

studentHomePage::~studentHomePage()
{
    delete ui;
}

void studentHomePage::on_pushButton_settings_clicked()
{
    hide();
    settings =new Settings(this);
    settings->show();
}


void studentHomePage::on_pushButton_user_clicked()
{
    hide();
    info = new UserInfo(this);
    info->show();
}





void studentHomePage::on_pushButton_search_clicked()
{
    data.open();

    QString opp = ui->comboBox_searchopption->currentText();



    QSqlQueryModel *modal= new QSqlQueryModel();
    QSqlQueryModel *modal1= new QSqlQueryModel();
    QSqlQueryModel *modal2= new QSqlQueryModel();

    QSqlQuery *title= new QSqlQuery(data);
    QSqlQuery *isbn_no= new QSqlQuery(data);
    QSqlQuery *author= new QSqlQuery(data);

    title->prepare("SELECT title FROM books");
    isbn_no->prepare("SELECT isbn_no FROM books");
    author->prepare("SELECT author FROM books");

    title->exec();
    isbn_no->exec();
    author->exec();

    modal->setQuery(std::move(*title));
    modal1->setQuery(std::move(*isbn_no));
    modal2->setQuery(std::move(*author));
    QVBoxLayout *lay=new QVBoxLayout(this);
    QString search=ui->lineEdit_search->text();
    QPushButton *label;



    for(int j=0;j<=modal->rowCount();j++)
    {
        QString strtitle=modal->record(j).value(0).toString();
        QString strisbn=modal1->record(j).value(0).toString();
        QString strauthor=modal2->record(j).value(0).toString();

        if(opp=="Name")
        {

            int check = QString::compare(search, strtitle, Qt::CaseInsensitive);

            if(check==0)
            {

                if ( ui->scrollcontent->layout() != NULL )
                {
                    QLayoutItem* item;
                    while ( ( item = ui->scrollcontent->layout()->takeAt( 0 ) ) != NULL )
                    {
                        delete item->widget();
                        delete item;
                    }
                delete ui->scrollcontent->layout();
                }

                ui->frame_display->setGeometry(10,50,900,550);

                label=new QPushButton(strtitle);
                label->setObjectName(strtitle);

                QLabel *lab=new QLabel("ISBN NUM: "+strisbn+", Author: "+strauthor+".");
                QFrame *line=new QFrame;
                line->setFrameShape(QFrame::HLine);
                line->setFrameShadow(QFrame::Sunken);

                lay->addWidget(label);
                lay->addWidget(lab);
                lay->addWidget(line);
            }
        }

        else if(opp=="Author")
        {
            int check = QString::compare(search, strauthor, Qt::CaseInsensitive);

            if(check==0)
            {

                if ( ui->scrollcontent->layout() != NULL )
                {
                    QLayoutItem* item;
                    while ( ( item = ui->scrollcontent->layout()->takeAt( 0 ) ) != NULL )
                    {
                        delete item->widget();
                        delete item;
                    }
                    delete ui->scrollcontent->layout();
                }

                ui->frame_display->setGeometry(10,50,900,550);

                label=new QPushButton(strtitle);
                label->setObjectName(strtitle);

                QLabel *lab=new QLabel("ISBN NUM: "+strisbn+", Author: "+strauthor+".");
                QFrame *line=new QFrame;
                line->setFrameShape(QFrame::HLine);
                line->setFrameShadow(QFrame::Sunken);

                lay->addWidget(label);
                lay->addWidget(lab);
                lay->addWidget(line);
            }
        }

        else if(opp=="Code")
            {
                int check = QString::compare(search, strisbn, Qt::CaseInsensitive);
                if(check==0)
                {

                    if ( ui->scrollcontent->layout() != NULL )
                    {
                        QLayoutItem* item;
                        while ( ( item = ui->scrollcontent->layout()->takeAt( 0 ) ) != NULL )
                        {
                            delete item->widget();
                            delete item;
                        }
                        delete ui->scrollcontent->layout();
                    }

                    ui->frame_display->setGeometry(10,50,900,550);

                    label=new QPushButton(strtitle);
                    label->setObjectName(strtitle);

                    QLabel *lab=new QLabel("ISBN NUM: "+strisbn+", Author: "+strauthor+".");
                    QFrame *line=new QFrame;
                    line->setFrameShape(QFrame::HLine);
                    line->setFrameShadow(QFrame::Sunken);

                    lay->addWidget(label);
                    lay->addWidget(lab);
                    lay->addWidget(line);
                }
            }

    ui->scrollcontent->setLayout(lay);
    //ui->scrollContents->setStyleSheet("background: transparent;border-color: rgb(62, 62, 62);padding-left:20px;padding-top:20px");
    ui->scrollcontent->setVisible(true);
    ui->scrollcontent->show();
    }

}


