#include "adcell2_addmajor.h"
#include "ui_adcell2_addmajor.h"
#include<sqlop.h>

adcell2_addMajor::adcell2_addMajor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adcell2_addMajor)
{
    ui->setupUi(this);
}

adcell2_addMajor::~adcell2_addMajor()
{
    delete ui;
}

void adcell2_addMajor::on_btn_cancel_clicked()
{
    this->close();
}

void adcell2_addMajor::on_btn_commit_clicked()
{
    QString college_id = ui->college_id->text();
    QString major_id = ui->major_id->text();
    QString major_name = ui->major_name->text();
    if(college_id == "")
    {
        QMessageBox::warning(this,"错误","请输入学院编号");
    }
    else if(major_id == "")
    {
        QMessageBox::warning(this,"错误","请输入专业编号");
    }
    else if(major_name == "")
    {
        QMessageBox::warning(this,"错误","请输入该专业名称");
    }
    else if(!sqlOP::getInstance()->isCollegeExist(college_id))
    {
        QMessageBox::warning(this,"错误","不存在使用该id的学院");
    }
    else if(sqlOP::getInstance()->isMajorExist(major_id))
    {
        QMessageBox::warning(this,"错误","已存在使用该id的专业");
    }
    else if(sqlOP::getInstance()->isMajorExistByName(major_name))
    {
        QMessageBox::warning(this,"错误","已存在使用该名称的专业");
    }
    else
    {
        QStringList info;
        info.append(college_id);
        info.append(major_id);
        info.append(major_name);
        sqlOP::getInstance()->addCollegeMajorInfos(info);
        this->close();
    }
}
