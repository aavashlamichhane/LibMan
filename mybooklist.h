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
    QSqlDatabase db;
    void connClose()
    {
        db.close();
        db.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen()
    {
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("127.0.0.1");
        db.setUserName("root");
        db.setPassword("rampyari1234");
        db.setDatabaseName("libman");
        if(!db.open())
        {
            QMessageBox::information(this,"Connection","connected successfully.");
            return false;
        }
        else
        {
            QMessageBox::information(this,"Connection","not connected.");
            return true;
        }
    }

public:
    explicit mybooklist(QWidget *parent = nullptr);
    ~mybooklist();

private slots:
    void on_pushButton_load_clicked();

private:
    Ui::mybooklist *ui;
};

#endif // MYBOOKLIST_H
