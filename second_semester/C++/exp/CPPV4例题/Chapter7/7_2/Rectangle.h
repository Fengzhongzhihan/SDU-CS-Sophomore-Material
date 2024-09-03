//Rectangle.h
#ifndef _RECTANGLE_H
#define _RECTANGLE_H
#include "Point.h"

class Rectangle: private Point {	//�����ඨ�岿��
public:	//�������к�����Ա
	void initRectangle(float x, float y, float w, float h) {
		initPoint(x, y); //���û��๫�г�Ա����
		this->w = w;
		this->h = h;
	}
	void move(float offX, float offY) { Point::move(offX, offY); }
	float getX() const { return Point::getX(); }
	float getY() const { return Point::getY(); }
	float getH() const { return h; }
	float getW() const { return w; }
private:	//����˽�����ݳ�Ա
	float w, h;
};

#endif //_RECTANGLE_H
