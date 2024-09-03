#include "adcell2_updatetime.h"
#include "ui_adcell2_updatetime.h"

adcell2_updateTime::adcell2_updateTime(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adcell2_updateTime)
{
    ui->setupUi(this);
}

adcell2_updateTime::~adcell2_updateTime()
{
    delete ui;
}
