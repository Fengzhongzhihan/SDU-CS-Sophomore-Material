//2_12.cpp
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Student {	//ѧ����Ϣ�ṹ��
	int num;		//ѧ��
	string name;	//����
	char sex;		//�Ա�
	int age;		//����
} stu = { 97001, "Lin Lin", 'F', 19};

int main() {
	cout << setw(7) << stu.num;
	cout << setw(20) << stu.name;
	cout << setw(3) << stu.sex;
	cout << setw(3) << stu.age;
	cout << endl;
	return 0;
}
