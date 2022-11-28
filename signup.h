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

public:
    explicit SignUp(QWidget *parent = nullptr);
    ~SignUp();

private:
    Ui::SignUp *ui;
    QSqlDatabase database;
};

#endif // SIGNUP_H
