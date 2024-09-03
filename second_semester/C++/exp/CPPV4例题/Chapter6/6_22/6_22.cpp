//6_22.cpp
#include <iostream>
#include <cassert>
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

//��̬������
class ArrayOfPoints {
public:
	ArrayOfPoints(int size) : size(size) {
		points = new Point[size];
	}

	ArrayOfPoints(const ArrayOfPoints& v);

	~ArrayOfPoints() {
		cout << "Deleting..." << endl;
		delete[] points;     
	}

	//����±�Ϊindex������Ԫ��
	Point &element(int index) {
		assert(index >= 0 && index < size);	//��������±겻��Խ�磬������ֹ
		return points[index];
	}
private:
	Point *points;	//ָ��̬�����׵�ַ
	int size;		//�����С
};

ArrayOfPoints::ArrayOfPoints(const ArrayOfPoints& v) {
	size = v.size;
	points = new Point[size];
	for (int i = 0; i < size; i++)
		points[i] = v.points[i];
}

int main() {
	int count;
	cout << "Please enter the count of points: ";
	cin >> count;
	ArrayOfPoints pointsArray1(count);		//������������
	pointsArray1.element(0).move(5,10);
	pointsArray1.element(1).move(15,20);
	
	ArrayOfPoints pointsArray2 = pointsArray1; //�����������鸱��
	cout << "Copy of pointsArray1:" << endl;
	cout << "Point_0 of array2: " << pointsArray2.element(0).getX() << ", "
		<< pointsArray2.element(0).getY() << endl;
	cout << "Point_1 of array2: " << pointsArray2.element(1).getX() << ", "
		<< pointsArray2.element(1).getY() << endl;

	pointsArray1.element(0).move(25, 30);
	pointsArray1.element(1).move(35, 40);
	cout << "After the moving of pointsArray1:" << endl;
	cout << "Point_0 of array2: " << pointsArray2.element(0).getX() << ", "
		<< pointsArray2.element(0).getY() << endl;
	cout << "Point_1 of array2: " << pointsArray2.element(1).getX() << ", "
		<< pointsArray2.element(1).getY() << endl;

	return 0;
}
