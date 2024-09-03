#include "adcell2_updateteacher.h"
#include "ui_adcell2_updateteacher.h"
#include<sqlop.h>

adcell2_updateTeacher::adcell2_updateTeacher(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adcell2_updateTeacher)
{
    ui->setupUi(this);
}

adcell2_updateTeacher::~adcell2_updateTeacher()
{
    delete ui;
}

void adcell2_updateTeacher::on_btn_cancel_clicked()
{
    this->close();
}

void adcell2_updateTeacher::on_btn_commit_clicked()
{
    QString teacher_name = ui->teacher_name->text();
    QString college_name = ui->college->text();
    if(teacher_name == "")
    {
        QMessageBox::warning(this,"错误","请输入教师名称");
    }
    else if(college_name == "")
    {
        QMessageBox::warning(this,"错误","请输入该学院名称");
    }
    else if(!sqlOP::getInstance()->isCollegeExistByName(college_name))
    {
        QMessageBox::warning(this,"错误","不存在使用该名称的学院");
    }
    else
    {
        QStringList info;
        info.append(teacher_name);
        info.append(college_name);
        info.append(teacher_id);
        sqlOP::getInstance()->updateTeacherInfos(info);
        this->close();
    }
}
