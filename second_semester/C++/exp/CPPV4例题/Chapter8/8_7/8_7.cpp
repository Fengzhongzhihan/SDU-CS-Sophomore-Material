//8_7.cpp  �ļ�����������
#include "Trapzint.h"	//�ඨ��ͷ�ļ�
#include <iostream>
#include <iomanip>
using namespace std;

int main() {	//������
	MyFunction f;		//����MyFunction��Ķ���
	Trapz trapz(f);	//����Trapz��Ķ���
	//���㲢������ֽ��
	cout << "TRAPZ Int: " << setprecision(7) << trapz(0, 2, 1e-7) << endl;	
	return 0;
}
