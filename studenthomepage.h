#ifndef STUDENTHOMEPAGE_H
#define STUDENTHOMEPAGE_H

#include <QDialog>

namespace Ui {
class studentHomePage;
}

class studentHomePage : public QDialog
{
    Q_OBJECT

public:
    explicit studentHomePage(QWidget *parent = nullptr);
    ~studentHomePage();

private:
    Ui::studentHomePage *ui;
};

#endif // STUDENTHOMEPAGE_H
