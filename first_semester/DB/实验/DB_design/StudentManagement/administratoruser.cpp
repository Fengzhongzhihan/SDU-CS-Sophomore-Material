#include "administratoruser.h"
#include "ui_administratoruser.h"

#include<QtDebug>

administratorUser::administratorUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::administratorUser)
{
    ui->setupUi(this);
}

administratorUser::~administratorUser()
{
    delete ui;
}

void administratorUser::initPage()
{
    ad_stuPage = new adcell1_student(this);
    ad_teaPage = new adcell1_teacher(this);
    ad_coursePage = new adcell1_course(this);
    ad_collegePage = new adcell1_college(this);
    ad_adPage = new adcell1_administrator(this);
    ad_adPage->setAdministratorId(administrator_id);
    ad_takesPage = new adcell1_takes(this);
    ad_scorePage = new adcell1_score(this);
    ad_stuPaPage = new adcell1_stuPa(this);
    ad_courseSetPage = new adcell1_courseSet(this);
    ui->stackedWidget->addWidget(ad_stuPage);
    ui->stackedWidget->addWidget(ad_takesPage);
    ui->stackedWidget->addWidget(ad_stuPaPage);
    ui->stackedWidget->addWidget(ad_teaPage);
    ui->stackedWidget->addWidget(ad_coursePage);
    ui->stackedWidget->addWidget(ad_courseSetPage);
    ui->stackedWidget->addWidget(ad_scorePage);
    ui->stackedWidget->addWidget(ad_collegePage);
    ui->stackedWidget->addWidget(ad_adPage);
    auto l = ui->widget->children();
    for(auto it:l)
    {
        if(it->objectName().contains("btn"))
        {
            connect(static_cast<QPushButton*>(it),&QPushButton::clicked,this,&administratorUser::dealMean);
        }
    }
    ui->stackedWidget->setCurrentIndex(0);
    ad_stuPage->initPage();

}
void administratorUser:: dealMean()
{
    auto str = sender()->objectName();

    if("btn_stu" == str)
    {
        ui->stackedWidget->setCurrentIndex(0);
        ad_stuPage->initPage();
    }
    else if("btn_takes" == str)
    {
        ui->stackedWidget->setCurrentIndex(1);
        ad_takesPage->initPage();
    }
    else if("btn_stupa" == str)
    {
        ui->stackedWidget->setCurrentIndex(2);
        ad_stuPaPage->initPage();
    }
    else if("btn_tea" == str)
    {
        ui->stackedWidget->setCurrentIndex(3);
        ad_teaPage->initPage();
    }
    else if("btn_course" == str)
    {
        ui->stackedWidget->setCurrentIndex(4);
        ad_coursePage->initPage();
    }
    else if("btn_courseSet"==str)
    {
        ui->stackedWidget->setCurrentIndex(5);
        ad_courseSetPage->initPage();
    }
    else if("btn_score"==str)
    {
        ui->stackedWidget->setCurrentIndex(6);
        ad_scorePage->initPage();
    }
    else if("btn_college"==str)
    {
        ui->stackedWidget->setCurrentIndex(7);
        ad_collegePage->initPage();
    }
    else if("btn_administrator"==str)
    {
        ui->stackedWidget->setCurrentIndex(8);
        ad_adPage->initPage("where root = 3");
    }
}
