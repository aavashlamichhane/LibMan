#ifndef USERINFO_H
#define USERINFO_H

#include <QDialog>
#include<QSqlDatabase>
#include<QtSql>
#include"editprofile.h"
#include<QSqlQuery>

namespace Ui {
class UserInfo;
}

class UserInfo : public QDialog
{
    Q_OBJECT

public:
    explicit UserInfo(QWidget *parent = nullptr);
    ~UserInfo();

private slots:
    void on_pushButton_editprofile_clicked();

    void on_pushButton_home_clicked();

private:
    Ui::UserInfo *ui;
    editProfile *ep;
    QSqlDatabase data_info;
};

#endif // USERINFO_H
