#include <iostream>
using namespace std;

float ftoc(int f) {
	return (f-32)*5.0/9;
}

int main()
{
	cout << "���뻪�϶�ֵ��" << endl;
	int f;
	cin >> f;
	cout << "��Ӧ���϶�ֵΪ" << ftoc(f) << endl;
	
	return 0;
}