#include <iostream>
using namespace std;

void swap(int& a, int&b) {
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int **a;
	a = new int*[3];
	for (int i = 0; i < 3; i ++)
		a[i] = new int[3];
	cout << "����9��������Ϊ����Ԫ��ֵ" << endl;
	for (int i = 0; i < 3; i ++)
		for (int j = 0; j < 3; j ++)
			cin >> a[i][j];
	cout << "��ʼ����" << endl;
	for (int i = 0; i < 3; i ++) {
		for (int j = 0; j < 3; j ++)
			cout << a[i][j] << ' ';
		cout << endl;
	}
	for (int i = 0; i < 3; i ++)
		for (int j = 0; j < i; j ++)
			swap(a[i][j], a[j][i]);

	for (int i = 0; i < 3; i ++) {
		for (int j = 0; j < 3; j ++)
			cout << a[i][j] << ' ';
		cout << endl;
	}
	return 0;
}
