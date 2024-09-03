#include <string>
#include <iostream>
using namespace std;

class ExamInfo {
public:
	//���ֹ��캯�����ֱ��õȼ����Ƿ�ͨ���Ͱٷ�����ʼ��
	ExamInfo(string name, char grade)
		: name(name), mode(GRADE), grade(grade) { }
	ExamInfo(string name, bool pass)
		: name(name), mode(PASS), pass(pass) { }
	ExamInfo(string name, int percent)
		: name(name), mode(PERCENTAGE), percent(percent) { }
	void show();

private:
	string name;	//�γ�����
	enum {
		GRADE,
		PASS,
		PERCENTAGE
	} mode;			//���ú��ּƷַ�ʽ
	union {
		char grade;		//�ȼ��Ƶĳɼ�
		bool pass;		//�Ƿ�ͨ��
		int percent;	//�ٷ��Ƶĳɼ�
	};
};

void ExamInfo::show() {
	cout << name << ": ";
	switch (mode) {
	case GRADE:
		cout << grade;
		break;
	case PASS:
		cout << (pass ? "PASS" : "FAIL");
		break;
	case PERCENTAGE:
		cout << percent;
		break;
	}
	cout << endl;
}

int main() {
	ExamInfo course1("English", 'B');
	ExamInfo course2("Calculus", true);
	ExamInfo course3("C++ Programming", 85);
	course1.show();
	course2.show();
	course3.show();
	return 0;
}
