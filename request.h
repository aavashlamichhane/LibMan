#ifndef REQUEST_H
#define REQUEST_H

#include <QDialog>

namespace Ui {
class Request;
}

class Request : public QDialog
{
    Q_OBJECT

public:
    explicit Request(QWidget *parent = nullptr);
    ~Request();

private:
    Ui::Request *ui;
};

#endif // REQUEST_H
