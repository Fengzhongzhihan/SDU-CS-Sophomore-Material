#include <string>
#include <iostream>
using namespace std;

class ExamInfo {
public:
	//���ֹ��캯�����ֱ��õȼ����Ƿ�ͨ���Ͱٷ�����ʼ��
	ExamInfo(string name, char grade)
		: name(name), mode(GRADE){ m.grade=grade;}  
	ExamInfo(string name, bool pass)
		: name(name), mode(PASS) { m.pass=pass;}  
	ExamInfo(string name, int percent)
		: name(name), mode(PERCENTAGE) {m.percent=percent; }  
	void show();

private:
	string name;	//�γ�����
	enum {
		GRADE,
		PASS,
		PERCENTAGE
	} mode;			//���ú��ּƷַ�ʽ
	
//�����������������б����� 
	union  {
		char grade;		//�ȼ��Ƶĳɼ�
		bool pass;		//�Ƿ�ͨ��
		int percent;	//�ٷ��Ƶĳɼ�
		} m;
};

void ExamInfo::show() {
	cout << name << ": ";
	switch (mode) {
	case GRADE:
		cout << m.grade;
		break;
	case PASS:
		cout << (m.pass ? "PASS" : "FAIL");
		break;
	case PERCENTAGE:
		cout << m.percent;
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
