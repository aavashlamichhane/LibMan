#ifndef MYBOOKLIST_H
#define MYBOOKLIST_H

#include <QDialog>
#include<QtSql>
#include<QSqlDatabase>
#include<QMessageBox>

namespace Ui {
class mybooklist;
}

class mybooklist : public QDialog
{
    Q_OBJECT

public:


public:
    explicit mybooklist(QWidget *parent = nullptr);
    ~mybooklist();

private slots:
    void on_pushButton_load_clicked();

private:
    Ui::mybooklist *ui;
    QSqlDatabase dal;
};

#endif // MYBOOKLIST_H
