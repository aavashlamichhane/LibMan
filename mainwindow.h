#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QtSql>
#include<QSqlDatabase>
#include "entry.h"
#include "signup.h"
#include "request.h"
#include "homepage.h"
#include "settings.h"
#include "userinfo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase db;
    void connClose()
    {
        db.close();
        db.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen()
    {
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("127.0.0.1");
        db.setUserName("root");
        db.setPassword("rampyari1234");
        db.setDatabaseName("libman");
        if(!db.open())
        {
            QMessageBox::information(this,"Connection","connected successfully.");
            return false;
        }
        else
        {
            QMessageBox::information(this,"Connection","not connected.");
            return true;
        }
    }

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:
    void on_Login_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    entry *Entry;
    SignUp *signup;
    Request *request;
    HomePage *homepage;
    QSqlDatabase dab;
    QString *usernameg;


};
#endif // MAINWINDOW_H
