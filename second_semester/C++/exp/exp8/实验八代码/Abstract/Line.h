#ifndef _LINE_H
#define _LINE_H

#include"Point.h" 
#include"Shape.h" 
#include<iostream>
using namespace std;

class Line:public Shape{	//Line�࣬�̳� 
 public: //�ⲿ�ӿ�

    Line(const Point& p1, const Point &p2){  //���췽�� 
		this->p1=p1; this->p2=p2;
	}
	
	virtual void show()	{  //show��ʵ�� 
    	cout<<"Line from p1:("<<p1.getX()<<","<<p1.getY()<<") to p2:("<<p2.getX()<<","<<p2.getY()<<")"<<endl;
	}

private:	//˽�����ݳ�Ա
	Point p1, p2;	 //������Ա 

};

#endif 
