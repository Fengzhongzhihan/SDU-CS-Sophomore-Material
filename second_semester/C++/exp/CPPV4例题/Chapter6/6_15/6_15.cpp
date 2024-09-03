//6_15.cpp
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

	static void showCount() {		//�����̬���ݳ�Ա
		cout << "  Object count = " << count << endl;
	}

private:	//˽�����ݳ�Ա
	int x, y;
	static int count;	//��̬���ݳ�Ա���������ڼ�¼��ĸ���
};

int Point::count = 0;	//��̬���ݳ�Ա����ͳ�ʼ����ʹ�������޶�

int main() {	//������ʵ��
	void (*funcPtr)() = Point::showCount;	//����һ��ָ������ָ�룬ָ����ľ�̬��Ա����

	Point a(4, 5);	//�������A
	cout << "Point A: " << a.getX() << ", " << a.getY();
	funcPtr();	//������������ֱ��ͨ��ָ����ʾ�̬������Ա

	Point b(a);	//�������B
	cout << "Point B: " << b.getX() << ", " << b.getY();
	funcPtr();	//������������ֱ��ͨ��ָ����ʾ�̬������Ա

	return 0;
}
