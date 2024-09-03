#ifndef TEACELL_UPDATEINFO_H
#define TEACELL_UPDATEINFO_H

#include <QDialog>

namespace Ui {
class teacell_updateInfo;
}

class teacell_updateInfo : public QDialog
{
    Q_OBJECT

public:
    explicit teacell_updateInfo(QWidget *parent = nullptr);
    ~teacell_updateInfo();

    void setTid(QString id)
    {
        tid=id;
    }

private slots:
    void on_commitButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::teacell_updateInfo *ui;
    QString tid;
};

#endif // TEACELL_UPDATEINFO_H
