//10_9.cpp
#include <set>
#include <iterator>
#include <utility>
#include <iostream>
using namespace std;

int main() {
	set<double> s;
	while (true) {
		double v;
		cin >> v;
		if (v == 0) break;	//����0��ʾ����
		pair<set<double>::iterator, bool> r = s.insert(v);	//���Խ�v����
		if (!r.second)		//���v�Ѵ��ڣ������ʾ��Ϣ
			cout << v << " is duplicated" << endl;
	}
	set<double>::iterator iter1 = s.begin();	//�õ���һ��Ԫ�صĵ�����
	set<double>::iterator iter2 = s.end();		//�õ�ĩβ�ĵ�����
	double medium = (*iter1 + *(--iter2)) / 2;	//�õ���С�����Ԫ�ص���ֵ
	//���С�ڻ������ֵ��Ԫ��
	cout << "<= medium: ";
	copy(s.begin(), s.upper_bound(medium), ostream_iterator<double>(cout, " "));
	cout << endl;
	//������ڻ������ֵ��Ԫ��
	cout << ">= medium: ";
	copy(s.lower_bound(medium), s.end(), ostream_iterator<double>(cout, " "));
	cout << endl;
	return 0;
}
