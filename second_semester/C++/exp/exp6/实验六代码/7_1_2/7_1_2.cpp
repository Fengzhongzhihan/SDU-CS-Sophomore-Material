//7_1.cpp
#include <iostream>
#include <cmath>
#include "Rectangle.h"
using namespace std;

int main() {
	Rectangle rect(2, 3, 20, 10);	//����Rectangle��Ķ������rect.initRectangle(2, 3, 20, 10);
	cout << "The data of rect(x,y,w,h): " << endl;
	cout << rect.getX() <<", "	//������ε���������
		<< rect.getY() << ", "
		<< rect.getW() << ", "
		<< rect.getH() << endl;
	rect.move(3,2);	//�ƶ�����λ��
	cout << "The data of rect(x,y,w,h): " << endl;
	cout << rect.getX() <<", "	//������ε���������
		<< rect.getY() << ", "
		<< rect.getW() << ", "
		<< rect.getH() << endl;
	return 0;
}
