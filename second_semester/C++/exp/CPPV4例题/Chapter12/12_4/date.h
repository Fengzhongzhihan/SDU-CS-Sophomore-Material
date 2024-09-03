//date.h
#ifndef __DATE_H__
#define __DATE_H__
#include <iostream>

class Date {	//������
private:
	int year;		//��
	int month;		//��
	int day;		//��
	int totalDays;	//�������Ǵӹ�ԪԪ��1��1�տ�ʼ�ĵڼ���

public:
	Date(int year = 1, int month = 1, int day = 1);	//���ꡢ�¡��չ�������
	int getYear() const { return year; }
	int getMonth() const { return month; }
	int getDay() const { return day; }
	int getMaxDay() const;		//��õ����ж�����
	bool isLeapYear() const {	//�жϵ����Ƿ�Ϊ����
		return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	}
	//������������֮��������	
	int operator - (const Date& date) const {
		return totalDays - date.totalDays;
	}
	//�ж��������ڵ�ǰ��˳��
	bool operator < (const Date& date) const {
		return totalDays < date.totalDays;
	}
};

std::istream & operator >> (std::istream &in, Date &date);
std::ostream & operator << (std::ostream &out, const Date &date);
#endif //__DATE_H__
