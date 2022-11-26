#ifndef ADMINPANNEL_H
#define ADMINPANNEL_H

#include <QDialog>

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
};

#endif // ADMINPANNEL_H
