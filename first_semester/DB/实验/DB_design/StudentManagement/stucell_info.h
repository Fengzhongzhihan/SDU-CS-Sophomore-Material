#ifndef STUCELL_INFO_H
#define STUCELL_INFO_H
#include "sqlop.h"
#include <QDialog>
#include <QStandardItemModel>
namespace Ui {
class stucell_info;
}

class stucell_info : public QDialog
{
    Q_OBJECT

public:
    explicit stucell_info(QWidget *parent = nullptr);
    ~stucell_info();

    void initPage(QString strCondition="");
    void setSid(QString id)
    {
        this->sid=id;
    }
private slots:
    void on_SelectInfo_clicked();

    void on_UpdateInfo_clicked();

private:
    Ui::stucell_info *ui;
    QStandardItemModel m_model;
    QString sid;
};

#endif // STUCELL_INFO_H
