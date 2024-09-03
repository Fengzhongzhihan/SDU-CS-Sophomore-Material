//Point.h
#ifndef _POINT_H
#define _POINT_H

class Point {	//Point��Ķ���
public:	//�ⲿ�ӿ�
	Point(float x = 0, float y = 0) : x(x), y(y) { }
	float getX() const { return x; }
	float getY() const { return y; }
private:	//˽�����ݳ�Ա
	float x, y;
};
#endif	//_POINT_H
