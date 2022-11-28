#ifndef EDITPROFILE_H
#define EDITPROFILE_H

#include <QMainWindow>
#include<QSqlQuery>
#include<QtSql>
#include<QSqlDatabase>

namespace Ui {
class editProfile;
}

class editProfile : public QMainWindow
{
    Q_OBJECT

public:
    explicit editProfile(QWidget *parent = nullptr);
    ~editProfile();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::editProfile *ui;
    QSqlDatabase data_info;
};

#endif // EDITPROFILE_H
