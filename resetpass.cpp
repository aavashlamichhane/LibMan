#include "resetpass.h"
#include "ui_resetpass.h"

resetpass::resetpass(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::resetpass)
{
    ui->setupUi(this);
    this->setWindowTitle("LibMan");
    this->setWindowIcon(QIcon(":/rec/drive-download-20221026T014232Z-001/Logo no BG and text.png"));
}

resetpass::~resetpass()
{
    delete ui;
}
