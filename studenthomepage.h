#ifndef STUDENTHOMEPAGE_H
#define STUDENTHOMEPAGE_H

#include <QDialog>
#include<QtSql>
#include<QSqlDatabase>
#include<QMessageBox>
#include "settings.h"
#include "userinfo.h"
#include "entry.h"

namespace Ui {
class studentHomePage;
}

class studentHomePage : public QDialog
{
    Q_OBJECT

public:
    explicit studentHomePage(QWidget *parent = nullptr);
    ~studentHomePage();
private slots:
    void on_pushButton_settings_clicked();

    void on_pushButton_user_clicked();



private slots:


private:
    Ui::studentHomePage *ui;
    QSqlDatabase db_stdhome;
    QSqlQueryModel *query_stdhome;
    Settings *settings;
    UserInfo *info;

    QSqlDatabase sdata;
};

#endif // STUDENTHOMEPAGE_H
