#ifndef STUDENTHOMEPAGE_H
#define STUDENTHOMEPAGE_H

#include <QDialog>
#include<QtSql>
#include<QSqlDatabase>
#include<QMessageBox>

namespace Ui {
class studentHomePage;
}

class studentHomePage : public QDialog
{
    Q_OBJECT

public:
    explicit studentHomePage(QWidget *parent = nullptr);
    ~studentHomePage();

private:
    Ui::studentHomePage *ui;
    QSqlDatabase db_stdhome;
    QSqlQueryModel *query_stdhome;
};

#endif // STUDENTHOMEPAGE_H
