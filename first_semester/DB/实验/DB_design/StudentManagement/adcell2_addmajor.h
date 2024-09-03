#ifndef ADCELL2_ADDMAJOR_H
#define ADCELL2_ADDMAJOR_H

#include <QDialog>

namespace Ui {
class adcell2_addMajor;
}

class adcell2_addMajor : public QDialog
{
    Q_OBJECT

public:
    explicit adcell2_addMajor(QWidget *parent = nullptr);
    ~adcell2_addMajor();

private slots:
    void on_btn_cancel_clicked();

    void on_btn_commit_clicked();

private:
    Ui::adcell2_addMajor *ui;
};

#endif // ADCELL2_ADDMAJOR_H
