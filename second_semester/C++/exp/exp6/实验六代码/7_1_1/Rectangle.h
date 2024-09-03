//Rectangle.h
#ifndef _RECTANGLE_H
#define _RECTANGLE_H
#include "Point.h"

class Rectangle: public Point {	//�����ඨ�岿�֣���Ϊ�̳л��Զ��̳�һ��Point���󣬲�����Ĭ�ϵĹ��캯����
public:	//�������к�����Ա
	Rectangle(float a, float b, float w, float h) :Point(a, b) {

		cout << getX() <<", "<< getY() <<endl;	//������ε���������
		
		this->w = w;
		this->h = h;
	}
	float getH() const { return h; }
	float getW() const { return w; }
private:	//����˽�����ݳ�Ա
	float w, h;
};

#endif //_RECTANGLE_H
