//9_1.cpp
#include <iostream>
using namespace std;

template <class T>	//���庯��ģ��
void outputArray(const T *array, int count) {
	for (int i = 0; i < count; i++)
		cout << array[i] << " ";
	cout << endl;
}	

int main() {	 //������
	const int A_COUNT = 8, B_COUNT = 8, C_COUNT = 20;
	int a [A_COUNT] = { 1, 2, 3, 4, 5, 6, 7, 8 };	//����int����
	double b[B_COUNT] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8 }; //����double����
	char c[C_COUNT] = "Welcome to see you!";	//����char����

	cout << " a array contains:" << endl;
	outputArray(a, A_COUNT);	//���ú���ģ��
	cout << " b array contains:" << endl;
	outputArray(b, B_COUNT);	//���ú���ģ��
	cout << " c array contains:" << endl;
	outputArray(c, C_COUNT);	//���ú���ģ��

	return 0;
}
