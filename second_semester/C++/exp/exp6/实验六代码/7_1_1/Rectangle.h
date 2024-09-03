//Rectangle.h
#ifndef _RECTANGLE_H
#define _RECTANGLE_H
#include "Point.h"

class Rectangle: public Point {	//派生类定义部分，因为继承会自动继承一个Point对象，并调用默认的构造函数。
public:	//新增公有函数成员
	Rectangle(float a, float b, float w, float h) :Point(a, b) {

		cout << getX() <<", "<< getY() <<endl;	//输出矩形的特征参数
		
		this->w = w;
		this->h = h;
	}
	float getH() const { return h; }
	float getW() const { return w; }
private:	//新增私有数据成员
	float w, h;
};

#endif //_RECTANGLE_H
