//8_5.cpp
#include <iostream>
using namespace std;

class Base {
public:
	// virtual ~Base();
	~Base();
};
Base::~Base() {
	cout<< "Base destructor" << endl;
 }

class Derived: public Base {
public:
	Derived();
	virtual ~Derived();
	//~Derived();
private:
	int *p;
};
Derived::Derived() {
	p = new int(0);
}
Derived::~Derived() { 
	cout <<  "Derived destructor" << endl;
	delete p;
}

void fun(Base* b) {
	delete b;
}

int main() {
	Base *b = new Derived();
	fun(b);

	Base b1=Derived();
	Derived d1;   fun(&d1);
	return 0;
}
