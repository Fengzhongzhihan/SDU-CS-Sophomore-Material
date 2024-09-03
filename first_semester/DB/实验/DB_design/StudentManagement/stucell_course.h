#ifndef STUCELL_COURSE_H
#define STUCELL_COURSE_H

#include <QDialog>
#include <QStandardItemModel>

namespace Ui {
class stucell_course;
}

class stucell_course : public QDialog
{
    Q_OBJECT

public:
    explicit stucell_course(QWidget *parent = nullptr);
    ~stucell_course();

    void initPage(QString strCondition="");
    void setSid(QString id)
    {
        this->sid=id;
    }
private slots:
    void on_showCourse_clicked();

    void on_selectCourse_clicked();

    void on_quitCourse_clicked();

    void on_myCourse_clicked();

private:
    Ui::stucell_course *ui;
    QStandardItemModel m_model;
    QString sid;
};

#endif // STUCELL_COURSE_H
