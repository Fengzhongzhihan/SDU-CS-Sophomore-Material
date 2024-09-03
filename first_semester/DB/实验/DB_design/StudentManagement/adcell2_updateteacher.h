#ifndef ADCELL2_UPDATETEACHER_H
#define ADCELL2_UPDATETEACHER_H

#include <QDialog>

namespace Ui {
class adcell2_updateTeacher;
}

class adcell2_updateTeacher : public QDialog
{
    Q_OBJECT

public:
    explicit adcell2_updateTeacher(QWidget *parent = nullptr);
    ~adcell2_updateTeacher();

    void setTeacherId(QString id)
    {
        this->teacher_id=id;
    }

private slots:
    void on_btn_cancel_clicked();

    void on_btn_commit_clicked();

private:
    Ui::adcell2_updateTeacher *ui;
    QString teacher_id;
};

#endif // ADCELL2_UPDATETEACHER_H
