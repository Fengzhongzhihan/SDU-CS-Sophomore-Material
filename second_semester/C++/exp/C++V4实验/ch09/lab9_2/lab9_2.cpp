#include <iostream>
#include "link.h"
using namespace std;

int main()
{
	LinkedList<int> A, B;
    int i, item;
	
    cout << "�������������A�����������";
	for (i = 0; i < 5; i ++) {
		cin >> item;
		A.insertRear(item);
	}
	cout << "�������������B�����������";
	for (i = 0; i < 5; i ++) {
		cin >> item;
		B.insertRear(item);
	}
	cout << endl << "��������A�е�Ԫ��Ϊ��";
	A.reset();
	while(!A.endOfList()) {
		cout << A.data() << "  ";
		A.next();
	}
	cout << endl << "��������B�е�Ԫ��Ϊ��";
	B.reset();
	while(!B.endOfList()) {
		A.insertRear(B.data());
		cout << B.data() << "  ";
		B.next();
	}
	
	cout << endl << "��������B��Ԫ�غ�����A�е�Ԫ��Ϊ��";
	A.reset();
	while(!A.endOfList()) {
		cout << A.data() << "  ";
		A.next();    
	}
	cout << endl;
	return 0;
}
