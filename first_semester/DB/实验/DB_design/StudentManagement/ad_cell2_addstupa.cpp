#include "ad_cell2_addstupa.h"
#include "ui_ad_cell2_addstupa.h"

ad_cell2_addStuPa::ad_cell2_addStuPa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ad_cell2_addStuPa)
{
    ui->setupUi(this);
}

ad_cell2_addStuPa::~ad_cell2_addStuPa()
{
    delete ui;
}

void ad_cell2_addStuPa::on_btn_cancel_clicked()
{
    this->close();
}

void ad_cell2_addStuPa::on_btn_commit_clicked()
{
    QDate date = ui->dateEdit->date();
}
