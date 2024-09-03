#include "adcell2_updatestudent.h"
#include "ui_adcell2_updatestudent.h"
#include<sqlop.h>

adcell2_updateStudent::adcell2_updateStudent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adcell2_updateStudent)
{
    ui->setupUi(this);
}

adcell2_updateStudent::~adcell2_updateStudent()
{
    delete ui;
}

void adcell2_updateStudent::on_cancelButton_clicked()
{
    this->close();
}

void adcell2_updateStudent::on_commitButton_clicked()
{
    QString name = ui->name->text();
    QString age = ui->age->text();
    QString grade = ui->grade->text();
    QString classes = ui->classes->text();
    QString identity_id = ui->identity_id->text();
    QString sex = ui->sex->currentText();
    QString major = ui->major->text();
    if(name == "")
    {
        QMessageBox::warning(this,"错误","请输入姓名");
    }
    else if(age == "")
    {
        QMessageBox::warning(this,"错误","请输入年龄");
    }
    else if(grade == "")
    {
        QMessageBox::warning(this,"错误","请输入年级");
    }
    else if(classes == "")
    {
        QMessageBox::warning(this,"错误","请输入班级");
    }
    else if(identity_id == "")
    {
        QMessageBox::warning(this,"错误","请输入身份证号");
    }
    else if(identity_id.size()<6)
    {
        QMessageBox::warning(this,"错误","身份证长度不正确");
    }
    else if(sex == "")
    {
        QMessageBox::warning(this,"错误","请输入性别");
    }
    else if(major == "")
    {
        QMessageBox::warning(this,"错误","请输入专业");
    }
    else if(sqlOP::getInstance()->isIdentityExist(student_id))
    {
        QMessageBox::warning(this,"错误","已存在使用该身份证的学生");
    }
    else if(!sqlOP::getInstance()->isMajorExistByName(major))
    {
        QMessageBox::warning(this,"错误","不存在该专业名称");
    }
    else
    {
        QStringList info;
        info.append(ui->name->text());
        info.append(ui->age->text());
        info.append(ui->grade->text());
        info.append(ui->classes->text());
        info.append(ui->identity_id->text());
        info.append(ui->sex->currentText());
        info.append(ui->major->text());
        info.append(student_id);
        sqlOP::getInstance()->updateStudentInfos(info);
        this->close();
    }
}
