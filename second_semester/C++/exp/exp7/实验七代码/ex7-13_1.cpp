//7_6.cpp
#include <iostream>
using namespace std;

class Base1 {	//定义基类Base1
public:
    int var;
    void fun() { cout << "Member of Base1" << endl; }
};

class Base2 {	//定义基类Base2
public:
    int var;
    void fun() { cout << "Member of Base2" << endl; }
};

class Derived: public Base1, public Base2 {	//定义派生类Derived
public:
    int var;	//同名数据成员
    void fun() { cout << "Member of Derived" << endl; }	//同名函数成员
};

int main() {
    Derived d;
    cout << "Base1's var pointer: " << &(d.Base1::var) << endl;
	cout << "Base2's var pointer: " << &(d.Base2::var) << endl;

    return 0;
}
