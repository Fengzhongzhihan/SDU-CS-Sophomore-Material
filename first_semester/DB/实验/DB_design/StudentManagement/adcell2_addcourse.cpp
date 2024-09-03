#include "adcell2_addcourse.h"
#include "ui_adcell2_addcourse.h"
#include<sqlop.h>

adcell2_addCourse::adcell2_addCourse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adcell2_addCourse)
{
    ui->setupUi(this);
}

adcell2_addCourse::~adcell2_addCourse()
{
    delete ui;
}

void adcell2_addCourse::on_btn_cancel_clicked()
{
    this->close();
}

void adcell2_addCourse::on_btn_commit_clicked()
{
    QString course_id = ui->course_id->text();
    QString course_name = ui->course_name->text();
    QString credit = ui->credit->text();
    if(course_id == "")
    {
        QMessageBox::warning(this,"错误","请输入课程编号");
    }
    else if(course_name == "")
    {
        QMessageBox::warning(this,"错误","请输入课程名称");
    }
    else if(credit == "")
    {
        QMessageBox::warning(this,"错误","请输入该课程的学分");
    }
    else if(sqlOP::getInstance()->isCourseExist(course_id))
    {
        QMessageBox::warning(this,"错误","已存在使用该id的课程");
    }
    else if(sqlOP::getInstance()->isCourseExistByName(course_name))
    {
        QMessageBox::warning(this,"错误","已存在使用该名称的课程");
    }
    else
    {
        QStringList info;
        info.append(course_id);
        info.append(course_name);
        info.append(credit);
        sqlOP::getInstance()->addCourseInfos(info);
        this->close();
    }
}
