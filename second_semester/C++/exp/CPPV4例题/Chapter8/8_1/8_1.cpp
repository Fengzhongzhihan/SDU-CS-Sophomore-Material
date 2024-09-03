//8_1.cpp
#include <iostream>
using namespace std;

class Complex {	//�����ඨ��
public:	//�ⲿ�ӿ�
	Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) { }	//���캯��
	Complex operator + (const Complex &c2) const;	//�����+���س�Ա����
	Complex operator - (const Complex &c2) const;	//�����-���س�Ա����
	void display() const;	//�������
private:	//˽�����ݳ�Ա
	double real;	//����ʵ��
	double imag;	//�����鲿
};	

Complex Complex::operator + (const Complex &c2) const {	//�������������ʵ��
	return Complex(real + c2.real, imag + c2.imag); //����һ����ʱ����������Ϊ����ֵ
}

Complex Complex::operator - (const Complex &c2) const {	//�������������ʵ��
	return Complex(real - c2.real, imag - c2.imag); //����һ����ʱ����������Ϊ����ֵ
}

void Complex::display() const {
	cout << "(" << real << ", " << imag << ")" << endl;
}

int main() {	//������
	Complex c1(5, 4), c2(2, 10), c3;	//���帴����Ķ���
	cout << "c1 = "; c1.display();
	cout << "c2 = "; c2.display();
	c3 = c1 - c2;	//ʹ�������������ɸ�������
	cout << "c3 = c1 - c2 = "; c3.display();
	c3 = c1 + c2;	//ʹ�������������ɸ����ӷ�
	cout << "c3 = c1 + c2 = "; c3.display();
	return 0;
}
