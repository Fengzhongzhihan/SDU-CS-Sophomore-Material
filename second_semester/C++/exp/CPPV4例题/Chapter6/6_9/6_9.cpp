//6_9.cpp
#include <iostream>
using namespace std;

int main() {
	int array2[3][3]= { { 11, 12, 13 }, { 21, 22, 23 }, { 31, 32, 33 } };
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++)
			cout << *(*(array2 + i) + j) << " ";	//��������ά�����i��Ԫ��ֵ
		cout << endl;
	}
	return 0;
}
