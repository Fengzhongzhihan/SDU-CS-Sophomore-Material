//7_6.cpp
#include <iostream>
using namespace std;

class Base1 {	//�������Base1
public:
	int var;
	void fun() { cout << "Member of Base1" << endl; }
};

class Base2 {	//�������Base2
public:
	int var;
	void fun() { cout << "Member of Base2" << endl; }
};

class Derived: public Base1, public Base2 {	//����������Derived
public:
	int var;	//ͬ�����ݳ�Ա
	void fun() { cout << "Member of Derived" << endl; }	//ͬ��������Ա
};

int main() {
	Derived d;
	Derived *p = &d;

	d.var = 1;	//������.��Ա����ʶ
	d.fun();	//����D1���Ա
	
	d.Base1::var = 2;	//������ֱ����ʶ
	d.Base1::fun();	//����Base1�����Ա
	
	p->Base2::var = 3;	//������ֱ����ʶ
	p->Base2::fun();	//����Base2�����Ա

	return 0;
}
