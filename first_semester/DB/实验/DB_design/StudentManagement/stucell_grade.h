#ifndef STUCELL_GRADE_H
#define STUCELL_GRADE_H

#include <QDialog>
#include <QStandardItemModel>

namespace Ui {
class stucell_grade;
}

class stucell_grade : public QDialog
{
    Q_OBJECT

public:
    explicit stucell_grade(QWidget *parent = nullptr);
    ~stucell_grade();
    void setSid(QString id)
    {
        this->sid=id;
    }
private slots:

    void on_showGrade_clicked();

    void on_printGrade_clicked();

    void on_reStudy_clicked();

    void on_reExam_clicked();

private:
    Ui::stucell_grade *ui;
    QStandardItemModel m_model;
    QString sid;
};

#endif // STUCELL_GRADE_H
