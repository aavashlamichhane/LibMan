#ifndef ISSUERECORDS_H
#define ISSUERECORDS_H

#include <QDialog>
#include<QtSql>
#include<QSqlDatabase>
#include<QMessageBox>
namespace Ui {
class IssueRecords;
}

class IssueRecords : public QDialog
{
    Q_OBJECT

public:
    explicit IssueRecords(QWidget *parent = nullptr);
    ~IssueRecords();

private slots:
    void on_pushButton_update_clicked();

    void on_lineEdit_returnPressed();

private:
    Ui::IssueRecords *ui;
    QSqlDatabase daib;
    QSqlQueryModel *modal=new QSqlQueryModel();

};

#endif // ISSUERECORDS_H
