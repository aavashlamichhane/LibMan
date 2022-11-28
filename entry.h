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

private:
    Ui::entry *ui;
    QSqlDatabase dEntry;
};

#endif // ENTRY_H
