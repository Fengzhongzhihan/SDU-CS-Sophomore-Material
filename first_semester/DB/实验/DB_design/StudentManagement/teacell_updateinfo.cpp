#include "teacell_updateinfo.h"
#include "ui_teacell_updateinfo.h"
#include "sqlop.h"

teacell_updateInfo::teacell_updateInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::teacell_updateInfo)
{
    ui->setupUi(this);
}

teacell_updateInfo::~teacell_updateInfo()
{
    delete ui;
}

void teacell_updateInfo::on_commitButton_clicked()
{
    QStringList info;
    info.append(ui->name->text());
    info.append(ui->college->text());
    info.append(tid);
    sqlOP::getInstance()->updateTeacherInfos(info);
    hide();
}

void teacell_updateInfo::on_cancelButton_clicked()
{
    this->close();
}
