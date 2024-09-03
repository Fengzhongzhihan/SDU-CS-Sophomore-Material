#include <string>
#include <iostream>
using namespace std;
//���������������� M 
	union M {
		char grade;		//�ȼ��Ƶĳɼ�
		bool pass;		//�Ƿ�ͨ��
		int percent;	//�ٷ��Ƶĳɼ�
		M(){ }
		M(char c){ grade =c;	}
		M(bool b){ pass =b;	}
		M(int i){ percent =i;	}
		char gett(){ return t;
		}
	    private:  //������˽�г�Ա 
			char t;
	} ;
	
class ExamInfo {
public:
	//���ֹ��캯�����ֱ��õȼ����Ƿ�ͨ���Ͱٷ�����ʼ��
	ExamInfo(string name, union M w) 
		: name(name), mode(GRADE), m(w){ } 

	void show();

private:
	string name;	//�γ�����
	enum {
		GRADE,
		PASS,
		PERCENTAGE
	} mode;			//���ú��ּƷַ�ʽ
    union M m;
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
