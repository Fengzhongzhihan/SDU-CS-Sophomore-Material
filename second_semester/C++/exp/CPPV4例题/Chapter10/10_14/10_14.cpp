//10_14.cpp
#include <iostream>
#include <numeric>	//������ֵ�㷨ͷ�ļ�
using namespace std;

class MultClass	{  //����MultClass��
public:
	int operator() (int x, int y) const { return x * y; }	//���ز�����operator()
};

int main() {
	int a[] = { 1, 2, 3, 4, 5 };
	const int N = sizeof(a) / sizeof(int);
	cout << "The result by multipling all elements in a is "
		<< accumulate(a, a + N, 1, MultClass())	//����multclass���ݸ�ͨ���㷨
		<< endl;
	return 0;
}
