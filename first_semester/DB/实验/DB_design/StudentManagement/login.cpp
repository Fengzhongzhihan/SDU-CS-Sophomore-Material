#include "login.h"
#include "ui_login.h"
#include "teacheruser.h"
#include"administratoruser.h"

login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
}



login::~login()
{
    delete ui;
}

void login::paintEvent(QPaintEvent *event)
{
    QPalette PAllbackground = this->palette();
    QImage ImgAllbackground(":/new/prefix1/C:/Users/Lenovo/Desktop/DaMingPool.jpg");
    QImage fitimgpic=ImgAllbackground.scaled(this->width(),this->height(), Qt::IgnoreAspectRatio);
    PAllbackground.setBrush(QPalette::Window, QBrush(fitimgpic));
    this->setPalette(PAllbackground);
}


void login::on_loginButton_clicked()
{

        db.setHostName("127.0.0.1");//数据库服务器ip
        db.setUserName("root");//数据库用户名
        db.setPassword("123456");//数据库密码
        db.setDatabaseName("fzzh_base");//使用哪个数据库
        //端口号就使用默认的3306吧,因为在本地

        if( !db.open() )//打开数据库,如果返回false表示打开失败
        {
            QMessageBox::warning(this,"无法联网~",db.lastError().text() );//打开失败,显示错误信息
            return;
        }
    //连接成功,判断账号密码是否在数据库当中

        QString sqlstr = "select* from account;"; // 使用 MYSQL 查询语句获取表的数据，写入 tableWidget 中。
        QSqlQuery query;
        query.prepare(sqlstr); // 准备查询语句。
        if (query.exec())
        {
            bool flag=false;
            while (query.next())
            {
                QString id=ui->userId->text();
                QString pwd= ui->passWord->text();

                if(id==query.value(0)&&pwd==query.value(1))
                {
                    QMessageBox::warning(this,"成功","登录成功");
                    if(query.value(2)==1)
                    {
                        StudentUser * student= new StudentUser();
                        student->setSid(id);
                        student->initPage();
                        hide();
                        student->exec();
                        delete student;
                    }
                    if(query.value(2)==2)
                    {
                        teacherUser *teacher= new teacherUser();
                        teacher->setTid(id);
                        teacher->initPage();
                        hide();
                        teacher->exec();
                        return;
                    }
                    if(query.value(2)==3)
                    {
                        administratorUser*administrator = new administratorUser();
                        administrator->setAdministratorId(id);
                        administrator->initPage();
                        hide();
                        administrator->exec();
                        return;
                    }

                    flag=true;
                    break;
                }

            }

            if(flag==false)
            {
                    QMessageBox::warning(this,"错误","用户名或密码错误");
            }

        }
        else
        {
            QMessageBox::warning(this,"错误","网络连接错误");
        }
}

void login::on_cancelButton_clicked()
{
    this->close();
}
