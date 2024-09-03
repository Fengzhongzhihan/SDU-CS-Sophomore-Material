#ifndef ADCELL1_COURSESET_H
#define ADCELL1_COURSESET_H

#include <QDialog>
#include<QStandardItem>

namespace Ui {
class adcell1_courseSet;
}

class adcell1_courseSet : public QDialog
{
    Q_OBJECT

public:
    explicit adcell1_courseSet(QWidget *parent = nullptr);
    ~adcell1_courseSet();

    void initPage(QString strCondition="");

private slots:
    void on_btn_search_clicked();

    void on_btn_print_clicked();

    void on_btn_searchtime_clicked();

    void on_btn_courseStudent_clicked();

    void on_btn_deltime_clicked();

    void on_btn_delCourSet_clicked();

    void on_btn_courseSet_clicked();

    void on_btn_addtime_clicked();

    void on_btn_updateCourseSet_clicked();

private:
    Ui::adcell1_courseSet *ui;
    QStandardItemModel m_model;
};

#endif // ADCELL1_COURSESET_H
