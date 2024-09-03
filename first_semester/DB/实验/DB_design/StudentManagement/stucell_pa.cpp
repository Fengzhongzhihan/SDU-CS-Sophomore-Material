#include "stucell_pa.h"
#include "ui_stucell_pa.h"
#include "sqlop.h"

stucell_pa::stucell_pa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stucell_pa)
{
    ui->setupUi(this);
    ui->tableView->setModel(&m_model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

stucell_pa::~stucell_pa()
{
    delete ui;
}

void stucell_pa::on_showPA_clicked()
{
    QString strCondition=QString ("where s.student_id ='%1'").arg(sid);
    auto l=sqlOP::getInstance()->getPArecords(strCondition);
    m_model.clear();
    m_model.setHorizontalHeaderLabels(QStringList{"学号","姓名","奖项/惩罚","时间"});
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
