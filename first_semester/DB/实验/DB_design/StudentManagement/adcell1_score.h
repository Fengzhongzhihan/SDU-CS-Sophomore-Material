#ifndef ADCELL1_SCORE_H
#define ADCELL1_SCORE_H

#include <QDialog>
#include<QStandardItem>

namespace Ui {
class adcell1_score;
}

class adcell1_score : public QDialog
{
    Q_OBJECT

public:
    explicit adcell1_score(QWidget *parent = nullptr);
    ~adcell1_score();

    void initPage(QString strCondition="");

private slots:
    void on_btn_searchScore_clicked();

    void on_btn_print_clicked();

    void on_btn_statistics_clicked();

    void on_btn_updateScore_clicked();

private:
    Ui::adcell1_score *ui;
    QStandardItemModel m_model;
};

#endif // ADCELL1_SCORE_H
