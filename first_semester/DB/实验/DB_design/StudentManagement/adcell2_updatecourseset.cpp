#include "adcell2_updatecourseset.h"
#include "ui_adcell2_updatecourseset.h"
#include<sqlop.h>

adcell2_updateCourseSet::adcell2_updateCourseSet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adcell2_updateCourseSet)
{
    ui->setupUi(this);
}

adcell2_updateCourseSet::~adcell2_updateCourseSet()
{
    delete ui;
}

void adcell2_updateCourseSet::on_cancelButton_clicked()
{
    this->close();
}

void adcell2_updateCourseSet::on_commitButton_clicked()
{
    QString teacher_id = ui->teacher_id->text();
    QString course_id = ui->course_id->text();
    QString address = ui->address->text();
    QString time_id = ui->time_id->text();
    QString college_id = ui->college_id->text();
    QString campus = ui->campus->text();
    QString classification = ui->classification->text();
    if(teacher_id == "")
    {
        QMessageBox::warning(this,"错误","请输入教师编号");
    }
    else if(course_id == "")
    {
        QMessageBox::warning(this,"错误","请输入课程编号");
    }
    else if(address == "")
    {
        QMessageBox::warning(this,"错误","请输入上课地址");
    }
    else if(time_id == "")
    {
        QMessageBox::warning(this,"错误","请输入时间编号");
    }
    else if(college_id == "")
    {
        QMessageBox::warning(this,"错误","请输入开设学院的编号");
    }
    else if(campus == "")
    {
        QMessageBox::warning(this,"错误","请输入开设校区");
    }
    else if(classification == "")
    {
        QMessageBox::warning(this,"错误","请输入课程分类");
    }
    else if(!sqlOP::getInstance()->isTeacherExist(teacher_id))
    {
        QMessageBox::warning(this,"错误","不存在使用该id的教师");
    }
    else if(!sqlOP::getInstance()->isCourseExist(course_id))
    {
        QMessageBox::warning(this,"错误","不存在使用该id的课程");
    }
    else if(!sqlOP::getInstance()->isTimeExist(time_id))
    {
        QMessageBox::warning(this,"错误","不存在使用该id的时间编号");
    }
    else if(!sqlOP::getInstance()->isCollegeExist(college_id))
    {
        QMessageBox::warning(this,"错误","不存在使用该id的学院");
    }
    else
    {
        QStringList info;
        info.append(courseSet_id);
        info.append(teacher_id);
        info.append(course_id);
        info.append(address);
        info.append(time_id);
        info.append(college_id);
        info.append(campus);
        info.append(classification);
        sqlOP::getInstance()->updateCourseSetInfos(info);
        this->close();
    }
}
