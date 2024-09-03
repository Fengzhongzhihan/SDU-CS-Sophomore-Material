//7_4.cpp
#include <iostream>
using namespace std;

class Base1 {	//����Base1�����캯���в���
public:
	Base1(int i) { cout << "Constructing Base1 " << i << endl; }
};

class Base2 {	//����Base2�����캯���в���
public:
	Base2(int j) { cout << "Constructing Base2 " << j << endl; }
};

class Base3 {	//����Base3�����캯���޲���
public:
	Base3() { cout << "Constructing Base3 *" << endl; }
};

class Derived: public Base2, public Base1, public Base3 {
//��������Derived��ע���������˳��
public:	//������Ĺ��г�Ա
	Derived(int a, int b, int c, int d): Base1(a), member2(d), member1(c), Base2(b) { }
	//ע��������ĸ�����˳��ע���Ա�������ĸ�����˳��
private:	//�������˽�г�Ա����
	Base1 member1;
	Base2 member2;
	Base3 member3;
};

int main() {
	Derived obj(1, 2, 3, 4);
	return 0;
}
