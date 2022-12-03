#ifndef UPDATEBOOK_H
#define UPDATEBOOK_H

#include <QDialog>
#include<QSqlDatabase>
#include<QtSql>
#include<QSqlQuery>
#include<QMessageBox>

namespace Ui {
class UpdateBook;
}

class UpdateBook : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateBook(QWidget *parent = nullptr);
    ~UpdateBook();

private slots:
    void on_pushButton_clicked();


    void on_pushButton_back_clicked();

    void on_lineEdit_num_returnPressed();

    void on_lineEdit_copy_returnPressed();

private:
    Ui::UpdateBook *ui;
    QSqlDatabase daub;
};

#endif // UPDATEBOOK_H
