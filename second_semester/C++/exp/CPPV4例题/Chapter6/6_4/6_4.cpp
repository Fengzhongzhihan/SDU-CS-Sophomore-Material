//6_4.cpp
#include "Point.h"
#include <iostream>
#include <cmath>
using namespace std;

//ֱ��������ϣ�pointsΪ���㣬nPointΪ����
float lineFit(const Point points[], int nPoint) {
	float avgX = 0, avgY = 0;
	float lxx = 0, lyy = 0, lxy = 0;
	for(int i = 0; i < nPoint; i++)	{ //����x��y��ƽ��ֵ
		avgX += points[i].getX() / nPoint;
		avgY += points[i].getY() / nPoint;
	}
	for(int i = 0; i < nPoint; i++)	{ //����Lxx��Lyy��Lxy
		lxx += (points[i].getX() - avgX) * (points[i].getX() - avgX);
		lyy += (points[i].getY() - avgY) * (points[i].getY() - avgY);
		lxy += (points[i].getX() - avgX) * (points[i].getY() - avgY);
	}
	cout << "This line can be fitted by y=ax+b." << endl;
	cout << "a = " << lxy / lxx << "  ";	//����ع�ϵ��a
	cout << "b = " << avgY - lxy * avgX / lxx << endl;	//����ع�ϵ��b
	return static_cast<float>(lxy / sqrt(lxx * lyy));	//�������ϵ��r
}

int main() {
	Point p[10] = { Point(6, 10), Point(14, 20), Point(26, 30), Point(33, 40), Point(46, 50),
		Point(54, 60), Point(67, 70), Point(75, 80), Point(84, 90), Point(100, 100) };	//��ʼ�����ݵ�
	float r = lineFit(p, 10);	//�������Իع����
	cout << "Line coefficient r = " << r << endl;	//������ϵ��
	return 0;
}
