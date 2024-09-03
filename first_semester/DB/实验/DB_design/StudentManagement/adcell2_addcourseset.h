#ifndef ADCELL2_ADDCOURSESET_H
#define ADCELL2_ADDCOURSESET_H

#include <QDialog>

namespace Ui {
class adcell2_addCourseSet;
}

class adcell2_addCourseSet : public QDialog
{
    Q_OBJECT

public:
    explicit adcell2_addCourseSet(QWidget *parent = nullptr);
    ~adcell2_addCourseSet();

private slots:
    void on_cancelButton_clicked();

    void on_commitButton_clicked();

private:
    Ui::adcell2_addCourseSet *ui;
};

#endif // ADCELL2_ADDCOURSESET_H
