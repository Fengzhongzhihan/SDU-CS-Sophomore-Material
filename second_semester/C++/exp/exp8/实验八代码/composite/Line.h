#ifndef _LINE_H
#define _LINE_H

#include "Point.h"
#include <iostream>
using namespace std;

class Line {	//Line类，组合类 
public:	//外部接口
	Line(const Point& p1, const Point &p2){
		this->p1=p1; this->p2=p2;
	}
    void show()	{
    	cout<<"Line from p1:("<<p1.getX()<<","<<p1.getY()<<") to p2:("<<p2.getX()<<","<<p2.getY()<<")"<<endl;
	}

private:	//私有数据成员
	Point p1, p2;	 //Point类成员 
};

#endif //_LINE_H
