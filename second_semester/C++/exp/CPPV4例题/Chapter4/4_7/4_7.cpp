//4_7.cpp
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Student {	//ѧ����Ϣ�ṹ��
	int num;		//ѧ��
	string name;	//����
	char sex;		//�Ա�
	int age;		//����
};

int main() {
	Student stu = { 97001, "Lin Lin", 'F', 19 };
	cout << "Num:  " << stu.num << endl;
	cout << "Name: " << stu.name << endl;
	cout << "Sex:  " << stu.sex << endl;
	cout << "Age:  " << stu.age << endl;
	return 0;
}
