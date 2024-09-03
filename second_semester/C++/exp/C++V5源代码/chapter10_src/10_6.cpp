//10_6.cpp
#include <list>
#include <iterator>
#include <string>
#include <iostream>
using namespace std;

int main() {
	string names1[] = { "Alice", "Helen", "Lucy", "Susan" };
	string names2[] = { "Bob", "David", "Levin", "Mike" };
	list<string> s1(names1, names1 + 4); //��names1��������ݹ����б�s1
	list<string> s2(names2, names2 + 4); //��names2��������ݹ����б�s2

	//��s1�ĵ�һ��Ԫ�طŵ�s2�����
	s2.splice(s2.end(), s1, s1.begin());
	list<string>::iterator iter1 = s1.begin(); //iter1ָ��s1��
	advance(iter1, 2); //iter1ǰ��2��Ԫ�أ�����ָ��s1��3��Ԫ��
	list<string>::iterator iter2 = s2.begin();  //iter2ָ��s2��
	++iter2; //iter2ǰ��1��Ԫ�أ�����ָ��s2��2��Ԫ��
	list<string>::iterator iter3 = iter2; //��iter2��ʼ��iter3
	advance(iter3, 2); //iter3ǰ��2��Ԫ�أ�����ָ��s2��4��Ԫ��
	//��[iter2, iter3)��Χ�ڵĽ��ӵ�s1��iter1ָ��Ľ��ǰ
	s1.splice(iter1, s2, iter2, iter3); 

	//�ֱ�s1��s2���
	copy(s1.begin(), s1.end(), ostream_iterator<string>(cout, " "));
	cout << endl;
	copy(s2.begin(), s2.end(), ostream_iterator<string>(cout, " "));
	cout << endl;
	return 0;
}
