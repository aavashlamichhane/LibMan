#ifndef FORGOTPASS_H
#define FORGOTPASS_H

#include <QMainWindow>
#include<QtSql>
#include<QSqlDatabase>
#include<QMessageBox>
#include "resetpass.h"


namespace Ui {
class forgotpass;
}

class forgotpass : public QMainWindow
{
    Q_OBJECT

public:
    explicit forgotpass(QWidget *parent = nullptr);
    ~forgotpass();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::forgotpass *ui;
    QSqlDatabase fab;
    resetpass *re;
};

#endif // FORGOTPASS_H
