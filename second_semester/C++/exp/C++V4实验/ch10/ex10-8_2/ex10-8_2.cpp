#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	string str;
	map<string, int> ismap;
	int i = 0;
	while (1) {
		cout << "�����ַ���: ";
		cin >> str;
		if (str == "QUIT")
			break;
		int counter = ismap.count(str);
		if (counter > 0)
			cout << str << "��ӳ�����������ֹ�" << counter << "��" << endl;
		else
			cout << str << "��ӳ����û�г��ֹ�" << endl;
		ismap.insert(map<string, int>::value_type(str, i));
		i ++;
	}
	return 0;
}
