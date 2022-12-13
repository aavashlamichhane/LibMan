#include "forgotpass.h"
#include "ui_forgotpass.h"
#include "mainwindow.h"


MainWindow *mwin;
QString usern;


forgotpass::forgotpass(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::forgotpass)
{
    ui->setupUi(this);
    this->setWindowTitle("LibMan");
    this->setWindowIcon(QIcon(":/rec/drive-download-20221026T014232Z-001/Logo no BG and text.png"));
}

forgotpass::~forgotpass()
{
    delete ui;
}

void forgotpass::on_pushButton_2_clicked()
{
    close();
    mwin = new MainWindow();
    mwin->showMaximized();
}


void forgotpass::on_pushButton_clicked()
{
    fab = QSqlDatabase::addDatabase("QMYSQL","Fab");
    fab.setHostName("127.0.0.1");
    fab.setUserName("root");
    fab.setPassword("rampyari1234");
    fab.setDatabaseName("libman");
    fab.open();
    QString mail = ui->lineEdit_mail->text();
    QString user = ui->lineEdit_user->text();
    usern=user;
    QString ph=ui->lineEdit_ph->text();
    QString ques = ui->comboBox_ques->currentText();
    QString ans = ui->lineEdit_ans->text();
    QSqlQuery qry(fab);
    qry.prepare("SELECT * FROM userbase WHERE user_email=:user_email AND username=:username AND phone_number=:phone_number AND sec_ques=:sec_ques AND sec_ans=:sec_ans ");
    qry.bindValue(":user_email",mail);
    qry.bindValue(":username",user);
    qry.bindValue(":phone_number",ph);
    qry.bindValue(":sec_ques",ques);
    qry.bindValue(":sec_ans",ans);
    qry.exec();
    if(!qry.next())
    {
        qDebug() << qry.lastError().text()<<Qt::endl;
        QMessageBox::warning(this,"Error","Invalid account.");

    }
    else
    {
        close();
        re = new resetpass(this);
        re->show();
    }

}

