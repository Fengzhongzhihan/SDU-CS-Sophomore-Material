#ifndef TEACELL_UPDATESTUINFO_H
#define TEACELL_UPDATESTUINFO_H

#include <QDialog>

namespace Ui {
class teacell_updateStuInfo;
}

class teacell_updateStuInfo : public QDialog
{
    Q_OBJECT

public:
    explicit teacell_updateStuInfo(QWidget *parent = nullptr);
    ~teacell_updateStuInfo();

    void setSid(QString str);
    void setName(QString str);
    void setCourse(QString str);
    void setCourseSet(QString str);

private slots:
    void on_commitBtn_clicked();

    void on_cancelBtn_clicked();

private:
    Ui::teacell_updateStuInfo *ui;
};

#endif // TEACELL_UPDATESTUINFO_H
