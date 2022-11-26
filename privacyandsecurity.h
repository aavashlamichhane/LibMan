#ifndef PRIVACYANDSECURITY_H
#define PRIVACYANDSECURITY_H

#include <QDialog>

namespace Ui {
class privacyandsecurity;
}

class privacyandsecurity : public QDialog
{
    Q_OBJECT

public:
    explicit privacyandsecurity(QWidget *parent = nullptr);
    ~privacyandsecurity();

private:
    Ui::privacyandsecurity *ui;
};

#endif // PRIVACYANDSECURITY_H
