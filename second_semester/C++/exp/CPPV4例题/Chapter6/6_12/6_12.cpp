//6_12.cpp
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
	Point a(4, 5);	//���岢��ʼ������a
	Point *p1 = &a;	//�������ָ�룬��a�ĵ�ַ�����ʼ��
	cout << p1->getX() << endl;	//����ָ����ʶ����Ա
	cout << a.getX() << endl; 	//���ö��������ʶ����Ա
	return 0;
}
