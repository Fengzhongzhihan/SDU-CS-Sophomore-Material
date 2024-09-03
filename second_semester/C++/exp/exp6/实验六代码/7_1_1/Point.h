//Point.h
#include<iostream>
using namespace std;
#ifndef _POINT_H
#define _POINT_H

class Point {	//基类Point类的定义
public:	//公有函数成员
	Point(float a=0 , float b=0 ) { 
	this->x = a; this->y = b;
	cout<<"In Point constructor:"<<x<<","<<y<<",this:"<<this<<endl;}
	void move(float offX, float offY) { x += offX; y += offY; }
	float getX()  { return x; }
	float getY()  { return y; }
private:	//私有数据成员
	float x, y;
};

#endif //_POINT_H
