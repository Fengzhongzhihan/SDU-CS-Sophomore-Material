#ifndef ADCELL2_ADDADMINISTRATOR_H
#define ADCELL2_ADDADMINISTRATOR_H

#include <QDialog>

namespace Ui {
class adcell2_addAdministrator;
}

class adcell2_addAdministrator : public QDialog
{
    Q_OBJECT

public:
    explicit adcell2_addAdministrator(QWidget *parent = nullptr);
    ~adcell2_addAdministrator();

private slots:
    void on_btn_cancel_clicked();

    void on_btn_commit_clicked();

private:
    Ui::adcell2_addAdministrator *ui;
};

#endif // ADCELL2_ADDADMINISTRATOR_H
