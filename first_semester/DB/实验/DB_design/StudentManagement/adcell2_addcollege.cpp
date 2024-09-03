#include "adcell2_addcollege.h"
#include "ui_adcell2_addcollege.h"
#include<sqlop.h>

adcell2_addCollege::adcell2_addCollege(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adcell2_addCollege)
{
    ui->setupUi(this);
}

adcell2_addCollege::~adcell2_addCollege()
{
    delete ui;
}

void adcell2_addCollege::on_btn_cancel_clicked()
{
    this->close();
}

void adcell2_addCollege::on_btn_commit_clicked()
{
    QString college_id = ui->college_id->text();
    QString college_name = ui->college_name->text();
    if(college_id == "")
    {
        QMessageBox::warning(this,"错误","请输入学院编号");
    }
    else if(college_name == "")
    {
        QMessageBox::warning(this,"错误","请输入学院名称");
    }
    else if(sqlOP::getInstance()->isCollegeExist(college_id))
    {
        QMessageBox::warning(this,"错误","已存在使用该id的学院");
    }
    else if(sqlOP::getInstance()->isCollegeExistByName(college_name))
    {
        QMessageBox::warning(this,"错误","已存在使用该名称的学院");
    }
    else
    {
        QStringList info;
        info.append(college_id);
        info.append(college_name);
        sqlOP::getInstance()->addCollegeInfos(info);
        this->close();
    }
}
