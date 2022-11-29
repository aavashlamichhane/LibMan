#ifndef FORGOTPASS_H
#define FORGOTPASS_H

#include <QMainWindow>
#include<QtSql>
#include<QSqlDatabase>
#include<QMessageBox>


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
};

#endif // FORGOTPASS_H
