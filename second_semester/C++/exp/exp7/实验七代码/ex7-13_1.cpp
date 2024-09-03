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
    cout << "Base1's var pointer: " << &(d.Base1::var) << endl;
	cout << "Base2's var pointer: " << &(d.Base2::var) << endl;

    return 0;
}
