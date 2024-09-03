#include <iostream>
using namespace std;

class Object {
private:
	int weight;
public:
	Object() {
		cout << "����Object����" << endl;
		weight = 0;
	}
	int getWeight() {
		return weight;
	}
	void setWeight(int n) {
		weight = n;
	}
	~Object() {
		cout << "����Object����" << endl;
	}
};

class Box: public Object {
private:
	int height, width;
public:
	Box() {
		cout << "����Box����" << endl;
		height = width = 0;
	}
	int getHeight() {
		return height;
	}
	void setHeight(int n) {
		height = n;
	}
	int getWidth() {
		return width;
	}
	void setWidth(int n) {
		width = n;
	}
	~Box() {
		cout << "����Box����" << endl;
	}
};

int main() {
	Box a;
	return 0;
}
