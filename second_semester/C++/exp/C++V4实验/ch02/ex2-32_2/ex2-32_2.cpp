//ʹ��do��while���
#include <iostream>
using namespace std ;

int main() {
	int n = 18;
	int m = 0;
	do{
		cout << "����������ֵΪ���٣�(0~~100):";
		cin >> m;
		if (n > m)
			cout << "��µ�ֵ̫С�ˣ�" << endl;
		else if (n < m)
			cout << "��µ�ֵ̫���ˣ�" << endl;
		else
			cout << "��¶��ˣ�" << endl;
	}while(n != m);
	return 0;
} 
