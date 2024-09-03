//student.h      

#ifndef STUDENT_H
#define STUDENT_H
#include <iostream> 
using namespace std;     
class Student               //类定义        
{ public:
	Student(int num,string name,char sex);
    void display( );    	//公用成员函数原型声明
  private:
    int num;
    string name;
    char sex ;
  };

#endif