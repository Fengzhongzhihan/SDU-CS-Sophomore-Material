#ifndef _LINE_H
#define _LINE_H

#include"Point.h" 
#include"Shape.h" 
#include<iostream>
using namespace std;

class Line:public Shape{	//Line类，继承 
 public: //外部接口

    Line(const Point& p1, const Point &p2){  //构造方法 
		this->p1=p1; this->p2=p2;
	}
	
	virtual void show()	{  //show的实现 
    	cout<<"Line from p1:("<<p1.getX()<<","<<p1.getY()<<") to p2:("<<p2.getX()<<","<<p2.getY()<<")"<<endl;
	}

private:	//私有数据成员
	Point p1, p2;	 //新增成员 

};

#endif 
