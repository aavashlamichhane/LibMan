#ifndef ADMINPANNEL_H
#define ADMINPANNEL_H

#include <QDialog>
#include "entry.h"


namespace Ui {
class adminpannel;
}

class adminpannel : public QDialog
{
    Q_OBJECT

public:
    explicit adminpannel(QWidget *parent = nullptr);
    ~adminpannel();

private:
    Ui::adminpannel *ui;
    entry *newbook;
};

#endif // ADMINPANNEL_H