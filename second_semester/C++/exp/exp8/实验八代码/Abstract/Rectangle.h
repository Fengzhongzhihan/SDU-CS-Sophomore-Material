#ifndef _RECTANGLE_H
#define _RECTANGLE_H

#include"Point.h" 
#include"Shape.h" 
#include<iostream>

class Rectangle:public Shape{  //�����࣬�̳� 
public:	
	Rectangle(const Point& upleft, float w, float h) {  //���Ͻǵ㣬���� 
		this->upleft=upleft; //
		this->w = w;
		this->h = h;
	}
	virtual void show()	{
    	cout<<"Rectangle upleft:("<<upleft.getX()<<","<<upleft.getY()<<")"<<" width:"<<w<<" height:"<<h<<endl;
	}
	float getH() const { return h; }
	float getW() const { return w; }
private:	
	Point upleft;
	float w, h;
};

#endif
