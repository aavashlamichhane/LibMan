#ifndef REQUEST_H
#define REQUEST_H

#include <QDialog>
#include<QtSql>
#include<QSqlDatabase>
#include<QMessageBox>

namespace Ui {
class Request;
}

class Request : public QDialog
{
    Q_OBJECT

public:
    explicit Request(QWidget *parent = nullptr);
    ~Request();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Request *ui;
    QSqlDatabase drequest;

};

#endif // REQUEST_H
