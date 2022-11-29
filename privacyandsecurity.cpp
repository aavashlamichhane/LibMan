#include "privacyandsecurity.h"
#include "ui_privacyandsecurity.h"

privacyandsecurity::privacyandsecurity(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::privacyandsecurity)
{
    ui->setupUi(this);
    this->setWindowTitle("LibMan");
    this->setWindowIcon(QIcon(":/rec/drive-download-20221026T014232Z-001/Logo no BG and text.png"));
}

privacyandsecurity::~privacyandsecurity()
{
    delete ui;
}
