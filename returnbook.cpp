#include "returnbook.h"
#include "ui_returnbook.h"
#include "adminpannel.h"

adminpannel *pan;

returnBook::returnBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::returnBook)
{
    ui->setupUi(this);
}

returnBook::~returnBook()
{
    delete ui;
}

void returnBook::on_pushButton_back_clicked()
{
    close();
    pan = new adminpannel(this);
    pan->show();
}

