#ifndef MYBOOKLIST_H
#define MYBOOKLIST_H

#include <QDialog>

namespace Ui {
class mybooklist;
}

class mybooklist : public QDialog
{
    Q_OBJECT

public:
    explicit mybooklist(QWidget *parent = nullptr);
    ~mybooklist();

private slots:
    void on_pushButton_load_clicked();

private:
    Ui::mybooklist *ui;
};

#endif // MYBOOKLIST_H
