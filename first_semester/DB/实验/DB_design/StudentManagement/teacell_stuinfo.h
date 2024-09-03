#ifndef TEACELL_STUINFO_H
#define TEACELL_STUINFO_H

#include <QDialog>
#include <QStandardItemModel>
namespace Ui {
class teacell_stuInfo;
}

class teacell_stuInfo : public QDialog
{
    Q_OBJECT

public:
    explicit teacell_stuInfo(QWidget *parent = nullptr);
    ~teacell_stuInfo();
    void initPage(QString strCondition="");
    void setTid(QString id)
    {
        tid=id;
    }
private slots:
    void on_findMyStudent_clicked();

    void on_printStudent_clicked();

    void on_showMyCourse_clicked();

    void on_searchStudent_clicked();

private:
    Ui::teacell_stuInfo *ui;
    QStandardItemModel m_model;
    QString tid;
};

#endif // TEACELL_STUINFO_H
