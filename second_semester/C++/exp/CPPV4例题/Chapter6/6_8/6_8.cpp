//6_8.cpp
#include <iostream>
using namespace std;

int main() {
	int line1[] = { 1, 0, 0 };	//�������飬����ĵ�һ��
	int line2[] = { 0, 1, 0 };	//�������飬����ĵڶ���
	int line3[] = { 0, 0, 1 };	//�������飬����ĵ�����
	
	//��������ָ�����鲢��ʼ��
	int *pLine[3] = { line1, line2, line3 };	
	
	cout << "Matrix test:" << endl;	//�����λ����
	for (int i = 0; i < 3; i++) {	//��ָ������Ԫ��ѭ��
		for (int j = 0; j < 3; j++) 	//�Ծ���ÿһ��ѭ��
			cout << pLine[i][j] << " ";
		cout << endl;
	}
	return 0;
}
