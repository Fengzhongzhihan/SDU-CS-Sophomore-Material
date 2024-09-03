#include "teacheruser.h"
#include "ui_teacheruser.h"
#include "sqlop.h"
teacherUser::teacherUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::teacherUser)
{
    ui->setupUi(this);
}

teacherUser::~teacherUser()
{
    delete ui;
}


void teacherUser::initPage()
{
    teaInfo =new teacell_teaInfo(this);
    teaInfo->setTid(tid);
    teaScore=new teacell_score(this);
    teaScore->setTid(tid);
    teaCourse=new teacell_course(this);
    teaCourse->setTid(tid);
    stuInfo=new teacell_stuInfo(this);
    stuInfo->setTid(tid);

     ui->stackedWidget->addWidget(teaInfo);
       ui->stackedWidget->addWidget(teaCourse);
       ui->stackedWidget->addWidget(teaScore);
  ui->stackedWidget->addWidget(stuInfo);

    ui->stackedWidget->setCurrentIndex(0);
  auto l= ui->tool->children();

  for(auto it:l)
  {
      if(it->objectName().contains("btn"))
      {
          connect(static_cast<QPushButton*>(it),&QPushButton::clicked,this,&teacherUser::dealPage);
      }
  }

}

void teacherUser::dealPage()
{
    QString str= sender()->objectName();
    if("btn_teaInfo"==str)
    {
        ui->stackedWidget->setCurrentIndex(0);
    }
    else if("btn_course"==str)
    {
        teaCourse->initPage();
        ui->stackedWidget->setCurrentIndex(1);
    }
    else if("btn_score"==str)
    {
//        teaCourse->initPage();
        ui->stackedWidget->setCurrentIndex(2);
    }
    else
    {
        stuInfo->initPage();
        ui->stackedWidget->setCurrentIndex(3);
    }
}
