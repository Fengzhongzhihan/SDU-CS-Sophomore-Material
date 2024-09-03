#include <iostream>
#include <stack>
#include <queue>
using namespace std;


int main()
{
	int a[] = {5, 1, 4, 6};
	cout << "�������Ԫ�ص�ջ�Ĳ�����" << endl;
	stack<int> iStack;
	for (int i = 0; i < 4; i ++)
		iStack.push(a[i]);
	if (!iStack.empty()) {
		cout << "��һ��pop������ȡ����Ԫ���ǣ�" << iStack.top() << endl;
		iStack.pop();
	}
	if (!iStack.empty()) {
		cout << "�ڶ���pop������ȡ����Ԫ���ǣ�" << iStack.top() << endl;
		iStack.pop();
	}
	iStack.push(2);
	iStack.push(3);
	if (!iStack.empty()) {
		cout << "������pop������ȡ����Ԫ���ǣ�" << iStack.top() << endl;
		iStack.pop();
	}
	if (!iStack.empty()) {
		cout << "���Ĵ�pop������ȡ����Ԫ���ǣ�" << iStack.top() << endl;
		iStack.pop();
	}

	cout << "�������Ԫ�صĶ��еĲ�����" << endl;
	queue<int> iQueue;
	for (int i = 0; i < 4; i ++)
		iQueue.push(a[i]);
	if (!iQueue.empty()) {
		cout << "��һ��pop������ȡ����Ԫ���ǣ�" << iQueue.front() << endl;
		iQueue.pop();
	}
	if (!iQueue.empty()) {
		cout << "�ڶ���pop������ȡ����Ԫ���ǣ�" << iQueue.front() << endl;
		iQueue.pop();
	}
	iQueue.push(2);
	iQueue.push(3);
	if (!iQueue.empty()) {
		cout << "������pop������ȡ����Ԫ���ǣ�" << iQueue.front() << endl;
		iQueue.pop();
	}
	if (!iQueue.empty()) {
		cout << "���Ĵ�pop������ȡ����Ԫ���ǣ�" << iQueue.front() << endl;
		iQueue.pop();
	}

	cout << "�������Ԫ�ص����ȼ����еĲ�����" << endl;
	priority_queue<int> iPriQueue;
	for (int i = 0; i < 4; i ++)
		iPriQueue.push(a[i]);
	if (!iPriQueue.empty()) {
		cout << "��һ��pop������ȡ����Ԫ���ǣ�" << iPriQueue.top() << endl;
		iPriQueue.pop();
	}
	if (!iPriQueue.empty()) {
		cout << "�ڶ���pop������ȡ����Ԫ���ǣ�" << iPriQueue.top() << endl;
		iPriQueue.pop();
	}
	iPriQueue.push(2);
	iPriQueue.push(3);
	if (!iPriQueue.empty()) {
		cout << "������pop������ȡ����Ԫ���ǣ�" << iPriQueue.top() << endl;
		iPriQueue.pop();
	}
	if (!iPriQueue.empty()) {
		cout << "���Ĵ�pop������ȡ����Ԫ���ǣ�" << iPriQueue.top() << endl;
		iPriQueue.pop();
	}

	return 0;
}
