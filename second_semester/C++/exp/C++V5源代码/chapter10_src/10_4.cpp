//10_4.cpp
#include <iostream>
#include <list>
#include <deque>
#include <iterator>
#include <algorithm>
using namespace std;

//���ָ��������˳��������Ԫ��
template <class T>
void printContainer(const char* msg, const T& s) {
	cout << msg << ": ";
	copy(s.begin(), s.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}

int main() {
	//�ӱ�׼�������10�������������Ƿֱ��s��ͷ������
	deque<int> s;
	for (int i = 0; i < 10; i++) {
		int x;
		cin >> x;
		s.push_front(x);
	}
	printContainer("deque at first", s);

	//��s���������ݵ��������б�����l
	list<int> l(s.rbegin(), s.rend());
	printContainer("list at first", l);

	//���б�����l��ÿ������������˳��ߵ�
	list<int>::iterator iter = l.begin();
	while (iter != l.end()) {
		int v = *iter;			//�õ�һ��Ԫ��
		iter = l.erase(iter);	//����Ԫ��ɾ�����õ�ָ����һ��Ԫ�صĵ�����
		l.insert(++iter, v);	//���ո�ɾ����Ԫ�ز�����һ��λ��
	}
	printContainer("list at last", l);

	//���б�����l�����ݸ�s��ֵ����s���
	s.assign(l.begin(), l.end());
	printContainer("deque at last", s);

	return 0;
}
