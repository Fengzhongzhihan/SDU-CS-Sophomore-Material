#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include<QProcess>
#include <QString>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QtDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QTableWidget>
#include <QMainWindow>
#include <studentuser.h>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class login; }
QT_END_NAMESPACE

class login : public QMainWindow
{
    Q_OBJECT

public:
    login(QWidget *parent = nullptr);
    ~login();
    void paintEvent(QPaintEvent* event);

private slots:
    void on_loginButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::login *ui;
        QSqlDatabase db= QSqlDatabase::addDatabase("QMYSQL");;
};
#endif // LOGIN_H
