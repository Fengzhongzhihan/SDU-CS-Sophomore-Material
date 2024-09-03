#include <iostream>
#include <string>
#include <utility>
#include <boost/unordered_map.hpp>
using namespace std;
using namespace boost;

int main() {
	unordered_map<string, int> courses;
	//���γ���Ϣ����coursesӳ����
	courses.insert(make_pair("CSAPP", 3));
	courses.insert(make_pair("C++", 2));
	courses.insert(make_pair("CSARCH", 4));
	courses.insert(make_pair("COMPILER", 4));
	courses.insert(make_pair("OS", 5));

	int n = 3; //ʣ�µĿ�ѡ����
	int sum = 0; //ѧ���ܺ�
	while (n > 0) {
		string name;
		cin >> name; //����γ�����
		unordered_map<string, int>::iterator iter = courses.find(name);//���ҿγ�
		if (iter == courses.end()) { //�ж��Ƿ��ҵ�
			cout << name << " is not available" << endl;
		} else {
			sum += iter->second; //�ۼ�ѧ��
			courses.erase(iter); //����ѡ���Ŀγ̴�ӳ����ɾ��
			n--;
		}
	}

	cout << "Total credit: " << sum << endl; //�����ѧ��
	return 0;
}
