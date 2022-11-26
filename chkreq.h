#ifndef CHKREQ_H
#define CHKREQ_H

#include <QDialog>
#include<QtSql>
#include<QSqlDatabase>
#include<QMessageBox>

namespace Ui {
class chkreq;
}

class chkreq : public QDialog
{
    Q_OBJECT

public:
    explicit chkreq(QWidget *parent = nullptr);
    ~chkreq();

private:
    Ui::chkreq *ui;
    QSqlDatabase dala;

};

#endif // CHKREQ_H
