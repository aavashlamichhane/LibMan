#include "forgotpass.h"
#include "ui_forgotpass.h"
#include "mainwindow.h"
#include <CkMailMan.h>
#include <CkEmail.h>

MainWindow *mwin;
int code;

//void ChilkatSample(void)
//{
//    srand((unsigned) time(NULL));
//    code = 1000+ (rand() % 8999);
//    CkMailMan mailman;
//    mailman.put_SmtpHost("mail.google.com");
//    mailman.put_SmtpUsername("shisui.uchiha7601@gmail.com");
//    mailman.put_SmtpPassword("sasuke.35");
//    CkEmail email;
//    email.put_Subject("Password Reset");
//    email.put_Body("Use the code below to set up a new password for your account.If you did not request to reset your password,ignore this email.");
//    email.put_From("Chilkat Support <support@chilkatsoft.com>");
//    bool success = email.AddTo("Aavash Lamichhane","aavashlamichhane76@gmail.com");
//    success = mailman.SendEmail(email);
//    if (success != true)
//    {
//        qDebug()<< mailman.lastErrorText() << "\r\n";
//        return;
//    }
//     success = mailman.CloseSmtpConnection();
//    if (success != true)
//    {
//        qDebug() << "Connection to SMTP server not closed cleanly." << "\r\n";
//    }
//        qDebug() << "Mail Sent!" << "\r\n";
//}
forgotpass::forgotpass(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::forgotpass)
{
    ui->setupUi(this);
}

forgotpass::~forgotpass()
{
    delete ui;
}

void forgotpass::on_pushButton_2_clicked()
{
    close();
    mwin = new MainWindow(this);
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
    QString mail = ui->lineEdit->text();
    QSqlQuery qry(fab);
    qry.prepare("SELECT user_email FORM userbase WHERE user_email=:user_email");
    qry.bindValue(":user_email",mail);
    qry.exec();
    if(!qry.next())
    {
        QMessageBox::warning(this,"Error","Given account does not exist.");
        //qDebug<< qry.lastError();
    }
    else
    {
//        ChilkatSample();
    }

}

