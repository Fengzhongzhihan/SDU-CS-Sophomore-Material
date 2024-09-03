#ifndef ADCELL1_COLLEGE_H
#define ADCELL1_COLLEGE_H

#include <QDialog>
#include<QStandardItem>

namespace Ui {
class adcell1_college;
}

class adcell1_college : public QDialog
{
    Q_OBJECT

public:
    explicit adcell1_college(QWidget *parent = nullptr);
    ~adcell1_college();

    void initPage(QString strCondition="");

private slots:
    void on_btn_search_clicked();

    void on_btn_print_clicked();

    void on_btn_deletemajor_clicked();

    void on_btn_deleteCollege_clicked();

    void on_btn_addCollege_clicked();

    void on_btn_addmajor_clicked();

private:
    Ui::adcell1_college *ui;
    QStandardItemModel m_model;
};

#endif // ADCELL1_COLLEGE_H
