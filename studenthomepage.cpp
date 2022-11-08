#include "studenthomepage.h"
#include "ui_studenthomepage.h"

studentHomePage::studentHomePage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::studentHomePage)
{
    ui->setupUi(this);
}

studentHomePage::~studentHomePage()
{
    delete ui;
}
