//7_2.cpp
#include <iostream>
#include <cmath>
#include "Rectangle.h"
using namespace std;

int main() {
	Rectangle rect;	//����Rectangle��Ķ���
	rect.initRectangle(2, 3, 20, 10);	//���þ��ε�����
	rect.move(3,2);	//�ƶ�����λ��
	cout << "The data of rect(x,y,w,h): " << endl;
	cout << rect.getX() <<", "	//������ε���������
		<< rect.getY() << ", "
		<< rect.getW() << ", "
		<< rect.getH() << endl;
	return 0;
}
