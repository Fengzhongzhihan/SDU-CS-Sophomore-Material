#include "adcell2_updatecollege.h"
#include "ui_adcell2_updatecollege.h"

adcell2_updateCollege::adcell2_updateCollege(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adcell2_updateCollege)
{
    ui->setupUi(this);
}

adcell2_updateCollege::~adcell2_updateCollege()
{
    delete ui;
}
