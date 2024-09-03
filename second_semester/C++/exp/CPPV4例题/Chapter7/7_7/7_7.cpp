//7_7.cpp
#include <iostream>
using namespace std;

class Base0 {	//�������Base0
public:
	int var0;
	void fun0() { cout << "Member of Base0" << endl; }
};

class Base1: public Base0 {	//����������Base1
public:	//�����ⲿ�ӿ�
	int var1;
};

class Base2: public Base0 {	//����������Base2
public:	//�����ⲿ�ӿ�
	int var2;
};

class Derived: public Base1, public Base2 {	//����������Derived
public:	//�����ⲿ�ӿ�
	int var;
	void fun() { cout << "Member of Derived" << endl; }
};

int main() {	//����������
	Derived d;			//����Derived�����d
	d.Base1::var0 = 2;	//ʹ��ֱ�ӻ���
	d.Base1::fun0();
	d.Base2::var0 = 3;	//ʹ��ֱ�ӻ���
	d.Base2::fun0();
	return 0;
}
