#ifndef ENTRY_H
#define ENTRY_H

#include <QDialog>
#include<QtSql>
#include<QSqlDatabase>
#include<QMessageBox>



namespace Ui {
class entry;
}

class entry : public QDialog
{
    Q_OBJECT

public:
    explicit entry(QWidget *parent = nullptr);
    ~entry();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_name_returnPressed();

    void on_lineEdit_author_returnPressed();

    void on_lineEdit_year_returnPressed();

    void on_lineEdit_isbn_returnPressed();

    void on_lineEdit_pub_returnPressed();

    void on_lineEdit_copies_returnPressed();

    void on_lineEdit_page_returnPressed();

private:
    Ui::entry *ui;
    QSqlDatabase dEntry;
};

#endif // ENTRY_H
