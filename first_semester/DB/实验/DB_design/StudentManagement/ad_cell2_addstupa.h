#ifndef AD_CELL2_ADDSTUPA_H
#define AD_CELL2_ADDSTUPA_H

#include <QDialog>

namespace Ui {
class ad_cell2_addStuPa;
}

class ad_cell2_addStuPa : public QDialog
{
    Q_OBJECT

public:
    explicit ad_cell2_addStuPa(QWidget *parent = nullptr);
    ~ad_cell2_addStuPa();

private slots:
    void on_btn_cancel_clicked();

    void on_btn_commit_clicked();

private:
    Ui::ad_cell2_addStuPa *ui;
};

#endif // AD_CELL2_ADDSTUPA_H
