//�ļ�3����������5_10.cpp
#include "Point.h"
#include <iostream>
using namespace std;

int main() {
	Point a(4, 5);	//�������a���乹�캯����ʹcount��1
	cout << "Point A: " << a.getX() << ", " << a.getY();
	Point::showCount();	//����������

	Point b(a);	//�������b���乹�캯����ʹcount��1
	cout << "Point B: " << b.getX() << ", " << b.getY();
	Point::showCount();	//����������

	return 0;
}
