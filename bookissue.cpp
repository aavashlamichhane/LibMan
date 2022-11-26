#include "bookissue.h"
#include "ui_bookissue.h"

bookissue::bookissue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bookissue)
{
    ui->setupUi(this);
}

bookissue::~bookissue()
{
    delete ui;
}
