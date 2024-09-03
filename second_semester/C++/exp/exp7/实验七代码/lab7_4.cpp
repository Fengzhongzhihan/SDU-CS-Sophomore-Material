#include <iostream>
#include <cstring>
using namespace std;

class Date
{
public:
	int year;
	int month;
	int day;
	Date() {year = 1900; month = 1; day = 1;}
	Date(int y, int m, int d) : year(y), month(m), day(d) {}
//	Date(const Date& b) {year = b.year; month = b.month; day = b.day;}
};

class people
{
	char name[11];
	char number[7];
	char sex[3];
	Date birth;
	char id[16];
public:
	char* getName() {return name;}
	char* getNumber() {return number;}
	char* getSex() {return sex;}
	Date getBirth() {return birth;}
	char* getId() {return id;}
	people() {}
	people(char* nm, char* no, char* gd, Date b, char* i) : birth(b) {
		strcpy(name, nm);
		strcpy(number, no);
		strcpy(sex, gd);
		strcpy(id, i);
	}
};

class teacher : virtual public people
{
	char principalship[11];
	char department[21];
public:
	char* getPs() {return principalship;}
	char* getDpm() {return department;}
	teacher() {}
	teacher(char* ps, char* dpm) {
		strcpy(principalship, ps);
		strcpy(department, dpm);
	}
	teacher(char* nm, char* no, char* gd, Date b, char* i, char* ps, char* dpm) : people(nm, no, gd, b, i) {
		strcpy(principalship, ps);
		strcpy(department, dpm);
	}
};

class student : virtual public people
{
	char classNO[7];
public:
	char* getClassNO() {return classNO;}
	student() {}
	student(char* cln) {strcpy(classNO, cln);}
	student(char* nm, char* no, char* gd, Date b, char* i, char* cln) : people(nm, no, gd, b, i) {
		strcpy(classNO, cln);
	}
};

class graduate : public student
{
	char subject[21];
	teacher adviser;
public:
	char* getSubject() {return subject;}
	teacher getAdviser() {return adviser;}
	graduate() {}
	graduate(char* sbj, teacher adv) : adviser(adv) {strcpy(subject, sbj);}
	graduate(char* cln, char* sbj, teacher adv) : student(cln), adviser(adv) {strcpy(subject, sbj);}
	graduate(char* nm, char* no, char* gd, Date b, char* i, char* cln, char* sbj, teacher adv) : student(nm, no, gd, b, i, cln), adviser(adv) {strcpy(subject, sbj);}
};

class TA : public graduate, public teacher
{
public:
	TA() {}
	TA(char* nm, char* no, char* gd, Date b, char* i, char* ps, char* dpm, char* cln, char* sbj, teacher adv) : people(nm, no, gd, b, i), teacher(ps, dpm), graduate(cln, sbj, adv) {}
};

int main()
{
	teacher ad("Zheng Li", "1001", "Female", Date(1978, 1, 1), "1234567890", "professor", "CST");
	TA ta("Li Chao", "011401", "Male", Date(1988, 06, 01), "12345619880601", "TA", "CST", "cst61", "computer science", ad);
	cout << "TA name: " << ta.getName() << endl;
	cout << "No.: " << ta.getNumber() << endl;
	cout << "Department: " << ta.getDpm() << endl;
	cout << "Class No.: " << ta.getClassNO() << endl;
	cout << "Subject: " << ta.getSubject() << endl;
	cout << "Advisor: " << ad.getName() << endl;
	return 0;
}
