//2_9.cpp
#include <iostream>
using namespace std;

int main() {
	const int N = 4;
	for (int i = 1; i <= N; i++) {	//���ǰ4��ͼ��
		for (int j = 1; j <= 30; j++)
			cout << ' ';	//��ͼ������30��
		for (int j = 1; j <= 8 - 2 * i; j++)
			cout << ' ';
		for (int j = 1; j <= 2 * i - 1; j++)
			cout << '*';
		cout << endl;
	}
	for (int i = 1; i <= N - 1; i++) {	//�����3��ͼ��
		for (int j = 1; j <= 30; j++)
			cout << ' ';	//��ͼ������30��
		for (int j = 1; j <= 7 - 2 * i ;j++)
			cout << '*';
		cout << endl;
	}
	return 0;
}
