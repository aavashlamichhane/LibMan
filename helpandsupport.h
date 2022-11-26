#ifndef HELPANDSUPPORT_H
#define HELPANDSUPPORT_H

#include <QDialog>

namespace Ui {
class helpandsupport;
}

class helpandsupport : public QDialog
{
    Q_OBJECT

public:
    explicit helpandsupport(QWidget *parent = nullptr);
    ~helpandsupport();

private:
    Ui::helpandsupport *ui;
};

#endif // HELPANDSUPPORT_H
