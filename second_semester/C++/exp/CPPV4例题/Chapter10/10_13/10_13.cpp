//10_13.cpp
#include <iostream>   
#include <numeric>	//������ֵ�㷨ͷ�ļ�
using namespace std;

int mult(int x, int y) { return x * y; };	//����һ����ͨ����
int main() {
	int a[] = { 1, 2, 3, 4, 5 };
	const int N = sizeof(a) / sizeof(int);
	cout << "The result by multipling all elements in a is "
		<< accumulate(a, a + N, 1, mult)	//����ͨ����mult���ݸ�ͨ���㷨
		<< endl;
	return 0;
}
