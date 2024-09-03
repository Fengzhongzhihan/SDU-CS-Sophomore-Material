#ifndef ADCELL1_TAKES_H
#define ADCELL1_TAKES_H

#include <QDialog>
#include<QStandardItem>

namespace Ui {
class adcell1_takes;
}

class adcell1_takes : public QDialog
{
    Q_OBJECT

public:
    explicit adcell1_takes(QWidget *parent = nullptr);
    ~adcell1_takes();

    void initPage(QString strCondition="");

private slots:
    void on_btn_showCourse_clicked();

    void on_pushButton_clicked();

    void on_btn_myCourse_clicked();

    void on_btn_selectCourse_clicked();

    void on_btn_quitCourse_clicked();

private:
    Ui::adcell1_takes *ui;
    QStandardItemModel m_model;
};

#endif // ADCELL1_TAKES_H
