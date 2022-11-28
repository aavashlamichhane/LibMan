#ifndef STUDENTHOMEPAGE_H
#define STUDENTHOMEPAGE_H

#include <QMainWindow>
#include<QtSql>
#include<QSqlDatabase>
#include<QMessageBox>
#include "settings.h"
#include "userinfo.h"
#include "mybooklist.h"
#include "request.h"
#include "booklist.h"

namespace Ui {
class studentHomePage;
}

class studentHomePage : public QMainWindow
{
    Q_OBJECT

public:
    explicit studentHomePage(QWidget *parent = nullptr);
    ~studentHomePage();
private slots:
    void on_pushButton_settings_clicked();

    void on_pushButton_user_clicked();



private slots:


    void on_pushButton_search_clicked();

    void on_pushButton_adminpanel_clicked();

    void on_pushButton_notifydelay_clicked();

    void on_pushButton_circulation_clicked();

    void on_pushButton_books_clicked();

    void on_lineEdit_search_returnPressed();

    void on_pushButton_home_clicked();

private:
    Ui::studentHomePage *ui;
    QSqlDatabase db_stdhome;
    QSqlQueryModel *query_stdhome;
    Settings *settings;
    UserInfo *info;
    Request *request;
    QSqlDatabase data;
    mybooklist *list;
    booklist *book;
    studentHomePage *shp;
};

#endif // STUDENTHOMEPAGE_H
