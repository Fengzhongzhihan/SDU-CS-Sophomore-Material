#include "teacell_teainfo.h"
#include "ui_teacell_teainfo.h"
#include "sqlop.h"
#include "teacell_updateinfo.h"

teacell_teaInfo::teacell_teaInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::teacell_teaInfo)
{
    ui->setupUi(this);
    ui->tableView->setModel(&m_model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

teacell_teaInfo::~teacell_teaInfo()
{
    delete ui;
}

void teacell_teaInfo::initPage(QString strCondition)
{
    auto l =sqlOP::getInstance()->getTeachersInfos(strCondition);
    m_model.clear();
    m_model.setHorizontalHeaderLabels(QStringList{"教师号","姓名","学院"});
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

void teacell_teaInfo::on_showMyinfo_clicked()
{
    //显示个人信息
    QString strCondition= QString( "where teacher_id ='%1'").arg(tid);
    initPage(strCondition);
}

void teacell_teaInfo::on_updateMyinfo_clicked()
{
   teacell_updateInfo * updateTeaInfo= new teacell_updateInfo ();
   updateTeaInfo->setTid(tid);
    updateTeaInfo->exec();
    on_showMyinfo_clicked();
    delete  updateTeaInfo;
}
