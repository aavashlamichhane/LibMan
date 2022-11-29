#include "helpandsupport.h"
#include "ui_helpandsupport.h"

helpandsupport::helpandsupport(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::helpandsupport)
{
    ui->setupUi(this);
    this->setWindowTitle("LibMan");
    this->setWindowIcon(QIcon(":/rec/drive-download-20221026T014232Z-001/Logo no BG and text.png"));
}

helpandsupport::~helpandsupport()
{
    delete ui;
}
