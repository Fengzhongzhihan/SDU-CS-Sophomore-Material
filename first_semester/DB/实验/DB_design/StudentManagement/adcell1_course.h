#ifndef ADCELL1_COURSE_H
#define ADCELL1_COURSE_H

#include <QDialog>
#include<QStandardItem>

namespace Ui {
class adcell1_course;
}

class adcell1_course : public QDialog
{
    Q_OBJECT

public:
    explicit adcell1_course(QWidget *parent = nullptr);
    ~adcell1_course();

    void initPage(QString strCondition="");

private slots:
    void on_btn_search_clicked();

    void on_pushButton_clicked();

    void on_btn_deleteCourse_clicked();

    void on_btn_addCourse_clicked();

    void on_btn_updateCourseInfo_clicked();

private:
    Ui::adcell1_course *ui;
    QStandardItemModel m_model;
};

#endif // ADCELL1_COURSE_H
