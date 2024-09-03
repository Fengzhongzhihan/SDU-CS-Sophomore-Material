//5_8.cpp
#include <iostream>
using namespace std;

class A {
public:
	A(int i);
	void print();
private:
	const int a;
	static const int b;   //��̬�����ݳ�Ա
};

const int A::b = 10;	//��̬�����ݳ�Ա������˵���ͳ�ʼ��

//�����ݳ�Աֻ��ͨ����ʼ���б�����ó�ֵ
A::A(int i) : a(i) { }

void A::print() {
	cout << a << ":" << b << endl;
}
int main() {
/*��������a��b������100��0��Ϊ��ֵ���ֱ���ù��캯����ͨ�����캯���ĳ�
	ʼ���б������ĳ����ݳ�Ա����ֵ*/
	A a1(100), a2(0);  
	a1.print();
	a2.print();
	return 0;
}
