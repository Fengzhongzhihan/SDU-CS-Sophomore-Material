//5_2.cpp
#include <iostream>
using namespace std;
int i = 1;	// i Ϊȫ�ֱ��������о�̬������

void other() {
	//a, bΪ��̬�ֲ�����������ȫ���������ֲ��ɼ���ֻ��һ�ν��뺯��ʱ����ʼ��
	static int a = 2;
	static int b;
	//cΪ�ֲ����������ж�̬�����ڣ�ÿ�ν��뺯��ʱ����ʼ��
	int c = 10;
	a += 2;
	i += 32;
	c += 5;
	cout << "---OTHER---" << endl;
	cout << " i: " << i << " a: " << a << " b: " << b << " c: " << c << endl;
	b = a;
}

int main() {
	//aΪ��̬�ֲ�����������ȫ���������ֲ��ɼ�
	static int a;
	//b, cΪ�ֲ����������ж�̬������
	int b = -10;	
	int c = 0;

	cout << "---MAIN---" << endl;
	cout << " i: " << i << " a: " << a << " b: " << b << " c: " << c << endl;
	c += 8;
	other();
	cout << "---MAIN---" << endl;
	cout << " i: " << i << " a: " << a << " b: " << b << " c: " << c << endl;
	i += 10;
	other();
	return 0;
}
