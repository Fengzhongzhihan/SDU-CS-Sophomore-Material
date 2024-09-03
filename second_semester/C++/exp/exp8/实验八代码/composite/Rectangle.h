#ifndef _RECTANGLE_H
#define _RECTANGLE_H

#include <iostream>
#include "Point.h" 
using namespace std;

class Rectangle {	
public:	
	Rectangle(const Point& upleft, float w, float h) {  //左上角点，宽，高 
		this->upleft=upleft; 
		this->w = w;
		this->h = h;
	}
	void show()	{
    	cout<<"Rectangle upleft:("<<upleft.getX()<<","<<upleft.getY()<<")"<<" width:"<<w<<" height:"<<h<<endl;
	}
	float getH() const { return h; }
	float getW() const { return w; }
private:	
	Point upleft;  //Point类成员 
	float w, h;
};
#endif //_RECTANGLE_H
