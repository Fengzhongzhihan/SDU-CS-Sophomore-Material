//6_6.cpp
#include <iostream>
using namespace std;

int main() {
//!	void voidObject;	//����������void���͵ı���
	void *pv;	//�ԣ���������void���͵�ָ��
	int i = 5;
	pv = &i;	//void����ָ��ָ�����ͱ���
	int *pint = static_cast<int *>(pv);	//void����ָ�븳ֵ��int����ָ��
	cout << "*pint = " << *pint << endl;
	return 0;
} 
