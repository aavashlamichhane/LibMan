#ifndef BOOKISSUE_H
#define BOOKISSUE_H

#include <QDialog>

namespace Ui {
class bookissue;
}

class bookissue : public QDialog
{
    Q_OBJECT

public:
    explicit bookissue(QWidget *parent = nullptr);
    ~bookissue();

private:
    Ui::bookissue *ui;
};

#endif // BOOKISSUE_H
