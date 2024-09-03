//9_4.cpp
#include <iostream>
#include <iomanip>
#include "Array.h"
using namespace std;

int main() {
	Array<int> a(10);	// ����������������飬��ʼ״̬��10��Ԫ�ء�
	int count = 0;

	int n;
	cout << "Enter a value >= 2 as upper limit for prime numbers: ";
	cin >> n;

	for (int i = 2; i <= n; i++) {
		//���i�Ƿ��ܱ�����С����������
		bool isPrime = true;
		for (int j = 0; j < count; j++)
			if (i % a[j] == 0) {	//��i��a[j]������˵��i��������
				isPrime = false;
				break;
			}

		//��iд����������
		if (isPrime) {
			//������������ˣ�����ռ�ӱ�
			if (count == a.getSize())
				a.resize(count * 2);
			a[count++] = i;
		}
	}

	for (int i = 0; i < count; i++)	//�������
		cout << setw(8) << a[i];
	cout << endl;

	return 0;
}
