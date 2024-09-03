#include "adcell2_addstudent.h"
#include "ui_adcell2_addstudent.h"
#include<sqlop.h>

adcell2_addStudent::adcell2_addStudent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adcell2_addStudent)
{
    ui->setupUi(this);
}

adcell2_addStudent::~adcell2_addStudent()
{
    delete ui;
}

void adcell2_addStudent::on_cancelButton_clicked()
{
    this->close();
}

void adcell2_addStudent::on_commitButton_clicked()
{
    QString name = ui->name->text();
    QString age = ui->age->text();
    QString grade = ui->grade->text();
    QString classes = ui->classes->text();
    QString identity_id = ui->identity_id->text();
    QString sex = ui->sex->currentText();
    QString major = ui->major->text();
    QString sid = ui->sid->text();
    if(sid == "")
    {
        QMessageBox::warning(this,"错误","请输入学号");
    }
    else if(name == "")
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
    else if(sqlOP::getInstance()->isStudentExist(sid))
    {
        QMessageBox::warning(this,"错误","已存在使用该id的学生");
    }
    else if(sqlOP::getInstance()->isIdentityExist(sid))
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
        info.append(ui->sid->text());
        sqlOP::getInstance()->addStudentInfos(info);
        this->close();
    }

}
