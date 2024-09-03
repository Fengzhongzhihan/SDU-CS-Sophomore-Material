#include <string>
#include <iostream>
using namespace std;
//独立的有名联合体 M 
	union M {
		char grade;		//等级制的成绩
		bool pass;		//是否通过
		int percent;	//百分制的成绩
		M(){ }
		M(char c){ grade =c;	}
		M(bool b){ pass =b;	}
		M(int i){ percent =i;	}
		char gett(){ return t;
		}
	    private:  //可以有私有成员 
			char t;
	} ;
	
class ExamInfo {
public:
	//三种构造函数，分别用等级、是否通过和百分来初始化
	ExamInfo(string name, union M w) 
		: name(name), mode(GRADE), m(w){ } 

	void show();

private:
	string name;	//课程名称
	enum {
		GRADE,
		PASS,
		PERCENTAGE
	} mode;			//采用何种计分方式
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
