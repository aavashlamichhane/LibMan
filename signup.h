#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include<QtSql>
#include<QSqlDatabase>
#include<QMessageBox>

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
    void on_commandLinkButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::SignUp *ui;
    QSqlDatabase database;

};

#endif // SIGNUP_H
