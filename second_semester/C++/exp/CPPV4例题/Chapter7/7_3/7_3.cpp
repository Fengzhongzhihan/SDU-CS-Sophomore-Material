//7_3.cpp
#include <iostream>
using namespace std;

class Base1 { //����Base1����
public:
	void display() const { cout << "Base1::display()" << endl; }
};

class Base2: public Base1 { //����������Base2��������
public:
	void display() const { cout << "Base2::display()" << endl; }
};

class Derived: public Base2 { //����������Derived��������
public:
	void display() const { cout << "Derived::display()" << endl; }
};

void fun(Base1 *ptr) { //����Ϊָ���������ָ��
	ptr->display();	//"����ָ��->��Ա��"
}

int main() {	//������
	Base1 base1;	//����Base1�����
	Base2 base2;	//����Base2�����
	Derived derived;	//����Derived�����

	fun(&base1);	//��Base1�����ָ�����fun����
	fun(&base2);	//��Base2�����ָ�����fun����
	fun(&derived);	//��Derived�����ָ�����fun����

	return 0;
}
