#ifndef ADCELL2_UPDATESCORE_H
#define ADCELL2_UPDATESCORE_H

#include <QDialog>

namespace Ui {
class adcell2_updateScore;
}

class adcell2_updateScore : public QDialog
{
    Q_OBJECT

public:
    explicit adcell2_updateScore(QWidget *parent = nullptr);
    ~adcell2_updateScore();

    void setStudentId(QString id)
    {
        this->student_id=id;
    }

    void setCourseSetId(QString id)
    {
        this->courseSet_id=id;
    }

private slots:
    void on_cancelButton_clicked();

    void on_commitButton_clicked();

private:
    Ui::adcell2_updateScore *ui;
    QString student_id;
    QString courseSet_id;
};

#endif // ADCELL2_UPDATESCORE_H
