//6_10.cpp
#include <iostream>
using namespace std;

//��ʵ��x�ֳ��������ֺ�С�����֣��β�intpart��fracpart��ָ��
void splitFloat(float x, int *intPart, float *fracPart) {
	*intPart = static_cast<int>(x);	//ȡx����������
	*fracPart = x - *intPart;		//ȡx��С������
}

int main() {
	cout << "Enter 3 float point numbers:" << endl;
	for(int i = 0; i < 3; i++) {
		float x, f;
		int n;
		cin >> x;
		splitFloat(x, &n, &f);	//������ַ��Ϊʵ��
		cout << "Integer Part = " << n << " Fraction Part = " << f << endl;
	}
	return 0;
}
