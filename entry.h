#ifndef ENTRY_H
#define ENTRY_H

#include <QDialog>

namespace Ui {
class entry;
}

class entry : public QDialog
{
    Q_OBJECT

public:
    explicit entry(QWidget *parent = nullptr);
    ~entry();

private:
    Ui::entry *ui;
};

#endif // ENTRY_H
