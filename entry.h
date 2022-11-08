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

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::entry *ui;
};

#endif // ENTRY_H
