#include "teacell_course.h"
#include "ui_teacell_course.h"
#include "sqlop.h"
teacell_course::teacell_course(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::teacell_course)
{
    ui->setupUi(this);
    ui->tableView->setModel(&m_model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

teacell_course::~teacell_course()
{
    delete ui;
}

void teacell_course::initPage(QString strCondition)
{
    //查询课程信息并且显示
    auto l =sqlOP::getInstance()->getCourseSetInfos(strCondition);
    m_model.clear();
    m_model.setHorizontalHeaderLabels(QStringList{"课程号","开设学院","课程名","学分","类型","教师编号","教师名称","上课地点","上课校区","开始周","结束周","星期几","节次"});
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

void teacell_course::on_findCourse_clicked()
{
    QString str=ui->courseName->text();
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

void teacell_course::on_findMyCourse_clicked()
{
    QString strCondition=QString("where t.teacher_id ='%1'").arg(tid);
    initPage(strCondition);
}

