//10_10.cpp
#include <iostream>
#include <map>
#include <string>
#include <utility>
using namespace std;

int main() {
	map<string, int> courses;
	//���γ���Ϣ����coursesӳ����
	courses.insert(make_pair("CSAPP", 3));
	courses.insert(make_pair("C++", 2));
	courses.insert(make_pair("CSARCH", 4));
	courses.insert(make_pair("COMPILER", 4));
	courses.insert(make_pair("OS", 5));

	int n = 3;		//ʣ�µĿ�ѡ����
	int sum = 0;	//ѧ���ܺ�
	while (n > 0) {
		string name;
		cin >> name;	//����γ�����
		map<string, int>::iterator iter = courses.find(name);//���ҿγ�
		if (iter == courses.end()) {	//�ж��Ƿ��ҵ�
			cout << name << " is not available" << endl;
		} else {
			sum += iter->second;	//�ۼ�ѧ��
			courses.erase(iter);	//����ѡ���Ŀγ̴�ӳ����ɾ��
			n--;
		}
	}

	cout << "Total credit: " << sum << endl;	//�����ѧ��
	return 0;
}
