//Point.h
#include<iostream>
using namespace std;
#ifndef _POINT_H
#define _POINT_H

class Point {	//����Point��Ķ���
public:	//���к�����Ա
	Point(float a=0 , float b=0 ) { 
	this->x = a; this->y = b;
	cout<<"In Point constructor:"<<x<<","<<y<<",this:"<<this<<endl;}
	void move(float offX, float offY) { x += offX; y += offY; }
	float getX()  { return x; }
	float getY()  { return y; }
private:	//˽�����ݳ�Ա
	float x, y;
};

#endif //_POINT_H
