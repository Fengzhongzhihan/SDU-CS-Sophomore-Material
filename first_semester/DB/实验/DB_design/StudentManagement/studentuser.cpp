#include "studentuser.h"
#include "ui_studentuser.h"

StudentUser::StudentUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentUser)
{
    ui->setupUi(this);
}

StudentUser::~StudentUser()
{
    delete ui;
}

void StudentUser::initPage()
{
    stuPA =new stucell_pa(this);
    stuPA->setSid(sid);
    stuInfo=new stucell_info(this);
    stuInfo->setSid(sid);
    stuGrade=new stucell_grade(this);
    stuGrade->setSid(sid);
    stuCourse=new stucell_course(this);
    stuCourse->setSid(sid);
     ui->stackedWidget->addWidget(stuInfo);
       ui->stackedWidget->addWidget(stuCourse);
       ui->stackedWidget->addWidget(stuGrade);
  ui->stackedWidget->addWidget(stuPA);
    ui->stackedWidget->setCurrentIndex(0);
  auto l= ui->tool->children();

  for(auto it:l)
  {
      if(it->objectName().contains("btn"))
      {
          connect(static_cast<QPushButton*>(it),&QPushButton::clicked,this,&StudentUser::dealPage);
      }
  }

}

void StudentUser::dealPage()
{
    QString str= sender()->objectName();
    if("btn_info"==str)
    {
        ui->stackedWidget->setCurrentIndex(0);
    }
    else if("btn_course"==str)
    {
        stuCourse->initPage();
        ui->stackedWidget->setCurrentIndex(1);
    }
    else if("btn_grade"==str)
    {
        ui->stackedWidget->setCurrentIndex(2);
    }
    else
    {
        ui->stackedWidget->setCurrentIndex(3);
    }
}


