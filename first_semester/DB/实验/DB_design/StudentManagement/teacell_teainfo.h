#ifndef TEACELL_TEAINFO_H
#define TEACELL_TEAINFO_H

#include <QDialog>
#include <QStandardItemModel>
namespace Ui {
class teacell_teaInfo;
}

class teacell_teaInfo : public QDialog
{
    Q_OBJECT

public:
    explicit teacell_teaInfo(QWidget *parent = nullptr);
    ~teacell_teaInfo();
    void initPage(QString strCondition="");
    void setTid(QString id)
    {
        tid=id;
    }
private slots:
    void on_showMyinfo_clicked();

    void on_updateMyinfo_clicked();

private:
    Ui::teacell_teaInfo *ui;
    QStandardItemModel m_model;
    QString tid;
};

#endif // TEACELL_TEAINFO_H
