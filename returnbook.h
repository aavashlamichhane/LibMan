#ifndef RETURNBOOK_H
#define RETURNBOOK_H

#include <QDialog>
#include<QtSql>
#include<QSqlDatabase>
#include<QMessageBox>
namespace Ui {
class returnBook;
}

class returnBook : public QDialog
{
    Q_OBJECT

public:
    explicit returnBook(QWidget *parent = nullptr);
    ~returnBook();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_back_clicked();

    void on_lineEdit_isbn_returnPressed();

    void on_lineEdit_user_returnPressed();

private:
    Ui::returnBook *ui;
    QSqlDatabase daret;
};

#endif // RETURNBOOK_H
