#include "adcell2_updatecourse.h"
#include "ui_adcell2_updatecourse.h"
#include<sqlop.h>

adcell2_updateCourse::adcell2_updateCourse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adcell2_updateCourse)
{
    ui->setupUi(this);
}

adcell2_updateCourse::~adcell2_updateCourse()
{
    delete ui;
}

void adcell2_updateCourse::on_cancelButton_clicked()
{
    this->close();
}

void adcell2_updateCourse::on_commitButton_clicked()
{
    QString course_name = ui->course_name->text();
    QString credit = ui->credit->text();
    if(course_name == "")
    {
        QMessageBox::warning(this,"错误","请输入课程名称");
    }
    else if(credit == "")
    {
        QMessageBox::warning(this,"错误","请输入该课程的学分");
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
        sqlOP::getInstance()->updateCourseInfos(info);
        this->close();
    }
}
