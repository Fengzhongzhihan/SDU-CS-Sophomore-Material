//3_1.cpp
#include <iostream>
using namespace std;

//����x��n�η�
double power(double x, int n) {
	double val = 1.0;
	while (n--)
		val *= x;
	return val;
}

int main() {
	cout <<  "5 to the power 2 is " << power(5, 2) << endl; 
	//����������Ϊһ�����ʽ�������������С�
	return 0;
}
