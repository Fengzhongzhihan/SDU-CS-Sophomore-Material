#include "sqlop.h"
#include "qmessagebox.h"

sqlOP::sqlOP()
{

}
sqlOP* sqlOP::instance =nullptr;

void sqlOP::init()
{
    db = QSqlDatabase::addDatabase("QMYSQL");

    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");//数据库服务器ip
    db.setUserName("root");//数据库用户名
    db.setPassword("123456");//数据库密码
    db.setDatabaseName("fzzh_base");//使用哪个数据库
    //端口号就使用默认的3306吧,因为在本地

    if( !db.open() )//打开数据库,如果返回false表示打开失败
    {
        QMessageBox::information(NULL,"错误","连接失败");//打开失败,显示错误信息
        return;
    }
    else
    {
        QMessageBox::warning(NULL,"恭喜~~~","Mysql连接成功！");
    }
}

QVector<QStringList> sqlOP::getStudentInfos(QString strCondition)
{
    QSqlQuery q(db);
    QString strSql =
            QString("select student_id, student_name, age,grade,classes ,"
                    "identity_id, sex ,college_name,major_name  from student "
                    "natural join collegemajor natural join college %1").arg(strCondition);
    QVector<QStringList> vec;
    bool ret = q.exec(strSql);
    if(!ret)
    {
       qDebug()<< q.lastError().text();
    }
    else
    {
        //一共多少列
        int iCols = q.record().count();
        //每次都读取一行数据
        QStringList l;
        while(q.next())
        {
            l.clear();
            for(int i =0;i<iCols;i++)
            {
                l<<q.value(i).toString();
            }
            vec.push_back(l);
        }
    }

    return vec;
}

QVector<QStringList> sqlOP::getTeacherInfos(QString strCondition)
{
    QSqlQuery q(db);
    QString strSql =
            QString("select teacher_id,teacher_name,college_name from teacher t join college c on t.college_id = c.college_id %1").arg(strCondition);
    QVector<QStringList> vec;
    bool ret = q.exec(strSql);
    if(!ret)
    {
       qDebug()<< q.lastError().text();
    }
    else
    {
        //一共多少列
        int iCols = q.record().count();
        //每次都读取一行数据
        QStringList l;
        while(q.next())
        {
            l.clear();
            for(int i =0;i<iCols;i++)
            {
                l<<q.value(i).toString();
            }
            vec.push_back(l);
        }
    }

    return vec;
}

QVector<QStringList> sqlOP::getCourseSetInfos(QString strCondition)
{
    QSqlQuery q(db);
    QString strSql =
            QString("select  courseSet_id,college_name,  course_name  , credit,classification, t.teacher_id,teacher_name, address_name, campus_name ,startWeek, endWeek, "
                    "DayOfWeek, section from (courseSet cs natural join college natural join course natural join time) join teacher t on t.teacher_id =cs.teacher_id %1").arg(strCondition);
    QVector<QStringList> vec;
    bool ret = q.exec(strSql);
    if(!ret)
    {
       qDebug()<< q.lastError().text();
    }
    else
    {
        //一共多少列
        int iCols = q.record().count();
        //每次都读取一行数据
        QStringList l;
        while(q.next())
        {
            l.clear();
            for(int i =0;i<iCols;i++)
            {
                l<<q.value(i).toString();
            }
            vec.push_back(l);
        }
    }
    return vec;
}

QVector<QStringList> sqlOP::getCourseInfos(QString strCondition)
{
    QSqlQuery q(db);
    QString strSql =
            QString("select * from course %1").arg(strCondition);
    QVector<QStringList> vec;
    bool ret = q.exec(strSql);
    if(!ret)
    {
       qDebug()<< q.lastError().text();
    }
    else
    {
        //一共多少列
        int iCols = q.record().count();
        //每次都读取一行数据
        QStringList l;
        while(q.next())
        {
            l.clear();
            for(int i =0;i<iCols;i++)
            {
                l<<q.value(i).toString();
            }
            vec.push_back(l);
        }
    }
    return vec;
}

QVector<QStringList> sqlOP::getCollegeInfos(QString strCondition)
{
    QSqlQuery q(db);
    QString strSql =
            QString("select college_id,college_name,major_id,major_name from college natural join collegemajor %1").arg(strCondition);
    QString strSql2 =
            QString("select college_id,college_name from(select college_id,college_name from college where college_id not in (select college_id from collegemajor)) as temp %1").arg(strCondition);
    QVector<QStringList> vec;
    bool ret = q.exec(strSql);
    if(!ret)
    {
       qDebug()<< q.lastError().text();
    }
    else
    {
        //一共多少列
        int iCols = q.record().count();
        //每次都读取一行数据
        QStringList l;
        while(q.next())
        {
            l.clear();
            for(int i =0;i<iCols;i++)
            {
                l<<q.value(i).toString();
            }
            vec.push_back(l);
        }
    }
    QVector<QStringList> vec2;
    ret = q.exec(strSql2);
    if(!ret)
    {
       qDebug()<< q.lastError().text();
    }
    else
    {
        //一共多少列
        int iCols = q.record().count();
        //每次都读取一行数据
        QStringList l;
        while(q.next())
        {
            l.clear();
            for(int i =0;i<iCols;i++)
            {
                l<<q.value(i).toString();
            }
            vec.push_back(l);
        }
    }
    return vec;
}

QVector<QStringList> sqlOP::getAdministratorInfos(QString strCondition)
{
    QSqlQuery q(db);
    QString strSql =
            QString("select user_id,pass_word from account %1").arg(strCondition);
    QVector<QStringList> vec;
    bool ret = q.exec(strSql);
    if(!ret)
    {
       qDebug()<< q.lastError().text();
    }
    else
    {
        //一共多少列
        int iCols = q.record().count();
        //每次都读取一行数据
        QStringList l;
        while(q.next())
        {
            l.clear();
            for(int i =0;i<iCols;i++)
            {
                l<<q.value(i).toString();
            }
            vec.push_back(l);
        }
    }
    return vec;
}

QVector<QStringList> sqlOP::getTimeInfos(QString strCondition)
{
    QSqlQuery q(db);
    QString strSql =
            QString("select time_id,startWeek,endWeek,DayOfWeek,section from time %1").arg(strCondition);
    QVector<QStringList> vec;
    bool ret = q.exec(strSql);
    if(!ret)
    {
       qDebug()<< q.lastError().text();
    }
    else
    {
        //一共多少列
        int iCols = q.record().count();
        //每次都读取一行数据
        QStringList l;
        while(q.next())
        {
            l.clear();
            for(int i =0;i<iCols;i++)
            {
                l<<q.value(i).toString();
            }
            vec.push_back(l);
        }
    }
    return vec;
}

QVector<QStringList> sqlOP::getTakesInfos(QString strCondition)
{
    QSqlQuery q(db);
    QString strSql =
            QString("select  student_id,courseSet_id,college_name,  course_name  , credit,classification,t.teacher_id, teacher_name, address_name, campus_name ,startWeek, endWeek, "
                    "DayOfWeek, section from (courseSet cs natural join college natural join course natural join time) "
                    "join teacher t on t.teacher_id =cs.teacher_id natural join takes %1").arg(strCondition);
    QVector<QStringList> vec;
    bool ret = q.exec(strSql);
    if(!ret)
    {
       qDebug()<< q.lastError().text();
    }
    else
    {
        //一共多少列
        int iCols = q.record().count();
        //每次都读取一行数据
        QStringList l;
        while(q.next())
        {
            l.clear();
            for(int i =0;i<iCols;i++)
            {
                l<<q.value(i).toString();
            }
            vec.push_back(l);
        }
    }
    return vec;
}

void sqlOP::addStudentInfos(QStringList stuInfo)
{
    QSqlQuery q(db);
    QString strSql = QString("insert into student values ('%8','%1','%2','%3','%4','%5','%6',"
                             "(select major_id from collegemajor where major_name ='%7'))"
                             ).arg(stuInfo[0],stuInfo[1],stuInfo[2],stuInfo[3],stuInfo[4],stuInfo[5],stuInfo[6],stuInfo[7]);
    QString strSql2 = QString("insert into account values ('%1',substr('%2',length('%2')-5,6),1)").arg(stuInfo[7],stuInfo[4]);
    if(q.exec(strSql)&&q.exec(strSql2))
    {
        QMessageBox::information(NULL,"成功","增加学生信息成功!");
    }
    else
    {
        QMessageBox::warning(NULL,"失败","创建失败!");
        qDebug()<<q.lastError().text();
    }
}

void sqlOP::addTeacherInfos(QStringList teaInfo)
{
    QSqlQuery q(db);
    QString strSql = QString("insert into Teacher values ('%1','%2',(select college_id from college where college_name = '%3'))"
                             ).arg(teaInfo[0],teaInfo[1],teaInfo[2]);
    QString strSql2 = QString("insert into account values ('%1',substr('%1',length('%1'),1),2)").arg(teaInfo[0]);
    if(q.exec(strSql)&&q.exec(strSql2))
    {
        QMessageBox::information(NULL,"成功","增加老师信息成功!");
    }
    else
    {
        QMessageBox::warning(NULL,"失败","创建失败!");
        qDebug()<<q.lastError().text();
    }
}

void sqlOP::addCourseInfos(QStringList courInfo)
{
    QSqlQuery q(db);
    QString strSql = QString("insert into course values ('%1','%2','%3')").arg(courInfo[0],courInfo[1],courInfo[2]);
    if(q.exec(strSql))
    {
        QMessageBox::information(NULL,"成功","增加课程信息成功!");
    }
    else
    {
        QMessageBox::warning(NULL,"失败","创建失败!");
        qDebug()<<q.lastError().text();
    }
}

void sqlOP::addCollegeInfos(QStringList collInfo)
{
    QSqlQuery q(db);
    QString strSql = QString("insert into college values ('%1','%2')").arg(collInfo[0],collInfo[1]);
    if(q.exec(strSql))
    {
        QMessageBox::information(NULL,"成功","增加学院信息成功!");
    }
    else
    {
        QMessageBox::warning(NULL,"失败","创建失败!");
        qDebug()<<q.lastError().text();
    }
}

void sqlOP::addCollegeMajorInfos(QStringList cmInfo)
{
    QSqlQuery q(db);
    QString strSql = QString("insert into collegemajor values ('%1','%2','%3')").arg(cmInfo[1],cmInfo[0],cmInfo[2]);
    if(q.exec(strSql))
    {
        QMessageBox::information(NULL,"成功","增加专业信息成功!");
    }
    else
    {
        QMessageBox::warning(NULL,"失败","创建失败!");
        qDebug()<<q.lastError().text();
    }
}

void sqlOP::addAdministratorInfos(QStringList AdInfo)
{
    QSqlQuery q(db);
    QString strSql = QString("insert into account values ('%1','%2',3)").arg(AdInfo[0],AdInfo[1]);
    if(q.exec(strSql))
    {
        QMessageBox::information(NULL,"成功","增加管理员信息成功!");
    }
    else
    {
        QMessageBox::warning(NULL,"失败","创建失败!");
        qDebug()<<q.lastError().text();
    }
}

void sqlOP::addTimeInfos(QStringList timeInfo)
{
    QSqlQuery q(db);
    QString strSql = QString("insert into time values ('%1','%2','%3','%4','%5')").arg(timeInfo[0],timeInfo[1],timeInfo[2],timeInfo[3],timeInfo[4]);
    if(q.exec(strSql))
    {
        QMessageBox::information(NULL,"成功","增加时间编号信息成功!");
    }
    else
    {
        QMessageBox::warning(NULL,"失败","创建失败!");
        qDebug()<<q.lastError().text();
    }
}

void sqlOP::addCourseSetInfos(QStringList courSetInfo)
{
    QSqlQuery q(db);
    QString strSql = QString("insert into courseset values ('%1','%2','%3','%4','%5','%6','%7','%8')").arg(courSetInfo[0],courSetInfo[1],courSetInfo[2],courSetInfo[3],courSetInfo[4],courSetInfo[5],courSetInfo[6],courSetInfo[7]);
    if(q.exec(strSql))
    {
        QMessageBox::information(NULL,"成功","增加开设课程信息成功!");
    }
    else
    {
        QMessageBox::warning(NULL,"失败","创建失败!");
        qDebug()<<q.lastError().text();
    }
}

void sqlOP::deleteStudentInfos(QString sid)
{
    QSqlQuery q(db);
    QString strSql = QString("delete from student where student_id = '%1'").arg(sid);
    QString strSql2 = QString("delete from account where user_id = '%1'").arg(sid);
    if(q.exec(strSql)&&q.exec(strSql2))
    {
        QMessageBox::information(NULL,"成功","删除学生成功");
    }
    else
    {
        qDebug()<<q.lastError().text();
        QMessageBox::warning(NULL,"错误","删除失败，请先让该学生进行退课并删除该学生的奖惩信息");
    }
}

void sqlOP::deleteTeacherInfos(QString tid)
{
    QSqlQuery q(db);
    QString strSql = QString("delete from teacher where teacher_id = '%1'").arg(tid);
    QString strSql2 = QString("delete from account where user_id = '%1'").arg(tid);
    if(q.exec(strSql)&&q.exec(strSql2))
    {
        QMessageBox::information(NULL,"成功","删除老师成功");
    }
    else
    {
        QMessageBox::warning(NULL,"错误","删除失败，请先让停止该老师的所有已开设课程");
    }
}

void sqlOP::deleteCourseInfos(QString cid)
{
    QSqlQuery q(db);
    QString strSql = QString("delete from course where course_id = '%1'").arg(cid);
    if(q.exec(strSql))
    {
        QMessageBox::information(NULL,"成功","删除课程成功");
    }
    else
    {
        QMessageBox::warning(NULL,"错误","删除失败，该课程已开设，请先删除相应的开设课程");
    }
}

void sqlOP::deleteCollegeInfos(QString college_id)
{
    QSqlQuery q(db);
    QString strSql = QString("delete from college where college_id = '%1'").arg(college_id);
    if(q.exec(strSql))
    {
        QMessageBox::information(NULL,"成功","删除学院成功");
    }
    else
    {
        QMessageBox::warning(NULL,"错误","已删除该学院的所有专业，请删除该学院的所有专业、已开设课程、老师");
    }
}

void sqlOP::deleteMajorInfos(QString major_id)
{
    QSqlQuery q(db);
    QString strSql = QString("delete from collegemajor where major_id = '%1'").arg(major_id);
    if(q.exec(strSql))
    {
        QMessageBox::information(NULL,"成功","删除专业成功");
    }
    else
    {
        QMessageBox::warning(NULL,"错误","删除失败，请先删除该专业的所有学生");
    }
}

void sqlOP::deleteMyAdministratorInfos(QString user_id)
{
    QSqlQuery q(db);
    QString strSql = QString("delete from account where user_id = '%1'").arg(user_id);
    if(q.exec(strSql))
    {
        QMessageBox::information(NULL,"成功","删除账号成功，登出后无法再次使用此账号登录");
    }
    else
    {
        QMessageBox::warning(NULL,"错误","删除失败");
    }
}

void sqlOP::deleteTimeInfos(QString time_id)
{
    QSqlQuery q(db);
    QString strSql = QString("delete from time where time_id = '%1'").arg(time_id);
    if(q.exec(strSql))
    {
        QMessageBox::information(NULL,"成功","删除时间编号成功");
    }
    else
    {
        QMessageBox::warning(NULL,"错误","删除失败，请先删除使用此时间编号的已开设课程");
    }
}

void sqlOP::deleteCourseSetInfos(QString cs_id)
{
    QSqlQuery q(db);
    QString strSql = QString("delete from courseset where courseSet_id = '%1'").arg(cs_id);
    if(q.exec(strSql))
    {
        QMessageBox::information(NULL,"成功","已取消该课程的开设");
    }
    else
    {
        QMessageBox::warning(NULL,"错误","删除失败，请先让选择该课程的同学退课，或你来给他们退课");
    }
}

void sqlOP::updateStudentInfos(QStringList stuInfo)
{
    QSqlQuery q(db);
    QString strSql = QString("update student set student_name = '%1',age='%2' ,grade='%3', classes ='%4', identity_id='%5', sex='%6', "
                             "major_id= (select major_id from collegemajor where major_name ='%7' )"
                             "where student_id ='%8' ").arg(stuInfo[0],stuInfo[1],stuInfo[2],stuInfo[3],stuInfo[4],stuInfo[5],stuInfo[6],stuInfo[7]);

    if(q.exec(strSql))
    {
        QMessageBox::information(NULL,"成功","修改学生信息成功!");
    }
    else
    {
        qDebug()<<q.lastError().text();
        QMessageBox::warning(NULL,"失败","你的专业名输入错误!没有这个专业!");
    }
}



void sqlOP::selectCourse(QString sid, QString courseSet_id)
{
    QSqlQuery q(db);
    QString strSql=
            QString ("insert into takes values ('%1','%2','0'); ").arg(sid).arg(courseSet_id);
    if(q.exec(strSql))
    {
        QMessageBox::information(NULL,"成功","选课成功");
    }
    else
    {
       QMessageBox::warning(NULL,"错误","该课程已经选过了!");
    }
}

void sqlOP::quitCourse(QString sid, QString courseSet_id)
{
    QSqlQuery q(db);
    QString strSql=
            QString ("delete from takes where student_id='%1' and courseSet_id ='%2' ").arg(sid).arg(courseSet_id);
    if(q.exec(strSql))
    {
        QMessageBox::information(NULL,"成功","退课成功");
    }
    else
    {
       qDebug()<<q.lastError().text();
    }
}

bool sqlOP::isSelected(QString sid, QString courseSet_id)
{
    QSqlQuery q(db);
    QString strSql=
            QString ("select * from takes where student_id='%1' and courseSet_id= '%2' ").arg(sid).arg(courseSet_id);
    if(q.exec(strSql))
    {
        if(q.size())
           return true;
        else
            return false;
    }
    else
    {
        qDebug()<<q.lastError().text();
        return false;
    }
}

QVector<QStringList> sqlOP::showSelectedCourse(QString strCondition)
{
    QSqlQuery q(db);
    QString strSql =
            QString("select  courseSet_id,college_name,  course_name  , credit,classification, teacher_name, address_name, campus_name ,startWeek, endWeek, "
                    "DayOfWeek, section from (courseSet cs natural join college natural join course natural join time) "
                    "join teacher t on t.teacher_id =cs.teacher_id natural join takes %1").arg(strCondition);
    QVector<QStringList> vec;
    bool ret = q.exec(strSql);
    if(!ret)
    {
       qDebug()<< q.lastError().text();
    }
    else
    {
        //一共多少列
        int iCols = q.record().count();
        //每次都读取一行数据
        QStringList l;
        while(q.next())
        {
            l.clear();
            for(int i =0;i<iCols;i++)
            {
                l<<q.value(i).toString();
            }
            vec.push_back(l);
        }
    }
    return vec;
}

QVector<QStringList> sqlOP::getStuScore(QString strCondition)
{
    QSqlQuery q(db);
    QString strSql =
            QString("select courseSet_id, course_name, student_id, student_name, score "
                    "from student natural join takes natural join courseSet natural join course %1").arg(strCondition);

    QVector <QStringList> vec;
    bool ret = q.exec(strSql);
    if(!ret)
    {
       qDebug()<< q.lastError().text();
    }
    else
    {
        //一共多少列
        int iCols = q.record().count();
        //每次都读取一行数据
        QStringList l;
        while(q.next())
        {
            l.clear();
            for(int i =0;i<iCols;i++)
            {
                l<<q.value(i).toString();
            }
            vec.push_back(l);
        }
    }
    return vec;
}

//重修逻辑
void sqlOP::reStudyCourse(QString sid, QString courseSet_id)
{
    //退课即可
    QSqlQuery q(db);
    QString strSql=
            QString ("delete from takes where student_id='%1' and courseSet_id ='%2' ").arg(sid).arg(courseSet_id);
    if(q.exec(strSql))
    {
        QMessageBox::information(NULL,"成功","重修成功,现在你可以选择对应的课了");
    }
    else
    {
       qDebug()<<q.lastError().text();
    }
}

void sqlOP::reExamCourse(QString sid, QString courseSet_id)
{
    //把成绩置为0即可
    QSqlQuery q(db);
    QString strSql=
            QString ("update takes set score =0 where student_id='%1' and courseSet_id ='%2' ").arg(sid).arg(courseSet_id);
    if(q.exec(strSql))
    {
        QMessageBox::information(NULL,"成功","补考成功,注意关注考试通知哦!");
    }
    else
    {
       qDebug()<<q.lastError().text();
    }
}

QVector<QStringList> sqlOP::getPArecords(QString strCondition)
{
    QSqlQuery q(db);
    QString strSql =
            QString("select s.student_id,student_name,PAsort,time from student s join parecords p on s.student_id = p.student_id %1 ").arg(strCondition);
    QVector<QStringList> vec;
    bool ret = q.exec(strSql);
    if(!ret)
    {
       qDebug()<< q.lastError().text();
    }
    else
    {
        //一共多少列
        int iCols = q.record().count();
        //每次都读取一行数据
        QStringList l;
        while(q.next())
        {
            l.clear();
            for(int i =0;i<iCols;i++)
            {
                l<<q.value(i).toString();
            }
            vec.push_back(l);
        }
    }
    return vec;
}

void sqlOP::stuPaRegister(QStringList paInfo)
{
    QSqlQuery q(db);
    QString strSql = QString("insert into parecords values ('%1','%2','%3')").arg(paInfo[0],paInfo[1],paInfo[2]);
    if(!q.exec(strSql))
    {
        QMessageBox::information(NULL,"失败","登记奖惩失败");
        qDebug()<<q.lastError().text();
    }
    else
    {
        QMessageBox::information(NULL,"成功","登记奖惩成功");
    }
}

void sqlOP::deleteStuPaInfos(QString sid, QString paInfo)
{
    QSqlQuery q(db);
    QString strSql = QString("delete from parecords where student_id = '%1' and PAsort = '%2'").arg(sid,paInfo);
    if(q.exec(strSql))
    {
        QMessageBox::information(NULL,"成功","删除奖惩记录成功");
    }
    else
    {
        QMessageBox::warning(NULL,"错误","删除失败，sql没有执行成功，出bug了~");
    }
}

QVector<QStringList> sqlOP::getTeachersInfos(QString strCondition)
{
    QSqlQuery q(db);
    QString strSql =
            QString("select teacher_id, teacher_name ,college_name from teacher natural join college %1").arg(strCondition);
    QVector<QStringList> vec;
    bool ret = q.exec(strSql);
    if(!ret)
    {
       qDebug()<< q.lastError().text();
    }
    else
    {
        //一共多少列
        int iCols = q.record().count();
        //每次都读取一行数据
        QStringList l;
        while(q.next())
        {
            l.clear();
            for(int i =0;i<iCols;i++)
            {
                l<<q.value(i).toString();
            }
            vec.push_back(l);
        }
    }

    return vec;
}

void sqlOP::updateTeacherInfos(QStringList stuInfo)
{
    QSqlQuery q(db);
    QString strSql = QString("update teacher set teacher_name = '%1', "
                             "college_id= (select college_id from college where college_name ='%2' )"
                             "where teacher_id ='%3' ").arg(stuInfo[0],stuInfo[1],stuInfo[2]);

    if(q.exec(strSql))
    {
        QMessageBox::information(NULL,"成功","修改老师信息成功!");
    }
    else
    {
        qDebug()<<q.lastError().text();
        QMessageBox::information(NULL,"失败","输入学院名称错误!没有这个学院!");
    }
}

void sqlOP::updateCourseInfos(QStringList courInfo)
{
    QSqlQuery q(db);
    QString strSql = QString("update course set course_name = '%1',credit = '%2'"
                             "where course_id = '%3' ").arg(courInfo[1],courInfo[2],courInfo[0]);
    if(q.exec(strSql))
    {
        QMessageBox::information(NULL,"成功","修改课程信息成功!");
    }
    else
    {
        qDebug()<<q.lastError().text();
    }
}

void sqlOP::updateCourseSetInfos(QStringList csInfo)
{
    QSqlQuery q(db);
    QString strSql = QString("update courseset set teacher_id = '%1',course_id = '%2',address_name = '%3',"
                             "time_id = '%4',college_id = '%5',campus_name = '%6',classification = '%7'"
                             " where courseSet_id = '%8'").arg(csInfo[1],csInfo[2],csInfo[3],csInfo[4],csInfo[5],csInfo[6],csInfo[7],csInfo[0]);
    if(q.exec(strSql))
    {
        QMessageBox::information(NULL,"成功","修改课程信息成功!");
    }
    else
    {
        QMessageBox::warning(NULL,"失败","修改课程信息失败!");
        qDebug()<<q.lastError().text();
    }
}

QVector<QStringList> sqlOP::selectMyStudents(QString strCondition)
{
    QSqlQuery q(db);
    QString strSql =
            QString("select student_id, student_name, age,grade,classes ,identity_id, sex ,college_name,major_name  "
                    "from student natural join collegemajor natural join college natural join takes %1").arg(strCondition);
    QVector<QStringList> vec;
    bool ret = q.exec(strSql);
    if(!ret)
    {
       qDebug()<< q.lastError().text();
    }
    else
    {
        //一共多少列
        int iCols = q.record().count();
        //每次都读取一行数据
        QStringList l;
        while(q.next())
        {
            l.clear();
            for(int i =0;i<iCols;i++)
            {
                l<<q.value(i).toString();
            }
            vec.push_back(l);
        }
    }

    return vec;
}

bool sqlOP::isMyClass(QString tid, QString courseSet_id)
{

    QSqlQuery q(db);
    QString strSql =
            QString("select * from  courseSet where teacher_id='%1' and courseSet_id='%2';").arg(tid).arg(courseSet_id);
    bool ret = q.exec(strSql);
    if(!ret)
    {
       qDebug()<< q.lastError().text();
       return false;
    }
    else
    {
       if(q.size())
           return true;
       else
           return false;
    }
}

bool sqlOP::setScore(QString sid, QString courseSet_id, QString score)
{
    QSqlQuery q(db);
    QString strSql =
            QString("update takes  set score =%1 where student_id='%2' and courseSet_id='%3'").arg(score).arg(sid).arg(courseSet_id);
    bool ret = q.exec(strSql);
    if(!ret)
    {
       qDebug()<< q.lastError().text();
       return false;
    }
    else
    {
        return true;
    }

}

QVector<QStringList> sqlOP::countScore(QString courseSet_id)
{
    QSqlQuery q(db);
    QString strSql =
            QString("select avg_score, max_score, min_score ,count_ok,count_sum, (count_ok/count_sum)as passRate from (select avg(score) as avg_score,"
                    " max(score) as max_score, min(score) as min_score, count(*) as count_sum from takes where courseSet_id='%1' and score>0 )"
                    " as a natural join (select count(*) as count_ok from takes where score>=60)as b ").arg(courseSet_id);
    bool ret = q.exec(strSql);
    QVector<QStringList> vec;

    QStringList l;

    if(!ret)
    {
       qDebug()<< q.lastError().text();
    }
    else
    {
        //一共多少列
        int iCols = q.record().count();
        //每次都读取一行数据
        QStringList l;
        while(q.next())
        {
            l.clear();
            for(int i =0;i<iCols;i++)
            {
                l<<q.value(i).toString();
            }
            vec.push_back(l);
        }
    }
    return vec;
}

bool sqlOP::isStudentExist(QString sid)
{
    QSqlQuery q(db);
    QString strSql =
            QString("select * from student where student_id = '%1'").arg(sid);
    bool ret = q.exec(strSql);
    if(ret)
    {
        if(q.size())
            return true;
        else
            return false;
    }
    else
    {
        qDebug()<< q.lastError().text();
        return false;
    }
}

bool sqlOP::isIdentityExist(QString identity_id)
{
    QSqlQuery q(db);
    QString strSql =
            QString("select * from student where identity_id = '%1'").arg(identity_id);
    bool ret = q.exec(strSql);
    if(ret)
    {
        if(q.size())
            return true;
        else
            return false;
    }
    else
    {
        qDebug()<< q.lastError().text();
        return false;
    }
}

bool sqlOP::isCollegeExist(QString college_id)
{
    QSqlQuery q(db);
    QString strSql =
            QString("select * from college where college_id = '%1'").arg(college_id);
    bool ret = q.exec(strSql);
    if(ret)
    {
        if(q.size())
            return true;
        else
            return false;
    }
    else
    {
        qDebug()<< q.lastError().text();
        return false;
    }
}

bool sqlOP::isCollegeExistByName(QString college_name)
{
    QSqlQuery q(db);
    QString strSql =
            QString("select * from college where college_name = '%1'").arg(college_name);
    bool ret = q.exec(strSql);
    if(ret)
    {
        if(q.size())
            return true;
        else
            return false;
    }
    else
    {
        qDebug()<< q.lastError().text();
        return false;
    }
}

bool sqlOP::isMajorExist(QString major_id)
{
    QSqlQuery q(db);
    QString strSql =
            QString("select * from collegemajor where major_id = '%1'").arg(major_id);
    bool ret = q.exec(strSql);
    if(ret)
    {
        if(q.size())
            return true;
        else
            return false;
    }
    else
    {
        qDebug()<< q.lastError().text();
        return false;
    }
}

bool sqlOP::isMajorExistByName(QString major_name)
{
    QSqlQuery q(db);
    QString strSql =
            QString("select * from collegemajor where major_name = '%1'").arg(major_name);
    bool ret = q.exec(strSql);
    if(ret)
    {
        if(q.size())
            return true;
        else
            return false;
    }
    else
    {
        qDebug()<< q.lastError().text();
        return false;
    }
}

bool sqlOP::isTeacherExist(QString teacher_id)
{
    QSqlQuery q(db);
    QString strSql =
            QString("select * from teacher where teacher_id = '%1'").arg(teacher_id);
    bool ret = q.exec(strSql);
    if(ret)
    {
        if(q.size())
            return true;
        else
            return false;
    }
    else
    {
        qDebug()<< q.lastError().text();
        return false;
    }
}

bool sqlOP::isCourseExist(QString course_id)
{
    QSqlQuery q(db);
    QString strSql =
            QString("select * from course where course_id = '%1'").arg(course_id);
    bool ret = q.exec(strSql);
    if(ret)
    {
        if(q.size())
            return true;
        else
            return false;
    }
    else
    {
        qDebug()<< q.lastError().text();
        return false;
    }
}

bool sqlOP::isCourseExistByName(QString course_name)
{
    QSqlQuery q(db);
    QString strSql =
            QString("select * from course where course_name = '%1'").arg(course_name);
    bool ret = q.exec(strSql);
    if(ret)
    {
        if(q.size())
            return true;
        else
            return false;
    }
    else
    {
        qDebug()<< q.lastError().text();
        return false;
    }
}

bool sqlOP::isCourseSetExist(QString courseSet_id)
{
    QSqlQuery q(db);
    QString strSql =
            QString("select * from courseset where courseSet_id = '%1'").arg(courseSet_id);
    bool ret = q.exec(strSql);
    if(ret)
    {
        if(q.size())
            return true;
        else
            return false;
    }
    else
    {
        qDebug()<< q.lastError().text();
        return false;
    }
}

bool sqlOP::isTimeExist(QString time_id)
{
    QSqlQuery q(db);
    QString strSql =
            QString("select * from time where time_id = '%1'").arg(time_id);
    bool ret = q.exec(strSql);
    if(ret)
    {
        if(q.size())
            return true;
        else
            return false;
    }
    else
    {
        qDebug()<< q.lastError().text();
        return false;
    }
}

bool sqlOP::isAdministratorExist(QString ad_id)
{
    QSqlQuery q(db);
    QString strSql =
            QString("select * from account where user_id = '%1'").arg(ad_id);
    bool ret = q.exec(strSql);
    if(ret)
    {
        if(q.size())
            return true;
        else
            return false;
    }
    else
    {
        qDebug()<< q.lastError().text();
        return false;
    }
}



