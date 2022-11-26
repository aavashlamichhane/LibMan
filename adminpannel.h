#ifndef ADMINPANNEL_H
#define ADMINPANNEL_H

#include <QDialog>
#include "entry.h"
#include "bookissue.h"


namespace Ui {
class adminpannel;
}

class adminpannel : public QDialog
{
    Q_OBJECT

public:
    explicit adminpannel(QWidget *parent = nullptr);
    ~adminpannel();

private slots:
    void on_pushButton_addbook_clicked();

    void on_pushButton_issuebook_clicked();

private:
    Ui::adminpannel *ui;
    entry *newbook;
    bookissue *issue;
};

#endif // ADMINPANNEL_H
