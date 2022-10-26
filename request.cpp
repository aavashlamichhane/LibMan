#include "request.h"
#include "ui_request.h"

Request::Request(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Request)
{
    ui->setupUi(this);
}

Request::~Request()
{
    delete ui;
}
