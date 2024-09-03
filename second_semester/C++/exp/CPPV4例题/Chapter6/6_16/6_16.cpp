//6_16.cpp
#include <iostream>
using namespace std;

class Point {
public:
	Point() : x(0), y(0) {
		cout<<"Default Constructor called."<<endl;
	}

	Point(int x, int y) : x(x), y(y) {
		cout<< "Constructor called."<<endl;
	}

	~Point() { cout<<"Destructor called."<<endl; }

	int getX() const { return x; }

	int getY() const { return y; }

	void move(int newX, int newY) {
		x = newX;
		y = newY;
	}
private:
	int x, y;
};

int main() {
	cout << "Step one: " << endl;
	Point *ptr1 = new Point;	//��̬��������û�и��������б���˵���ȱʡ���캯��
	delete ptr1;	//ɾ�������Զ�������������

	cout << "Step two: " << endl;
	ptr1 = new Point(1,2);		//��̬�������󣬲����������б���˵������βεĹ��캯��
	delete ptr1;	//ɾ�������Զ�������������

	return 0;
}
