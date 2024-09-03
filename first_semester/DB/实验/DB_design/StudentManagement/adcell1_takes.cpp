#include "adcell1_takes.h"
#include "ui_adcell1_takes.h"
#include"sqlop.h"
#include<QAxObject>
#include<QFileDialog>
#include <QDesktopServices>

adcell1_takes::adcell1_takes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adcell1_takes)
{
    ui->setupUi(this);
    ui->tableView->setModel(&m_model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

adcell1_takes::~adcell1_takes()
{
    delete ui;
}

void adcell1_takes::on_btn_showCourse_clicked()
{
    QString courSetInfo = ui->courseSetInfo->text();
    QString strCondition;
    if(courSetInfo == "")
    {
        strCondition = "";
    }
    else
    {
        strCondition = QString("where courseSet_id REGEXP '%1' or course_name REGEXP '%1'").arg(courSetInfo);
    }
    initPage(strCondition);
}

void adcell1_takes::initPage(QString strCondition)
{
    auto l=sqlOP::getInstance()->getCourseSetInfos(strCondition);
    m_model.clear();
    m_model.setHorizontalHeaderLabels(QStringList{"课程号","开设学院","课程名","学分","类型","教师编号","教师名称","上课地点","上课校区","开始周","结束周","星期几","节次"});
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    for(int i=0;i<l.size();i++)
    {
        QList<QStandardItem*> items;
        for(int j=0;j<l[i].size();j++)
            items.append(new QStandardItem(l[i][j]));
        m_model.appendRow(items);
    }
}

void adcell1_takes::on_pushButton_clicked()
{
    //获取第一列表头名
   QString firstName= m_model.headerData(0,Qt::Horizontal, Qt::DisplayRole).toString();
   if(firstName!="学号")
   {
       QMessageBox::warning(NULL,"错误","请显示出界面再进行打印!");
       return;
   }
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save as..."),
                                                         QString(), tr("EXCEL files (*.xls *.xlsx)"));
         if (fileName!="")
         {
             QAxObject *excel = new QAxObject;
             if (excel->setControl("Excel.Application")) //连接Excel控件
             {
                 excel->dynamicCall("SetVisible (bool Visible)","false");//不显示窗体
                 excel->setProperty("DisplayAlerts", false);//不显示任何警告信息。如果为true那么在关闭是会出现类似“文件已修改，是否保存”的提示
                 QAxObject *workbooks = excel->querySubObject("WorkBooks");//获取工作簿集合
                 workbooks->dynamicCall("Add");//新建一个工作簿
                 QAxObject *workbook = excel->querySubObject("ActiveWorkBook");//获取当前工作簿
                 QAxObject *worksheet = workbook->querySubObject("Worksheets(int)", 1);

                 int i,j;
                 //获取数据的列数
                 int colcount=m_model.columnCount();
                  //获取数据的行数
                 int rowcount=m_model.rowCount();

                 QAxObject *cell,*col;
                 //标题行
                 cell=worksheet->querySubObject("Cells(int,int)", 1, 1);
                 cell->dynamicCall("SetValue(const QString&)", "学生选课记录");
                 cell->querySubObject("Font")->setProperty("Size", 18);
                 //调整行高
                 worksheet->querySubObject("Range(const QString&)", "1:1")->setProperty("RowHeight", 30);
                 //合并标题行
                 QString cellTitle;
                 cellTitle.append("A1:");
                 cellTitle.append(QChar(colcount - 1 + 'A'));
                 cellTitle.append(QString::number(1));
                 QAxObject *range = worksheet->querySubObject("Range(const QString&)", cellTitle);
                 range->setProperty("WrapText", true);
                 range->setProperty("MergeCells", true);
                 range->setProperty("HorizontalAlignment", -4108);//xlCenter
                 range->setProperty("VerticalAlignment", -4108);//xlCenter
                 //列标题
                 for(i=0;i<colcount;i++)
                 {
                     QString columnName;
                     columnName.append(QChar(i  + 'A'));
                     columnName.append(":");
                     columnName.append(QChar(i + 'A'));
                     col = worksheet->querySubObject("Columns(const QString&)", columnName);
                     col->setProperty("ColumnWidth", ui->tableView->columnWidth(i)/6);
                     cell=worksheet->querySubObject("Cells(int,int)", 2, i+1);
                     //QTableWidget 获取表格头部文字信息
                     columnName=m_model.headerData(i,Qt::Horizontal,Qt::DisplayRole).toString();;
                     //QTableView 获取表格头部文字信息
                     // columnName=ui->tableView_right->model()->headerData(i,Qt::Horizontal,Qt::DisplayRole).toString();
                     cell->dynamicCall("SetValue(const QString&)", columnName);
                     cell->querySubObject("Font")->setProperty("Bold", true);
                     cell->querySubObject("Interior")->setProperty("Color",QColor(191, 191, 191));
                     cell->setProperty("HorizontalAlignment", -4108);//xlCenter
                     cell->setProperty("VerticalAlignment", -4108);//xlCenter
                 }

                //数据区

                //QTableWidget 获取表格数据部分
                 for(i=0;i<rowcount;i++){
                     for (j=0;j<colcount;j++)
                     {
                         worksheet->querySubObject("Cells(int,int)", i+3, j+1)->dynamicCall("SetValue(const QString&)",
                        m_model.item(i,j)?m_model.item(i,j)->text():"");
                     }
                 }


    //            QTableView 获取表格数据部分
    //              for(i=0;i<rowcount;i++) //行数
    //                 {
    //                     for (j=0;j<colcount;j++)   //列数
    //                     {
    //                         QModelIndex index = ui->tableView_right->model()->index(i, j);
    //                         QString strdata=ui->tableView_right->model()->data(index).toString();
    //                         worksheet->querySubObject("Cells(int,int)", i+3, j+1)->dynamicCall("SetValue(const QString&)", strdata);
    //                     }
    //                 }


                 //画框线
                 QString lrange;
                 lrange.append("A2:");
                 lrange.append(colcount - 1 + 'A');
                 lrange.append(QString::number(rowcount + 2));
                 range = worksheet->querySubObject("Range(const QString&)", lrange);
                 range->querySubObject("Borders")->setProperty("LineStyle", QString::number(1));
                 range->querySubObject("Borders")->setProperty("Color", QColor(0, 0, 0));
                 //调整数据区行高
                 QString rowsName;
                 rowsName.append("2:");
                 rowsName.append(QString::number(rowcount + 2));
                 range = worksheet->querySubObject("Range(const QString&)", rowsName);
                 range->setProperty("RowHeight", 20);
                 workbook->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(fileName));//保存至fileName
                 workbook->dynamicCall("Close()");//关闭工作簿
                 excel->dynamicCall("Quit()");//关闭excel
                 delete excel;
                 excel=NULL;
                 if (QMessageBox::question(NULL,"完成","文件已经导出，是否现在打开？",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
                 {
                     QDesktopServices::openUrl(QUrl("file:///" + QDir::toNativeSeparators(fileName)));
                 }
             }
             else
             {
                 QMessageBox::warning(NULL,"错误","未能创建 Excel 对象，请安装 Microsoft Excel。",QMessageBox::Apply);
             }
         }
}

void adcell1_takes::on_btn_myCourse_clicked()
{
    QString sid = ui->sid->text();
    QString courSetInfo = ui->courseSetInfo->text();
    QString strCondition;
    if(sid == "" && courSetInfo == "")
    {
        strCondition = "";
    }
    else if(sid != "" && courSetInfo == "")
    {
        strCondition = QString("where student_id = '%1'").arg(sid);
    }
    else if(sid == "" && courSetInfo != "")
    {
        strCondition = QString("where courseSet_id REGEXP '%1' or course_name REGEXP '%1'").arg(courSetInfo);
    }
    else if(sid != "" && courSetInfo != "")
    {
        strCondition = QString("where (student_id = '%1') and (courseSet_id REGEXP '%2' or course_name REGEXP '%2')").arg(sid,courSetInfo);
    }
    auto l=sqlOP::getInstance()->getTakesInfos(strCondition);
    m_model.clear();
    m_model.setHorizontalHeaderLabels(QStringList{"学号","课程号","开设学院","课程名","学分","类型","教师编号","教师名称","上课地点","上课校区","开始周","结束周","星期几","节次"});
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    for(int i=0;i<l.size();i++)
    {
        QList<QStandardItem*> items;
        for(int j=0;j<l[i].size();j++)
            items.append(new QStandardItem(l[i][j]));
        m_model.appendRow(items);
    }
}

void adcell1_takes::on_btn_selectCourse_clicked()
{
    int r = ui->tableView->currentIndex().row();
    QString sid = ui->sid->text();
    if(r<0)
    {
        QMessageBox::warning(this,"错误","请选择你想要选的课!");
    }
    else if(!sqlOP::getInstance()->isStudentExist(sid))
    {
        QMessageBox::warning(this,"错误","不存在以学号为学号的学生");
    }
    else
    {
        QString id=m_model.item(r,0)->text();
        sqlOP::getInstance()->selectCourse(sid,id);
    }
    on_btn_showCourse_clicked();
}

void adcell1_takes::on_btn_quitCourse_clicked()
{
    int r = ui->tableView->currentIndex().row();
    QString sid = ui->sid->text();
    if(r<0)
    {
        QMessageBox::warning(this,"错误","请选择你想要退的课!");
    }
    else if(!sqlOP::getInstance()->isStudentExist(sid))
    {
        QMessageBox::warning(this,"错误","不存在以学号为学号的学生");
    }
    else
    {
        //获取第一列表头名
       QString firstName= m_model.headerData(0,Qt::Horizontal, Qt::DisplayRole).toString();
       if(firstName!="学号")
       {
           QMessageBox::warning(NULL,"错误","请显示出选课记录界面再进行退课!");
           return;
       }
        QString id=m_model.item(r,1)->text();
        //判断是否已经选择了
        if(sqlOP::getInstance()->isSelected(sid,id))
            sqlOP::getInstance()->quitCourse(sid,id);
        else
        {
            QMessageBox::warning(this,"错误","你还没有选择该课程!");
        }
    }
    on_btn_myCourse_clicked();
}
