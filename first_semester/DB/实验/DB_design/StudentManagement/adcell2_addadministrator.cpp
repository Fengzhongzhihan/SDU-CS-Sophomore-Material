#include "adcell2_addadministrator.h"
#include "ui_adcell2_addadministrator.h"
#include<sqlop.h>

adcell2_addAdministrator::adcell2_addAdministrator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adcell2_addAdministrator)
{
    ui->setupUi(this);
}

adcell2_addAdministrator::~adcell2_addAdministrator()
{
    delete ui;
}

void adcell2_addAdministrator::on_btn_cancel_clicked()
{
    this->close();
}

void adcell2_addAdministrator::on_btn_commit_clicked()
{
    QString administrator_id = ui->administrator_id->text();
    QString administrator_password = ui->administrator_password->text();
    if(administrator_id == "")
    {
        QMessageBox::warning(this,"错误","请输入账户信息");
    }
    else if(administrator_password == "")
    {
        QMessageBox::warning(this,"错误","请输入账号密码");
    }
    else if(sqlOP::getInstance()->isAdministratorExist(administrator_id))
    {
        QMessageBox::warning(this,"错误","已存在使用该id的账号");
    }
    else
    {
        QStringList info;
        info.append(administrator_id);
        info.append(administrator_password);
        sqlOP::getInstance()->addAdministratorInfos(info);
        this->close();
    }
}
