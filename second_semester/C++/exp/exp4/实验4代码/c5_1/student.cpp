//student.cpp                            ����Student���г�Ա�����Ķ���
#include "student.h"                   //��Ҫ©д����
  
Student::Student(int n, string na, char s){
	num=n;
	name=na;
	sex=s;
}

void Student::display( )                 //�����ⶨ��display�ຯ��
{
	cout<<"num:"<<num<<endl;
 	cout<<"name:"<<name<<endl;
 	cout<<"sex:"<<sex<<endl;
}

