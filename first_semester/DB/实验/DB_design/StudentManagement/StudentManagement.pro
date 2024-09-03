QT       += core gui
QT += sql
QT += axcontainer

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adcell1_administrator.cpp \
    adcell1_college.cpp \
    adcell1_course.cpp \
    adcell1_courseset.cpp \
    adcell1_score.cpp \
    adcell1_student.cpp \
    adcell1_stupa.cpp \
    adcell1_takes.cpp \
    adcell1_teacher.cpp \
    adcell2_addadministrator.cpp \
    adcell2_addcollege.cpp \
    adcell2_addcourse.cpp \
    adcell2_addcourseset.cpp \
    adcell2_addmajor.cpp \
    adcell2_addstudent.cpp \
    adcell2_addstupa.cpp \
    adcell2_addteacher.cpp \
    adcell2_addtime.cpp \
    adcell2_updatecollege.cpp \
    adcell2_updatecourse.cpp \
    adcell2_updatecourseset.cpp \
    adcell2_updatescore.cpp \
    adcell2_updatestudent.cpp \
    adcell2_updateteacher.cpp \
    adcell2_updatetime.cpp \
    administratoruser.cpp \
    main.cpp \
    login.cpp \
    sqlop.cpp \
    stucell_course.cpp \
    stucell_grade.cpp \
    stucell_info.cpp \
    stucell_pa.cpp \
    stucell_updateinfo.cpp \
    studentuser.cpp \
    teacell_course.cpp \
    teacell_score.cpp \
    teacell_stuinfo.cpp \
    teacell_teainfo.cpp \
    teacell_updateinfo.cpp \
    teacell_updatestuinfo.cpp \
    teacheruser.cpp

HEADERS += \
    adcell1_administrator.h \
    adcell1_college.h \
    adcell1_course.h \
    adcell1_courseset.h \
    adcell1_score.h \
    adcell1_student.h \
    adcell1_stupa.h \
    adcell1_takes.h \
    adcell1_teacher.h \
    adcell2_addadministrator.h \
    adcell2_addcollege.h \
    adcell2_addcourse.h \
    adcell2_addcourseset.h \
    adcell2_addmajor.h \
    adcell2_addstudent.h \
    adcell2_addstupa.h \
    adcell2_addteacher.h \
    adcell2_addtime.h \
    adcell2_updatecollege.h \
    adcell2_updatecourse.h \
    adcell2_updatecourseset.h \
    adcell2_updatescore.h \
    adcell2_updatestudent.h \
    adcell2_updateteacher.h \
    adcell2_updatetime.h \
    administratoruser.h \
    login.h \
    sqlop.h \
    stucell_course.h \
    stucell_grade.h \
    stucell_info.h \
    stucell_pa.h \
    stucell_updateinfo.h \
    studentuser.h \
    teacell_course.h \
    teacell_score.h \
    teacell_stuinfo.h \
    teacell_teainfo.h \
    teacell_updateinfo.h \
    teacell_updatestuinfo.h \
    teacheruser.h

FORMS += \
    adcell1_administrator.ui \
    adcell1_college.ui \
    adcell1_course.ui \
    adcell1_courseset.ui \
    adcell1_score.ui \
    adcell1_student.ui \
    adcell1_stupa.ui \
    adcell1_takes.ui \
    adcell1_teacher.ui \
    adcell2_addadministrator.ui \
    adcell2_addcollege.ui \
    adcell2_addcourse.ui \
    adcell2_addcourseset.ui \
    adcell2_addmajor.ui \
    adcell2_addstudent.ui \
    adcell2_addstupa.ui \
    adcell2_addteacher.ui \
    adcell2_addtime.ui \
    adcell2_updatecollege.ui \
    adcell2_updatecourse.ui \
    adcell2_updatecourseset.ui \
    adcell2_updatescore.ui \
    adcell2_updatestudent.ui \
    adcell2_updateteacher.ui \
    adcell2_updatetime.ui \
    administratoruser.ui \
    login.ui \
    stucell_course.ui \
    stucell_grade.ui \
    stucell_info.ui \
    stucell_pa.ui \
    stucell_updateinfo.ui \
    studentuser.ui \
    teacell_course.ui \
    teacell_score.ui \
    teacell_stuinfo.ui \
    teacell_teainfo.ui \
    teacell_updateinfo.ui \
    teacell_updatestuinfo.ui \
    teacheruser.ui

TRANSLATIONS += \
    StudentManagement_zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    picture.qrc

