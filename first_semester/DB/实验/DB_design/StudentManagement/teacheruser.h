#ifndef TEACHERUSER_H
#define TEACHERUSER_H

#include <QDialog>
#include"teacell_course.h"
#include"teacell_score.h"
#include "teacell_stuinfo.h"
#include "teacell_teainfo.h"
#include <QtDebug>
namespace Ui {
class teacherUser;
}

class teacherUser : public QDialog
{
    Q_OBJECT

public:
    explicit teacherUser(QWidget *parent = nullptr);
    ~teacherUser();
    void setTid(QString id)
    {
        tid=id;
    }

    void initPage();

    void dealPage();
private:
    Ui::teacherUser *ui;
    QStandardItemModel m_model;
    QString tid;

    teacell_course * teaCourse;
    teacell_score * teaScore;
    teacell_stuInfo * stuInfo;
    teacell_teaInfo * teaInfo;
};

#endif // TEACHERUSER_H
