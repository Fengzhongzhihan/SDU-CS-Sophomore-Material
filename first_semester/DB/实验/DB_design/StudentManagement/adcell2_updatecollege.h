#ifndef ADCELL2_UPDATECOLLEGE_H
#define ADCELL2_UPDATECOLLEGE_H

#include <QDialog>

namespace Ui {
class adcell2_updateCollege;
}

class adcell2_updateCollege : public QDialog
{
    Q_OBJECT

public:
    explicit adcell2_updateCollege(QWidget *parent = nullptr);
    ~adcell2_updateCollege();

private:
    Ui::adcell2_updateCollege *ui;
};

#endif // ADCELL2_UPDATECOLLEGE_H
