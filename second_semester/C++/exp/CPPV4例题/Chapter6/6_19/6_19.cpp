//6_19.cpp
#include <iostream>
using namespace std;
int main() {
	float (*cp)[9][8] = new float[8][9][8];

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 9; j++)
			for (int k = 0; k < 8; k++)
				//��ָ����ʽ����Ԫ��
				*(*(*(cp + i) + j) + k) = static_cast<float>(i * 100 + j * 10 + k);

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 9; j++) {
			for (int k = 0; k < 8; k++)
				//��ָ��cp��Ϊ������ʹ�ã�ͨ�����������±��������Ԫ��
				cout << cp[i][j][k] << "  ";
			cout << endl;
		}
		cout << endl;
	}

	delete[] cp;
	return 0;
}
