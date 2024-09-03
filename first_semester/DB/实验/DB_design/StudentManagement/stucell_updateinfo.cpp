#include "stucell_updateinfo.h"
#include "ui_stucell_updateinfo.h"
#include "sqlop.h"

stucell_updateInfo::stucell_updateInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stucell_updateInfo)
{
    ui->setupUi(this);
}

stucell_updateInfo::~stucell_updateInfo()
{
    delete ui;
}

void stucell_updateInfo::on_commitButton_clicked()
{
    QStringList info;
    info.append(ui->name->text());
    info.append(ui->age->text());
    info.append(ui->grade->text());
    info.append(ui->m_class->text());
    info.append(ui->identity_id->text());
    info.append(ui->sex->currentText());
    info.append(ui->major->text());
    info.append(sid);
    sqlOP::getInstance()->updateStudentInfos(info);
    hide();
}

void stucell_updateInfo::on_cancelButton_clicked()
{
    this->close();
}
