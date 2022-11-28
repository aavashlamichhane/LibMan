#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QtSql>
#include<QSqlDatabase>
#include "entry.h"
#include "signup.h"
#include "request.h"
#include "homepage.h"
#include "userinfo.h"
#include "studenthomepage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT



public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();




private slots:
    void on_Login_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_username_login_returnPressed();

    void on_password_login_returnPressed();

private:
    Ui::MainWindow *ui;
    entry *Entry;
    SignUp *signup;
    Request *request;
    HomePage *homepage;
    studentHomePage *shomepage;
    QSqlDatabase dab;



};
#endif // MAINWINDOW_H
