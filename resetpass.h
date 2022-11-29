#ifndef RESETPASS_H
#define RESETPASS_H

#include <QDialog>

namespace Ui {
class resetpass;
}

class resetpass : public QDialog
{
    Q_OBJECT

public:
    explicit resetpass(QWidget *parent = nullptr);
    ~resetpass();

private:
    Ui::resetpass *ui;
};

#endif // RESETPASS_H
