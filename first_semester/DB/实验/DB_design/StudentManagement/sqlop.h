#ifndef SQLOP_H
#define SQLOP_H
#include <QtDebug>
#include <QSqlDatabase>
#include <QCoreApplication>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDateTime>
#include <QMessageBox>

class sqlOP
{
public:
    sqlOP();
    static sqlOP* instance;
    static sqlOP* getInstance() {
        if(nullptr == instance ) {
            instance = new sqlOP();
        }
        return instance;
    }

    void init();

    //显示学生信息
    QVector<QStringList> getStudentInfos(QString strCondition="");

    // 显示老师信息
    QVector<QStringList> getTeacherInfos(QString strCondition="");

    // 显示课程集信息
    QVector<QStringList> getCourseSetInfos(QString strCondition="");

    // 显示课程信息
    QVector<QStringList> getCourseInfos(QString strCondition="");

    // 显示学院信息
    QVector<QStringList> getCollegeInfos(QString strCondition="");

    // 显示管理员信息
    QVector<QStringList> getAdministratorInfos(QString strCondition="");

    // 显示时间编号
    QVector<QStringList> getTimeInfos(QString strCondition="");

    // 显示学生选课信息
    QVector<QStringList> getTakesInfos(QString strCondition="");

    // 增加学生
    void addStudentInfos(QStringList stuInfo);

    // 增加老师
    void addTeacherInfos(QStringList teaInfo);

    // 增加课程
    void addCourseInfos(QStringList courInfo);

    // 增加学院
    void addCollegeInfos(QStringList collInfo);

    // 增加专业
    void addCollegeMajorInfos(QStringList cmInfo);

    // 增加管理员
    void addAdministratorInfos(QStringList AdInfo);

    // 增加时间编号
    void addTimeInfos(QStringList timeInfo);

    // 增加开设课程
    void addCourseSetInfos(QStringList courSetInfo);

    // 删除学生
    void deleteStudentInfos(QString sid);

    // 删除老师
    void deleteTeacherInfos(QString tid);

    // 删除课程
    void deleteCourseInfos(QString cid);

    // 删除学院
    void deleteCollegeInfos(QString college_id);

    // 删除专业
    void deleteMajorInfos(QString major_id);

    // 删除自己的管理员账户
    void deleteMyAdministratorInfos(QString user_id);

    // 删除时间编号
    void deleteTimeInfos(QString time_id);

    // 删除开设课程
    void deleteCourseSetInfos(QString cs_id);

    // 修改学生信息
    void updateStudentInfos(QStringList stuInfo);

    // 修改老师信息
    void updateTeacherInfos(QStringList stuInfo);

    // 修改课程信息
    void updateCourseInfos(QStringList courInfo);

    // 修改开设的课程集信息
    void updateCourseSetInfos(QStringList csInfo);

    // 修改学院信息
    void updateCollegeInfos(QStringList collegeInfo);//

    // 学生选取课程
    void selectCourse(QString sid, QString courseSet_id);

    // 学生退课
    void quitCourse(QString sid ,QString courseSet_id);

    // 判断课程是否选过了
    bool isSelected(QString sid, QString courseSet_id);

    // 选取学生已选的课程
    QVector<QStringList> showSelectedCourse(QString strCondition="");

    // 显示成绩，但不会显示0分的成绩
    QVector<QStringList> getStuScore(QString strCondition="");

    // 重修课程
    void reStudyCourse(QString sid, QString courseSet_id);

    // 补考课程
    void reExamCourse(QString sid, QString courseSet_id);

    // 显示奖惩情况
    QVector<QStringList> getPArecords(QString strCondition="");

    // 登记学生奖惩
    void stuPaRegister(QStringList paInfo);

    // 删除学生奖惩
    void deleteStuPaInfos(QString sid,QString paInfo);

    // 显示老师信息
    QVector<QStringList> getTeachersInfos(QString strCondition="");

    // 选择选课的学生
    QVector<QStringList> selectMyStudents(QString strCondition="");

    // 判断是否是我的课程
    bool isMyClass(QString tid, QString courseSet_id);

    // 设置分数
    bool setScore(QString sid, QString courseSet_id, QString score);

    // 统计课程数据
    QVector<QStringList>  countScore(QString courseSet_id);

    // 判断学生是否存在
    bool isStudentExist(QString sid);

    // 判断身份证号是否存在
    bool isIdentityExist(QString identity_id);

    // 判断学院是否存在
    bool isCollegeExist(QString college_id);

    // 判断学院是否存在，使用名称
    bool isCollegeExistByName(QString college_name);

    // 判断专业是否存在
    bool isMajorExist(QString major_id);

    // 判断专业是否存在，使用名称
    bool isMajorExistByName(QString major_name);

    // 判断老师是否存在
    bool isTeacherExist(QString teacher_id);

    // 判断课程是否存在
    bool isCourseExist(QString course_id);

    // 判断课程是否存在，使用名称
    bool isCourseExistByName(QString course_name);

    // 判断课程集是否存在
    bool isCourseSetExist(QString courseSet_id);

    // 判断时间编号是否存在
    bool isTimeExist(QString time_id);

    // 判断管理员是否存在
    bool isAdministratorExist(QString ad_id);
private:
    QSqlDatabase db;
};

#endif // SQLOP_H
