#ifndef ADCELL1_STUDENT_H
#define ADCELL1_STUDENT_H

#include <QDialog>
#include<QStandardItem>

namespace Ui {
class adcell1_student;
}

class adcell1_student : public QDialog
{
    Q_OBJECT

public:
    explicit adcell1_student(QWidget *parent = nullptr);
    ~adcell1_student();

    void initPage(QString strCondition="");

private slots:
    void on_btn_search_clicked();

    void on_pushButton_clicked();

    void on_btn_deletestu_clicked();

    void on_btn_addstu_clicked();

    void on_btn_updatastu_clicked();

private:
    Ui::adcell1_student *ui;
    QStandardItemModel m_model;
};

#endif // ADCELL1_STUDENT_H
