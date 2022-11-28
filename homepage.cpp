#include "homepage.h"
#include "ui_homepage.h"
#include <QSqlQueryModel>


#include<QMessageBox>


HomePage::HomePage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HomePage)
{


    ui->setupUi(this);\



    data = QSqlDatabase::addDatabase("QMYSQL","Home");
    data.setHostName("127.0.0.1");
    data.setUserName("root");
    data.setPassword("rampyari1234");
    data.setDatabaseName("libman");
    data.open();
    QSqlQuery query(data),qry_lat(data);
    extern QString usernameg;
    QString aux;
    query.prepare("SELECT username FROM userbase WHERE username=:username");
    query.bindValue(":username",usernameg);
    query.exec();
    query.first();
    aux = query.value(0).toString() ;
    ui->label_name->setText(aux);
    qry_lat.prepare("SELECT isbn_no,title,author FROM books ORDER BY date_added desc");
    qry_lat.exec();
    qry_lat.first();
    QString isbn[5],title[5],aname[5];
    for(int i=1;i<=5;i++)
    {
        isbn[i-1]=qry_lat.value(0).toString();
        title[i-1]=qry_lat.value(1).toString();
        aname[i-1]=qry_lat.value(2).toString();
        qry_lat.next();
    }
    ui->label_b1->setText("Book : "+title[0]);
    ui->label_a1->setText("Author : "+aname[0]);
    ui->label_i1->setText("ISBN Num : "+isbn[0]);
    ui->label_b2->setText("Book : "+title[1]);
    ui->label_a2->setText("Author : "+aname[1]);
    ui->label_i2->setText("ISBN Num : "+isbn[1]);
    ui->label_b3->setText("Book : "+title[2]);
    ui->label_a3->setText("Author : "+aname[2]);
    ui->label_i3->setText("ISBN Num : "+isbn[2]);
    ui->label_b4->setText("Book : "+title[3]);
    ui->label_a4->setText("Author : "+aname[3]);
    ui->label_i4->setText("ISBN Num : "+isbn[3]);
    ui->label_b5->setText("Book : "+title[4]);
    ui->label_a5->setText("Author : "+aname[4]);
    ui->label_i5->setText("ISBN Num : "+isbn[4]);
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
    close();
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
    admin =new adminpannel(this);
    admin->show();
}



void HomePage::on_pushButton_search_clicked()
{
    data.open();

    QString opp = ui->comboBox_searchopption->currentText();



    QSqlQueryModel *modal= new QSqlQueryModel();
    QSqlQueryModel *modal1= new QSqlQueryModel();
    QSqlQueryModel *modal2= new QSqlQueryModel();
    QSqlQueryModel *modal3= new QSqlQueryModel();


    QSqlQuery *title= new QSqlQuery(data);
    QSqlQuery *isbn_no= new QSqlQuery(data);
    QSqlQuery *author= new QSqlQuery(data);
    QSqlQuery *num_copies= new QSqlQuery(data);

    title->prepare("SELECT title FROM books");
    isbn_no->prepare("SELECT isbn_no FROM books");
    author->prepare("SELECT author FROM books");
    num_copies->prepare("SELECT num_copies FROM books");

    title->exec();
    isbn_no->exec();
    author->exec();
    num_copies->exec();

    modal->setQuery(std::move(*title));
    modal1->setQuery(std::move(*isbn_no));
    modal2->setQuery(std::move(*author));
    modal3->setQuery(std::move(*num_copies));
    QVBoxLayout *lay=new QVBoxLayout(this);
    QString search=ui->lineEdit_search->text();
    QPushButton *label;



    for(int j=0;j<=modal->rowCount();j++)
    {
        QString strtitle=modal->record(j).value(0).toString();
        QString strisbn=modal1->record(j).value(0).toString();
        QString strauthor=modal2->record(j).value(0).toString();
        QString strcopies=modal3->record(j).value(0).toString();

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

                ui->frame_display_head->hide();

                ui->frame_display->setGeometry(10,50,900,550);

                QLabel *lab1=new QLabel("Search Result For "+strtitle);
                // QFrame *line1=new QFrame;

                label=new QPushButton(strtitle);
                label->setObjectName(strtitle);

                QLabel *lab=new QLabel("ISBN NUM: "+strisbn+", Author: "+strauthor+",Number of Copies: "+strcopies+".");
                QFrame *line=new QFrame;
                line->setFrameShape(QFrame::HLine);
                line->setFrameShadow(QFrame::Sunken);

                label->setStyleSheet(
                            "   QPushButton {"
                            "     background:transparent; Text-align:left;font-family:century gothic;font-size:18px; color:black;"
                            " }"
                            " QPushButton:hover {"
                            "     color: rgb(0, 0, 0);font-size:25px;"
                            " }");

                lab1->setStyleSheet(
                            "   QLabel {"
                            "     background:transparent; Text-align:left;font-family:century gothic;font-size:28px; color:black;"
                            " }");


                lay->addWidget(lab1);
                //lay->addWidget(line1);
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

                    ui->frame_display_head->hide();

                    ui->frame_display->setGeometry(10,50,900,550);
                    QLabel *lab1=new QLabel("Search Result For "+strisbn);
                    // QFrame *line1=new QFrame;

                    label=new QPushButton(strtitle);
                    label->setObjectName(strtitle);

                    QLabel *lab=new QLabel("ISBN NUM: "+strisbn+", Author: "+strauthor+",Number of Copies: "+strcopies+".");
                    QFrame *line=new QFrame;
                    line->setFrameShape(QFrame::HLine);
                    line->setFrameShadow(QFrame::Sunken);

                    label->setStyleSheet(
                                "   QPushButton {"
                                "     background:transparent; Text-align:left;font-family:century gothic;font-size:18px; color:black;"
                                " }"
                                " QPushButton:hover {"
                                "     color: rgb(0, 0, 0);font-size:25px;"
                                " }");

                    lab1->setStyleSheet(
                                "   QLabel {"
                                "     background:transparent; Text-align:left;font-family:century gothic;font-size:28px; color:black;"
                                " }");

                    lay->addWidget(lab1);
                    //lay->addWidget(line1);
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






void HomePage::on_pushButton_circulation_clicked()
{
    mblist = new mybooklist(this);
    mblist->show();
}


void HomePage::on_pushButton_books_clicked()
{
    blist = new booklist(this);
    blist->show();
}


void HomePage::on_pushButton_notifydelay_clicked()
{
    chk = new chkreq(this);
    chk->show();
}

