//6_14.cpp
#include <iostream>
using namespace std;

class Point {	//Point�ඨ��
public:	//�ⲿ�ӿ�
	Point(int x = 0, int y = 0) : x(x), y(y) { //���캯��
		count++;
	}	
	Point(const Point &p) : x(p.x), y(p.y) {	//�������캯��
		count++;
	}
	~Point() {  count--; }
	int getX() const { return x; }
	int getY() const { return y; }
	static int count;	//��̬���ݳ�Ա���������ڼ�¼��ĸ���

private:	//˽�����ݳ�Ա
	int x, y;
};

int Point::count = 0;	//��̬���ݳ�Ա����ͳ�ʼ����ʹ�������޶�

int main() {	//������ʵ��
	int *ptr = &Point::count;	//����һ��int��ָ�룬ָ����ľ�̬��Ա
	Point a(4, 5);	//�������a
	cout << "Point A: " << a.getX() << ", " << a.getY();
	cout << " Object count = " << *ptr << endl;	//ֱ��ͨ��ָ����ʾ�̬���ݳ�Ա

	Point b(a);	//�������b
	cout << "Point B: " << b.getX() << ", " << b.getY();
	cout << " Object count = " << *ptr << endl; 	//ֱ��ͨ��ָ����ʾ�̬���ݳ�Ա

	return 0;
}
