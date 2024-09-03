#include "adcell2_addtime.h"
#include "ui_adcell2_addtime.h"
#include<sqlop.h>

adcell2_addTime::adcell2_addTime(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adcell2_addTime)
{
    ui->setupUi(this);
}

adcell2_addTime::~adcell2_addTime()
{
    delete ui;
}

void adcell2_addTime::on_cancelButton_clicked()
{
    this->close();
}

void adcell2_addTime::on_commitButton_clicked()
{
    QString time_id = ui->time_id->text();
    QString startWeek = ui->startWeek->text();
    QString endWeek = ui->endWeek->text();
    QString DayOfWeek = ui->DayOfWeek->text();
    QString section = ui->section->text();
    if(time_id == "")
    {
        QMessageBox::warning(this,"错误","请输入时间编号");
    }
    else if(startWeek == "")
    {
        QMessageBox::warning(this,"错误","请输入开始周");
    }
    else if(endWeek == "")
    {
        QMessageBox::warning(this,"错误","请输入结束周");
    }
    else if(DayOfWeek == "")
    {
        QMessageBox::warning(this,"错误","请输入星期几");
    }
    else if(section == "")
    {
        QMessageBox::warning(this,"错误","请输入节次");
    }
    else if(sqlOP::getInstance()->isTimeExist(time_id))
    {
        QMessageBox::warning(this,"错误","已存在使用该id的时间编号");
    }
    else
    {
        QStringList info;
        info.append(time_id);
        info.append(startWeek);
        info.append(endWeek);
        info.append(DayOfWeek);
        info.append(section);
        sqlOP::getInstance()->addTimeInfos(info);
        this->close();
    }
}
