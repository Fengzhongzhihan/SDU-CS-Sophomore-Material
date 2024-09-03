#ifndef ADCELL2_UPDATESTUDENT_H
#define ADCELL2_UPDATESTUDENT_H

#include <QDialog>

namespace Ui {
class adcell2_updateStudent;
}

class adcell2_updateStudent : public QDialog
{
    Q_OBJECT

public:
    explicit adcell2_updateStudent(QWidget *parent = nullptr);
    ~adcell2_updateStudent();

    void setStudentId(QString id)
    {
        this->student_id=id;
    }

private slots:
    void on_cancelButton_clicked();

    void on_commitButton_clicked();

private:
    Ui::adcell2_updateStudent *ui;
    QString student_id;
};

#endif // ADCELL2_UPDATESTUDENT_H
