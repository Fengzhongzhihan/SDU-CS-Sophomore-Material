#ifndef ADCELL2_ADDCOLLEGE_H
#define ADCELL2_ADDCOLLEGE_H

#include <QDialog>

namespace Ui {
class adcell2_addCollege;
}

class adcell2_addCollege : public QDialog
{
    Q_OBJECT

public:
    explicit adcell2_addCollege(QWidget *parent = nullptr);
    ~adcell2_addCollege();

private slots:
    void on_btn_cancel_clicked();

    void on_btn_commit_clicked();

private:
    Ui::adcell2_addCollege *ui;
};

#endif // ADCELL2_ADDCOLLEGE_H
