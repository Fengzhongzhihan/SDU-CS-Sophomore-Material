//5_5.cpp
#include <iostream>
using namespace std;

class Point {	//Point�ඨ��
public:	//�ⲿ�ӿ�
	Point(int x = 0, int y = 0) : x(x), y(y) { //���캯��
		//�ڹ��캯���ж�count�ۼӣ����ж���ͬά��ͬһ��count
		count++;
	}	
	Point(Point &p) {	//�������캯��
		x = p.x;
		y = p.y;
		count++;
	}
	~Point() {  count--; }
	int getX() { return x; }
	int getY() { return y; }

	static void showCount() {		//��̬������Ա
		cout << "  Object count = " << count << endl;
	}
private:	//˽�����ݳ�Ա
	int x, y;
	static int count;	//��̬���ݳ�Ա���������ڼ�¼��ĸ���
};

int Point::count = 0;	//��̬���ݳ�Ա����ͳ�ʼ����ʹ�������޶�

int main() {	//������
	Point a(4, 5);	//�������a���乹�캯����ʹcount��1
	cout << "Point A: " << a.getX() << ", " << a.getY();
	Point::showCount();	//����������

	Point b(a);	//�������b���乹�캯����ʹcount��1
	cout << "Point B: " << b.getX() << ", " << b.getY();
	Point::showCount();	//����������

	return 0;
}
