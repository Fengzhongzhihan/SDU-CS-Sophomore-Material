#ifndef ADCELL2_ADDSTUDENT_H
#define ADCELL2_ADDSTUDENT_H

#include <QDialog>

namespace Ui {
class adcell2_addStudent;
}

class adcell2_addStudent : public QDialog
{
    Q_OBJECT

public:
    explicit adcell2_addStudent(QWidget *parent = nullptr);
    ~adcell2_addStudent();

private slots:
    void on_cancelButton_clicked();

    void on_commitButton_clicked();

private:
    Ui::adcell2_addStudent *ui;
};

#endif // ADCELL2_ADDSTUDENT_H
