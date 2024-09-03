#ifndef ADCELL1_STUPA_H
#define ADCELL1_STUPA_H

#include <QDialog>
#include<QStandardItem>

namespace Ui {
class adcell1_stuPa;
}

class adcell1_stuPa : public QDialog
{
    Q_OBJECT

public:
    explicit adcell1_stuPa(QWidget *parent = nullptr);
    ~adcell1_stuPa();

    void initPage(QString strCondition="");

private slots:
    void on_btn_search_clicked();

    void on_btn_print_clicked();

    void on_btn_delPa_clicked();

    void on_btn_addPa_clicked();

private:
    Ui::adcell1_stuPa *ui;
    QStandardItemModel m_model;
};

#endif // ADCELL1_STUPA_H
