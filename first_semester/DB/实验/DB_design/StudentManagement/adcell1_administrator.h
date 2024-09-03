#ifndef ADCELL1_ADMINISTRATOR_H
#define ADCELL1_ADMINISTRATOR_H

#include <QDialog>
#include <QStandardItemModel>

namespace Ui {
class adcell1_administrator;
}

class adcell1_administrator : public QDialog
{
    Q_OBJECT

public:
    explicit adcell1_administrator(QWidget *parent = nullptr);
    ~adcell1_administrator();

    void initPage(QString strCondition="");

    void setAdministratorId(QString id)
    {
        this->administrator_id=id;
    }

private slots:
    void on_btn_search_clicked();

    void on_btn_print_clicked();

    void on_btn_deleteAdministrator_clicked();

    void on_btn_addadministrator_clicked();

private:
    Ui::adcell1_administrator *ui;
    QStandardItemModel m_model;
    QString administrator_id;
};

#endif // ADCELL1_ADMINISTRATOR_H
