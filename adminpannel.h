#ifndef ADMINPANNEL_H
#define ADMINPANNEL_H

#include <QMainWindow>
#include "entry.h"
#include "bookissue.h"
#include "removebook.h"
#include "returnbook.h"
#include "returnbook.h"
#include "updatebook.h"
#include "issuerecords.h"

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

    void on_pushButton_updatebook_clicked();

    void on_pushButton_clicked();

    void on_pushButton_record_clicked();

    void on_pushButton_remove_clicked();

private:
    Ui::adminpannel *ui;
    entry *newbook;
    bookissue *issue;
    returnBook *returnbook;
    removebook *del;
    UpdateBook *upd;
    IssueRecords *iss;
};

#endif // ADMINPANNEL_H
