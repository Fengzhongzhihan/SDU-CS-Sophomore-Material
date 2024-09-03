#ifndef ADCELL2_ADDTEACHER_H
#define ADCELL2_ADDTEACHER_H

#include <QDialog>

namespace Ui {
class adcell2_addTeacher;
}

class adcell2_addTeacher : public QDialog
{
    Q_OBJECT

public:
    explicit adcell2_addTeacher(QWidget *parent = nullptr);
    ~adcell2_addTeacher();

private slots:
    void on_btn_cancel_clicked();

    void on_btn_commit_clicked();

private:
    Ui::adcell2_addTeacher *ui;
};

#endif // ADCELL2_ADDTEACHER_H
