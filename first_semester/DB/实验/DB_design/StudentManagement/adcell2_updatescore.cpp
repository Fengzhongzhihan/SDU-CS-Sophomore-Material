#include "adcell2_updatescore.h"
#include "ui_adcell2_updatescore.h"
#include<sqlop.h>

adcell2_updateScore::adcell2_updateScore(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adcell2_updateScore)
{
    ui->setupUi(this);
}

adcell2_updateScore::~adcell2_updateScore()
{
    delete ui;
}

void adcell2_updateScore::on_cancelButton_clicked()
{
    this->close();
}

void adcell2_updateScore::on_commitButton_clicked()
{
    QString score = ui->score->text();
    if(score == "")
    {
        QMessageBox::warning(this,"错误","请输入成绩");
    }
    else
    {
        if(sqlOP::getInstance()->setScore(student_id,courseSet_id,score))
            QMessageBox::information(NULL,"成功","修改学生成绩成功!");
        this->close();
    }
}
