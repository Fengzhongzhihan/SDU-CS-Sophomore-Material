//10_7.cpp
#include <stack>
#include <iostream>
#include <string>
using namespace std;

int main() {
	stack<char> s;
	string str;
	cin >> str;	//�Ӽ�������һ���ַ���

	//���ַ�����ÿ��Ԫ��˳��ѹ��ջ��
	for (string::iterator iter = str.begin(); iter != str.end(); ++iter)
		s.push(*iter);

	//��ջ�е�Ԫ��˳�򵯳������
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	cout << endl;

	return 0;
}
