#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include<QtSql>
#include<QSqlDatabase>
#include<QMessageBox>
#include<Qt>

namespace Ui {
class SignUp;
}

class SignUp : public QDialog
{
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent = nullptr);
    ~SignUp();

private slots:
    void on_pushButton_clicked();

    void on_pushbutton_login_clicked();

private:
    Ui::SignUp *ui;
    QSqlDatabase database;


};

#endif // SIGNUP_H
