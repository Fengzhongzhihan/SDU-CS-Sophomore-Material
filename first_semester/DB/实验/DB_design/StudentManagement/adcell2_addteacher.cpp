#include "adcell2_addteacher.h"
#include "ui_adcell2_addteacher.h"
#include<sqlop.h>

adcell2_addTeacher::adcell2_addTeacher(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adcell2_addTeacher)
{
    ui->setupUi(this);
}

adcell2_addTeacher::~adcell2_addTeacher()
{
    delete ui;
}

void adcell2_addTeacher::on_btn_cancel_clicked()
{
    this->close();
}

void adcell2_addTeacher::on_btn_commit_clicked()
{
    QString teacher_id = ui->teacher_id->text();
    QString teacher_name = ui->teacher_name->text();
    QString college_name = ui->college->text();
    if(teacher_id == "")
    {
        QMessageBox::warning(this,"错误","请输入教师编号");
    }
    else if(teacher_name == "")
    {
        QMessageBox::warning(this,"错误","请输入教师名称");
    }
    else if(college_name == "")
    {
        QMessageBox::warning(this,"错误","请输入该学院名称");
    }
    else if(sqlOP::getInstance()->isTeacherExist(teacher_id))
    {
        QMessageBox::warning(this,"错误","已存在使用该id的老师");
    }
    else if(!sqlOP::getInstance()->isCollegeExistByName(college_name))
    {
        QMessageBox::warning(this,"错误","不存在使用该名称的学院");
    }
    else
    {
        QStringList info;
        info.append(teacher_id);
        info.append(teacher_name);
        info.append(college_name);
        sqlOP::getInstance()->addTeacherInfos(info);
        this->close();
    }
}
