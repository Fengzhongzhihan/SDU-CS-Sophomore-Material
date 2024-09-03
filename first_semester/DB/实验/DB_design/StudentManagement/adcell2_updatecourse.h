#ifndef ADCELL2_UPDATECOURSE_H
#define ADCELL2_UPDATECOURSE_H

#include <QDialog>

namespace Ui {
class adcell2_updateCourse;
}

class adcell2_updateCourse : public QDialog
{
    Q_OBJECT

public:
    explicit adcell2_updateCourse(QWidget *parent = nullptr);
    ~adcell2_updateCourse();

    void setCourseId(QString id)
    {
        this->course_id=id;
    }

private slots:
    void on_cancelButton_clicked();

    void on_commitButton_clicked();

private:
    Ui::adcell2_updateCourse *ui;
    QString course_id;
};

#endif // ADCELL2_UPDATECOURSE_H
