#ifndef STUDENTUSER_H
#define STUDENTUSER_H

#include <QDialog>
#include <stucell_course.h>
#include <stucell_grade.h>
#include <stucell_info.h>
#include <stucell_pa.h>
#include <QtDebug>

namespace Ui {
class StudentUser;
}

class StudentUser : public QDialog
{
    Q_OBJECT

public:
    explicit StudentUser(QWidget *parent = nullptr);
    ~StudentUser();


    void initPage();

    void dealPage();

    void setSid(QString id)
    {
        this->sid=id;
    }
private:
    Ui::StudentUser *ui;
    QString sid;

    stucell_pa * stuPA ;
    stucell_grade *stuGrade ;
    stucell_course * stuCourse ;
    stucell_info * stuInfo ;

};

#endif // STUDENTUSER_H
