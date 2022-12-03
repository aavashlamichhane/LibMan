#ifndef SIGNUP_H
#define SIGNUP_H

#include <QMainWindow>
#include<QtSql>
#include<QSqlDatabase>
#include<QMessageBox>
#include<Qt>

namespace Ui {
class SignUp;
}

class SignUp : public QMainWindow
{
    Q_OBJECT
private slots:
    void on_pushButton_clicked();

    void on_pushbutton_login_clicked();

    void on_lineEdit_cpassword_returnPressed();

    void on_lineEdit_lN_returnPressed();

    void on_lineEdit_mN_returnPressed();

    void on_lineEdit_fN_returnPressed();

    void on_lineEdit_user_returnPressed();

    void on_lineEdit_email_returnPressed();

    void on_lineEdit_pNum_returnPressed();

    void on_lineEdit_password_returnPressed();

public:
    explicit SignUp(QWidget *parent = nullptr);
    ~SignUp();

private:
    Ui::SignUp *ui;
    QSqlDatabase database;
};

#endif // SIGNUP_H
