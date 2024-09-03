#ifndef STUCELL_PA_H
#define STUCELL_PA_H

#include <QDialog>
#include <QStandardItemModel>
namespace Ui {
class stucell_pa;
}

class stucell_pa : public QDialog
{
    Q_OBJECT

public:
    explicit stucell_pa(QWidget *parent = nullptr);
    ~stucell_pa();
    void setSid(QString id)
    {
        this->sid=id;
    }
private slots:

    void on_showPA_clicked();

private:
    Ui::stucell_pa *ui;
    QStandardItemModel m_model;
    QString sid;
};

#endif // STUCELL_PA_H

//QStandardItemModel m_model;
//QString tid;
