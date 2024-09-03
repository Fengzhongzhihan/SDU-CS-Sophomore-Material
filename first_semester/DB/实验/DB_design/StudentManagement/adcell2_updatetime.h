#ifndef ADCELL2_UPDATETIME_H
#define ADCELL2_UPDATETIME_H

#include <QDialog>

namespace Ui {
class adcell2_updateTime;
}

class adcell2_updateTime : public QDialog
{
    Q_OBJECT

public:
    explicit adcell2_updateTime(QWidget *parent = nullptr);
    ~adcell2_updateTime();

private:
    Ui::adcell2_updateTime *ui;
};

#endif // ADCELL2_UPDATETIME_H
