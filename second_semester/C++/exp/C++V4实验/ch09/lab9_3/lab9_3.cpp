#include <iostream>
#include "queue.h"
using namespace std;

int main()
{
	int item;
	Queue<int> q;
	cout << "����5��Ҫ�����Ԫ��" << endl;
	for (int i = 0; i < 5; i ++) {
		cin >> item;
		q.push(item);
	}
	for (int i = 0; i < 5; i ++)
		cout << "ȡ��Ԫ��" << q.pop() << endl;
	return 0;
}