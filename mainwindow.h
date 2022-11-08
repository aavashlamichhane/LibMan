#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:
    void on_Login_3_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
    entry *Entry;
    SignUp *signup;
    Request *request;
    HomePage *homepage;

};
#endif // MAINWINDOW_H
