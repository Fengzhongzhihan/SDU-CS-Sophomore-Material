#ifndef ADCELL2_ADDCOURSE_H
#define ADCELL2_ADDCOURSE_H

#include <QDialog>

namespace Ui {
class adcell2_addCourse;
}

class adcell2_addCourse : public QDialog
{
    Q_OBJECT

public:
    explicit adcell2_addCourse(QWidget *parent = nullptr);
    ~adcell2_addCourse();

private slots:
    void on_btn_cancel_clicked();

    void on_btn_commit_clicked();

private:
    Ui::adcell2_addCourse *ui;
};

#endif // ADCELL2_ADDCOURSE_H
