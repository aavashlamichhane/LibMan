#ifndef ADMINPANNEL_H
#define ADMINPANNEL_H

#include <QMainWindow>
#include "entry.h"
#include "bookissue.h"
#include "returnbook.h"
#include "promote.h"
#include "updatebook.h"

namespace Ui {
class adminpannel;
}

class adminpannel : public QMainWindow
{
    Q_OBJECT

public:
    explicit adminpannel(QWidget *parent = nullptr);
    ~adminpannel();
private slots:
    void on_pushButton_addbook_clicked();

    void on_pushButton_issuebook_clicked();

    void on_pushButton_returnbook_clicked();

    void on_pushButton_promote_clicked();

    void on_pushButton_updatebook_clicked();

    void on_pushButton_clicked();

private:
    Ui::adminpannel *ui;
    entry *newbook;
    bookissue *issue;
    returnBook *returnbook;
    promote *prom;
    UpdateBook *upd;
};

#endif // ADMINPANNEL_H
