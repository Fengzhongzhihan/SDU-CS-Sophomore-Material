#ifndef STUCELL_UPDATEINFO_H
#define STUCELL_UPDATEINFO_H

#include <QDialog>

namespace Ui {
class stucell_updateInfo;
}

class stucell_updateInfo : public QDialog
{
    Q_OBJECT

public:
    explicit stucell_updateInfo(QWidget *parent = nullptr);
    ~stucell_updateInfo();
    void setSid(QString id)
    {
        this->sid=id;
    }

private slots:
    void on_commitButton_clicked();


    void on_cancelButton_clicked();

private:
    Ui::stucell_updateInfo *ui;
    QString sid;
};

#endif // STUCELL_UPDATEINFO_H
