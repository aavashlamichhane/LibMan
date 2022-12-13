#include "resetpass.h"
#include "ui_resetpass.h"
#include "mainwindow.h"

MainWindow *m;

resetpass::resetpass(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::resetpass)
{
    ui->setupUi(this);
    this->setWindowTitle("LibMan");
    this->setWindowIcon(QIcon(":/rec/drive-download-20221026T014232Z-001/Logo no BG and text.png"));
}

resetpass::~resetpass()
{
    delete ui;
}


void resetpass::on_pushButton_clicked()
{
    res = QSqlDatabase::addDatabase("QMYSQL","reset");
    res.setHostName("127.0.0.1");
    res.setUserName("root");
    res.setPassword("rampyari1234");
    res.setDatabaseName("libman");
    res.open();
    extern QString usern;
    QSqlQuery chg(res);
    QString pass=ui->lineEdit->text();
    QString pass1=ui->lineEdit_2->text();
    if(pass!=pass1)
    {
        QMessageBox::warning(this,"Error","Password doesn't match. Please try again.");
    }
    chg.prepare("UPDATE userbase SET password=:password WHERE username=:username");
    chg.bindValue(":username",usern);
    chg.bindValue(":password",pass);
    if(chg.exec())
    {
        QMessageBox::information(this,"Success","Password has been changed.");
        close();
        m= new MainWindow();
        m->showMaximized();
    }


}

