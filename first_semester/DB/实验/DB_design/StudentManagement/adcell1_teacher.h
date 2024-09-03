#ifndef ADCELL1_TEACHER_H
#define ADCELL1_TEACHER_H

#include <QDialog>
#include<QStandardItem>

namespace Ui {
class adcell1_teacher;
}

class adcell1_teacher : public QDialog
{
    Q_OBJECT

public:
    explicit adcell1_teacher(QWidget *parent = nullptr);
    ~adcell1_teacher();

    void initPage(QString strCondition="");

private slots:
    void on_btn_search_clicked();

    void on_pushButton_clicked();

    void on_btn_deleteTeacher_clicked();

    void on_btn_addTeacher_clicked();

    void on_btn_modifyTeacher_clicked();

private:
    Ui::adcell1_teacher *ui;
    QStandardItemModel m_model;
};

#endif // ADCELL1_TEACHER_H
