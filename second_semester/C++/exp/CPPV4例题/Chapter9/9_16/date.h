//date.h
#ifndef __DATE_H__
#define __DATE_H__

class Date {	//������
private:
	int year;		//��
	int month;		//��
	int day;		//��
	int totalDays;	//�������Ǵӹ�ԪԪ��1��1�տ�ʼ�ĵڼ���

public:
	Date(int year, int month, int day);	//���ꡢ�¡��չ�������
	int getYear() const { return year; }
	int getMonth() const { return month; }
	int getDay() const { return day; }
	int getMaxDay() const;		//��õ����ж�����
	bool isLeapYear() const {	//�жϵ����Ƿ�Ϊ����
		return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	}
	void show() const;			//�����ǰ����
	//������������֮��������	
	int operator - (const Date& date) const {
		return totalDays - date.totalDays;
	}
};

#endif //__DATE_H__
