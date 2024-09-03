#ifndef ADCELL2_UPDATECOURSESET_H
#define ADCELL2_UPDATECOURSESET_H

#include <QDialog>

namespace Ui {
class adcell2_updateCourseSet;
}

class adcell2_updateCourseSet : public QDialog
{
    Q_OBJECT

public:
    explicit adcell2_updateCourseSet(QWidget *parent = nullptr);
    ~adcell2_updateCourseSet();

    void setCourseSetId(QString id)
    {
        this->courseSet_id=id;
    }

private slots:
    void on_cancelButton_clicked();

    void on_commitButton_clicked();

private:
    Ui::adcell2_updateCourseSet *ui;
    QString courseSet_id;
};

#endif // ADCELL2_UPDATECOURSESET_H
