#include "adcell2_addstupa.h"
#include "ui_adcell2_addstupa.h"
#include<sqlop.h>

adcell2_addStuPa::adcell2_addStuPa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adcell2_addStuPa)
{
    ui->setupUi(this);
}

adcell2_addStuPa::~adcell2_addStuPa()
{
    delete ui;
}

void adcell2_addStuPa::setDate()
{
    this->ui->dateEdit->setDate(QDate::currentDate());
}

void adcell2_addStuPa::on_btn_cancel_clicked()
{
    this->close();
}

void adcell2_addStuPa::on_btn_commit_clicked()
{
    QString sid = ui->sid->text();
    QString paInfo = ui->paInfo->text();
    QDate date = ui->dateEdit->date();
    QString year = QString::number(date.year());
    QString month = QString::number(date.month());
    QString day = QString::number(date.day());
    QString time = QString("%1-%2-%3").arg(year,month,day);
    if(sid == "")
    {
        QMessageBox::warning(this,"错误","请输入学号");
    }
    else if(paInfo == "")
    {
        QMessageBox::warning(this,"错误","请输入奖励/惩罚信息");
    }
    else
    {
        QStringList info;
        info.append(sid);
        info.append(paInfo);
        info.append(time);
        sqlOP::getInstance()->stuPaRegister(info);
        this->close();
    }
}
