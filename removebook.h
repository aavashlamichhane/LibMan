#ifndef REMOVEBOOK_H
#define REMOVEBOOK_H

#include <QDialog>

namespace Ui {
class removebook;
}

class removebook : public QDialog
{
    Q_OBJECT

public:
    explicit removebook(QWidget *parent = nullptr);
    ~removebook();

private:
    Ui::removebook *ui;
};

#endif // REMOVEBOOK_H
