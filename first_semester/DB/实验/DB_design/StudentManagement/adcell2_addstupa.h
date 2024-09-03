#ifndef ADCELL2_ADDSTUPA_H
#define ADCELL2_ADDSTUPA_H

#include <QDialog>

namespace Ui {
class adcell2_addStuPa;
}

class adcell2_addStuPa : public QDialog
{
    Q_OBJECT

public:
    explicit adcell2_addStuPa(QWidget *parent = nullptr);
    ~adcell2_addStuPa();

    void setDate();

private slots:
    void on_btn_cancel_clicked();

    void on_btn_commit_clicked();

private:
    Ui::adcell2_addStuPa *ui;
};

#endif // ADCELL2_ADDSTUPA_H
