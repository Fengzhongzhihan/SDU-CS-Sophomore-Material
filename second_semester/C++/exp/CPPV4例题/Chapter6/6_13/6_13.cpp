//6_13.cpp
#include <iostream>
using namespace std;

class Point {	//��Ķ���
public:	//�ⲿ�ӿ�
	Point(int x = 0, int y = 0) : x(x), y(y) { }	//���캯��
	int getX() const { return x; }	//����x
	int getY() const { return y; }	//����y
private:	//˽������
	int x, y;
};

int main() {	//������
	Point a(4,5);	//�������A
	Point *p1 = &a;	//�������ָ�벢��ʼ��
	int (Point::*funcPtr)() const = &Point::getX;	//�����Ա����ָ�벢��ʼ��
	
	cout << (a.*funcPtr)() << endl;		//(1)ʹ�ó�Ա����ָ��Ͷ��������ʳ�Ա����
	cout << (p1->*funcPtr)() << endl;	//(2)ʹ�ó�Ա����ָ��Ͷ���ָ����ʳ�Ա����
	cout << a.getX() << endl;			//(3)ʹ�ö��������ʳ�Ա����
	cout << p1->getX() << endl;			//(4)ʹ�ö���ָ����ʳ�Ա����

	return 0;
}
