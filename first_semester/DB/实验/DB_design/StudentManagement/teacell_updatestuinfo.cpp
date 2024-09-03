#include "teacell_updatestuinfo.h"
#include "ui_teacell_updatestuinfo.h"
#include "sqlop.h"

teacell_updateStuInfo::teacell_updateStuInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::teacell_updateStuInfo)
{
    ui->setupUi(this);
}

teacell_updateStuInfo::~teacell_updateStuInfo()
{
    delete ui;
}

void teacell_updateStuInfo::setSid(QString str)
{
    ui->sid->setText(str);
    ui->sid->setEnabled(false);
}

void teacell_updateStuInfo::setName(QString str)
{
     ui->name->setText(str);
     ui->name->setEnabled(false);
}

void teacell_updateStuInfo::setCourse(QString str)
{
     ui->course->setText(str);
     ui->course->setEnabled(false);
}

void teacell_updateStuInfo::setCourseSet(QString str)
{
    ui->courseSet->setText(str);
    ui->courseSet->setEnabled(false);
}

void teacell_updateStuInfo::on_commitBtn_clicked()
{
    QString sid= ui->sid->text();
    QString courseId=ui->courseSet->text();
    QString score= ui->score->text();
    bool res=sqlOP::getInstance()->setScore(sid,courseId,score);
    if(res==true)
    {
        QMessageBox::information(NULL,"成功","修改学生信息成功!");
        hide();
    }
}

void teacell_updateStuInfo::on_cancelBtn_clicked()
{
    this->close();
}
