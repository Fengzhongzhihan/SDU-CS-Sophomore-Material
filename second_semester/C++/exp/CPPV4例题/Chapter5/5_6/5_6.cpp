//5_6.cpp
#include <iostream>
#include <cmath>
using namespace std;

class Point {	//Point�ඨ��
public:	//�ⲿ�ӿ�
	Point(int x = 0, int y = 0) : x(x), y(y) { }
	int getX() { return x; }
	int getY() { return y; }
	friend float dist(Point &p1, Point &p2);	//��Ԫ��������
private:	//˽�����ݳ�Ա
	int x, y;
};

float dist(Point &p1, Point &p2) {	//��Ԫ����ʵ��
	double x = p1.x - p2.x;	//ͨ���������˽�����ݳ�Ա
	double y = p1.y - p2.y;
	return static_cast<float>(sqrt(x * x + y * y));
}

int main() {	//������
	Point myp1(1, 1), myp2(4, 5);	//����Point��Ķ���
	cout << "The distance is: ";
	cout << dist(myp1, myp2) << endl;	//���������ľ���
	return 0;
}
