//6_5.cpp
#include <iostream>
using namespace std;
int main() {
	int i;			//����int����i
	int *ptr = &i;	//ȡi�ĵ�ַ����ptr
	i = 10;			//int��������ֵ
	cout << "i = " << i << endl;			//���int������ֵ
	cout << "*ptr = " << *ptr << endl;	//���int��ָ����ָ��ַ������
	return 0;
}
