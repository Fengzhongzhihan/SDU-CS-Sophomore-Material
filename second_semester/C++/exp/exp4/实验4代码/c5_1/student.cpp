//student.cpp                            这是Student类中成员函数的定义
#include "student.h"                   //不要漏写此行
  
Student::Student(int n, string na, char s){
	num=n;
	name=na;
	sex=s;
}

void Student::display( )                 //在类外定义display类函数
{
	cout<<"num:"<<num<<endl;
 	cout<<"name:"<<name<<endl;
 	cout<<"sex:"<<sex<<endl;
}

