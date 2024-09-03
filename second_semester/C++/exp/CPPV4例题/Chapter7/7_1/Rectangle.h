//Rectangle.h
#ifndef _RECTANGLE_H
#define _RECTANGLE_H
#include "Point.h"

class Rectangle: public Point {	//�����ඨ�岿��
public:	//�������к�����Ա
	void initRectangle(float x, float y, float w, float h) {
		initPoint(x, y); //���û��๫�г�Ա����
		this->w = w;
		this->h = h;
	}
	float getH() const { return h; }
	float getW() const { return w; }
private:	//����˽�����ݳ�Ա
	float w, h;
};

#endif //_RECTANGLE_H
