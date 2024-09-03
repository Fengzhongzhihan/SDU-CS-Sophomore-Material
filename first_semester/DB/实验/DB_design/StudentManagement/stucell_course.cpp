#include "stucell_course.h"
#include "ui_stucell_course.h"
#include "sqlop.h"

stucell_course::stucell_course(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stucell_course)
{
    ui->setupUi(this);
    ui->tableView->setModel(&m_model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

stucell_course::~stucell_course()
{
    delete ui;
}

void stucell_course::initPage(QString strCondition)
{
    //查询课程信息并且显示
    auto l =sqlOP::getInstance()->getCourseSetInfos(strCondition);
    m_model.clear();
    m_model.setHorizontalHeaderLabels(QStringList{"课程号","开设学院","课程名","学分","类型","教师","上课地点","上课校区","开始周","结束周","星期几","第几大节"});
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    for(int i = 0;i<l.size();i++)
    {
        QList<QStandardItem*> items;
        for(int j = 0;j<l[i].size();j++)
        {
            items.append(new QStandardItem(l[i][j]));
        }
        m_model.appendRow(items);
    }
}

void stucell_course::on_showCourse_clicked()
{
    QString str=ui->findCourse->text();
    QString strCondition;
    if(str=="")
    {
        strCondition = "";
    }
    else
    {
        strCondition = QString("where course_id = '%1' or course_name REGEXP '%1'").arg(str);
    }
    initPage(strCondition);
}

void stucell_course::on_selectCourse_clicked()
{
    int r = ui->tableView->currentIndex().row();
    if(r<0)
    {
        QMessageBox::warning(this,"错误","请选择你想要选的课!");
    }
    else
    {
        QString id=m_model.item(r,0)->text();
        sqlOP::getInstance()->selectCourse(sid,id);
    }
}

void stucell_course::on_quitCourse_clicked()
{
    int r = ui->tableView->currentIndex().row();
    if(r<0)
    {
        QMessageBox::warning(this,"错误","请选择你想要退的课!");
    }
    else
    {
        QString id=m_model.item(r,0)->text();
        //判断是否已经选择了
        if(sqlOP::getInstance()->isSelected(sid,id))
            sqlOP::getInstance()->quitCourse(sid,id);
        else
        {
            QMessageBox::warning(this,"错误","你还没有选择该课程!");
        }
    }
}

void stucell_course::on_myCourse_clicked()
{
    QString strCondition=QString ("where student_id ='%1'").arg(sid);
    auto l=sqlOP::getInstance()->showSelectedCourse(strCondition);
    m_model.clear();
    m_model.setHorizontalHeaderLabels(QStringList{"课程号","开设学院","课程名","学分","类型","教师","上课地点","上课校区","开始周","结束周","星期几","节次"});
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    for(int i = 0;i<l.size();i++)
    {
        QList<QStandardItem*> items;
        for(int j = 0;j<l[i].size();j++)
        {
            items.append(new QStandardItem(l[i][j]));
        }
        m_model.appendRow(items);
    }
}
