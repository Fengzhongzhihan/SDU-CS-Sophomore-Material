#include <iostream>
#include "link.h"  //�μ�"ʵ��9"����
using namespace std;


template <class T>
class Link : public LinkedList<T>
{
public:
	void insertOrder(const T& item);
};

template <class T>
void Link<T>::insertOrder(const T& item)
{
    Link<T>::reset();
    while (!Link<T>::endOfList()) {
		if (item < Link<T>::data())
			break;
		Link<T>::next();
    }   
    insertAt(item);
}

int main()
{
	Link<int> A, B;
    int i, item;
	
    cout << "�������������A�����������";
	for (i = 0; i < 5; i ++) {
		cin >> item;
		A.insertOrder(item);
	}
	cout << "�������������B�����������";
	for (i = 0; i < 5; i ++) {
		cin >> item;
		B.insertOrder(item);
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
		A.insertOrder(B.data());
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
