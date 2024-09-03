#ifndef ADCELL2_ADDTIME_H
#define ADCELL2_ADDTIME_H

#include <QDialog>

namespace Ui {
class adcell2_addTime;
}

class adcell2_addTime : public QDialog
{
    Q_OBJECT

public:
    explicit adcell2_addTime(QWidget *parent = nullptr);
    ~adcell2_addTime();

private slots:
    void on_cancelButton_clicked();

    void on_commitButton_clicked();

private:
    Ui::adcell2_addTime *ui;
};

#endif // ADCELL2_ADDTIME_H
