#include "stucell_info.h"
#include "ui_stucell_info.h"
#include "stucell_updateinfo.h"

stucell_info::stucell_info(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stucell_info)
{
    ui->setupUi(this);
    ui->tableView->setModel(&m_model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}

stucell_info::~stucell_info()
{
    delete ui;
}

void stucell_info::initPage(QString strCondition)
{
    //查询学生信息并且显示
    auto l =sqlOP::getInstance()->getStudentInfos(strCondition);
    m_model.clear();
    m_model.setHorizontalHeaderLabels(QStringList{"学号","姓名","年龄","年级","班级","身份证号","性别","学院","专业"});
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


void stucell_info::on_SelectInfo_clicked()
{
    //显示个人信息
    QString strCondition= QString( "where student_id ='%1'").arg(sid);
    initPage(strCondition);
}

void stucell_info::on_UpdateInfo_clicked()
{
    stucell_updateInfo *stuUpdateInfo =new stucell_updateInfo(this);
   stuUpdateInfo->setSid(sid);

   stuUpdateInfo->exec();
   delete  stuUpdateInfo;
   on_SelectInfo_clicked();
}
