//Point.h
#ifndef _POINT_H
#define _POINT_H

class Point {	//��Ķ���
public:	//�ⲿ�ӿ�
	Point();
	Point(int x, int y);
	~Point();
	void move(int newX,int newY);
	int getX() const { return x; }
	int getY() const { return y; }
	static void showCount();	//��̬������Ա
private:	//˽�����ݳ�Ա
	int x, y;
};

#endif	//_POINT_H
