#ifndef ADMINISTRATORUSER_H
#define ADMINISTRATORUSER_H

#include <QDialog>
#include<adcell1_student.h>
#include<adcell1_teacher.h>
#include<adcell1_course.h>
#include<adcell1_college.h>
#include<adcell1_administrator.h>
#include<adcell1_takes.h>
#include<adcell1_score.h>
#include<adcell1_stupa.h>
#include<adcell1_courseset.h>
#include<QtDebug>
#include<qpushbutton.h>

namespace Ui {
class administratorUser;
}

class administratorUser : public QDialog
{
    Q_OBJECT

public:
    explicit administratorUser(QWidget *parent = nullptr);
    ~administratorUser();

    void initPage();

    void dealPage();

    void dealMean();

    void setAdministratorId(QString id)
    {
        this->administrator_id=id;
    }

private:
    Ui::administratorUser *ui;

    QString administrator_id;

    adcell1_student *ad_stuPage;
    adcell1_teacher *ad_teaPage;
    adcell1_course *ad_coursePage;
    adcell1_college *ad_collegePage;
    adcell1_administrator *ad_adPage;
    adcell1_takes *ad_takesPage;
    adcell1_score *ad_scorePage;
    adcell1_stuPa *ad_stuPaPage;
    adcell1_courseSet * ad_courseSetPage;
};

#endif // ADMINISTRATORUSER_H
