#include "mybooklist.h"
#include "ui_mybooklist.h"

mybooklist::mybooklist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mybooklist)
{
    ui->setupUi(this);
}

mybooklist::~mybooklist()
{
    delete ui;
}
