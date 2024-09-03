//8_3.cpp
#include <iostream>
using namespace std;

class Complex {	//�����ඨ��
public:	//�ⲿ�ӿ�
	Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) { }	//���캯��
	friend Complex operator + (const Complex &c1, const Complex &c2);	//�����+����
	friend Complex operator - (const Complex &c1, const Complex &c2);	//�����-����
	friend ostream & operator << (ostream &out, const Complex &c);		//�����<<����
private:	//˽�����ݳ�Ա
	double real;	//����ʵ��
	double imag;	//�����鲿
};	

Complex operator + (const Complex &c1, const Complex &c2) {	//�������������ʵ��
	return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

Complex operator - (const Complex &c1, const Complex &c2) {	//�������������ʵ��
	return Complex(c1.real - c2.real, c1.imag - c2.imag);
}

ostream & operator << (ostream &out, const Complex &c) {	//�������������ʵ��
	out << "(" << c.real << ", " << c.imag << ")";
	return out;
}

int main() {	//������
	Complex c1(5, 4), c2(2, 10), c3;	//���帴����Ķ���
	cout << "c1 = " << c1 << endl;
	cout << "c2 = " << c2 << endl;
	c3 = c1 - c2;	//ʹ�������������ɸ�������
	cout << "c3 = c1 - c2 = " << c3 << endl;
	c3 = c1 + c2;	//ʹ�������������ɸ����ӷ�
	cout << "c3 = c1 + c2 = " << c3 << endl;
	return 0;
}
