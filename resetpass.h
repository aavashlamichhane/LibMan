#ifndef RESETPASS_H
#define RESETPASS_H

#include <QDialog>
#include<QtSql>
#include<QSqlDatabase>
#include<QMessageBox>
namespace Ui {
class resetpass;
}

class resetpass : public QDialog
{
    Q_OBJECT

public:
    explicit resetpass(QWidget *parent = nullptr);
    ~resetpass();

private slots:
    void on_pushButton_clicked();

private:
    Ui::resetpass *ui;
    QSqlDatabase res;
};

#endif // RESETPASS_H
