//student.h      

#ifndef STUDENT_H
#define STUDENT_H
#include <iostream> 
using namespace std;     
class Student               //�ඨ��        
{ public:
	Student(int num,string name,char sex);
    void display( );    	//���ó�Ա����ԭ������
  private:
    int num;
    string name;
    char sex ;
  };

#endif