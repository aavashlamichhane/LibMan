#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QMainWindow>
#include "settings.h"
#include "userinfo.h"
#include "adminpannel.h"
#include "mybooklist.h"
#include "booklist.h"
#include "chkreq.h"
#include<QSqlDatabase>
#include<QtSql>

namespace Ui {
class HomePage;
}

class HomePage : public QMainWindow
{
    Q_OBJECT

public:
    explicit HomePage(QWidget *parent = nullptr);
    ~HomePage();

private slots:
    void on_pushButton_settings_clicked();

    void on_pushButton_user_clicked();

    void on_pushButton_adminpanel_clicked();

    void on_pushButton_search_clicked();

    void on_pushButton_circulation_clicked();

    void on_pushButton_books_clicked();

    void on_pushButton_notifydelay_clicked();

    void on_lineEdit_search_returnPressed();

    void on_pushButton_home_clicked();

private:
    Ui::HomePage *ui;
    Settings *settings;
    UserInfo *info;
    adminpannel *admin;
    QSqlDatabase data;
    mybooklist *mblist;
    booklist *blist;
    chkreq *chk;
    HomePage *hp;
};

#endif // HOMEPAGE_H
