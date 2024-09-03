#ifndef _LINE_H
#define _LINE_H

#include "Point.h"
#include <iostream>
using namespace std;

class Line {	//Line�࣬����� 
public:	//�ⲿ�ӿ�
	Line(const Point& p1, const Point &p2){
		this->p1=p1; this->p2=p2;
	}
    void show()	{
    	cout<<"Line from p1:("<<p1.getX()<<","<<p1.getY()<<") to p2:("<<p2.getX()<<","<<p2.getY()<<")"<<endl;
	}

private:	//˽�����ݳ�Ա
	Point p1, p2;	 //Point���Ա 
};

#endif //_LINE_H
