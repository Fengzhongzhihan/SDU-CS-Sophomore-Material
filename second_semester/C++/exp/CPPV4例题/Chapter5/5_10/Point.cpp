//�ļ�2�����ʵ�֣�Point.cpp
#include "Point.h"
#include <iostream>
using namespace std;

int Point::count = 0;	//ʹ��������ʼ����̬���ݳ�Ա

Point::Point(const Point &p) : x(p.x), y(p.y) {	//�������캯����
	count++;
}

void Point::showCount() {
	cout << "  Object count = " << count << endl;
}
