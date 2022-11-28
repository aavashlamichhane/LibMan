#ifndef PROMOTE_H
#define PROMOTE_H

#include <QDialog>
#include<QtSql>
#include<QSqlDatabase>
#include<QMessageBox>

namespace Ui {
class promote;
}

class promote : public QDialog
{
    Q_OBJECT

public:
    explicit promote(QWidget *parent = nullptr);
    ~promote();

private slots:
    void on_pushButton_clicked();


    void on_pushButton_back_clicked();

private:
    Ui::promote *ui;
    QSqlDatabase dap;
};

#endif // PROMOTE_H
