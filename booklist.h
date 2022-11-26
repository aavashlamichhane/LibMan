#ifndef BOOKLIST_H
#define BOOKLIST_H

#include <QDialog>
#include<QtSql>
#include<QSqlDatabase>
#include<QMessageBox>

namespace Ui {
class booklist;
}

class booklist : public QDialog
{
    Q_OBJECT

public:
    explicit booklist(QWidget *parent = nullptr);
    ~booklist();

private:
    Ui::booklist *ui;
    QSqlDatabase dalb;
};

#endif // BOOKLIST_H
