#ifndef REMOVEBOOK_H
#define REMOVEBOOK_H

#include <QDialog>
#include<QtSql>
#include<QSqlDatabase>
#include<QMessageBox>

namespace Ui {
class removebook;
}

class removebook : public QDialog
{
    Q_OBJECT

public:
    explicit removebook(QWidget *parent = nullptr);
    ~removebook();

private slots:
    void on_pushButton_back_clicked();

    void on_pushButton_clicked();

private:
    Ui::removebook *ui;
    QSqlDatabase daret;
};

#endif // REMOVEBOOK_H
