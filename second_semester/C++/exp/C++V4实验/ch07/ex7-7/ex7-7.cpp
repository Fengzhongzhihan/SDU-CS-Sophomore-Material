#include <iostream>
using namespace std;

class BaseClass
{
public:
    BaseClass();
};

BaseClass::BaseClass()
{
    cout << "����������!" << endl;

}

class DerivedClass : public BaseClass
{
public:
    DerivedClass();   
};

DerivedClass::DerivedClass()
{
    cout << "�������������!" << endl;
}


int main()
{
    DerivedClass d;
}
