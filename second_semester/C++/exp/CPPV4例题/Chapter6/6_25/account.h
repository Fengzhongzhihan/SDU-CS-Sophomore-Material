//account.h
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__
#include "date.h"
#include <string>

class SavingsAccount { //�����˻���
private:
	std::string id;		//�ʺ�
	double balance;		//���
	double rate;		//����������
	Date lastDate;		//�ϴα������ʱ��
	double accumulation;	//�����ۼ�֮��
	static double total;	//�����˻����ܽ��

	//��¼һ���ʣ�dateΪ���ڣ�amountΪ��descΪ˵��
	void record(const Date &date, double amount, const std::string &desc);
	//���������Ϣ
	void error(const std::string &msg) const;
	//��õ�ָ������Ϊֹ�Ĵ������ۻ�ֵ
	double accumulate(const Date& date) const {
		return accumulation + balance * date.distance(lastDate);
	}
public:
	//���캯��
	SavingsAccount(const Date &date, const std::string &id, double rate);
	const std::string &getId() const { return id; }
	double getBalance() const { return balance; }
	double getRate() const { return rate; }
	static double getTotal() { return total; }

	//�����ֽ�
	void deposit(const Date &date, double amount, const std::string &desc);
	//ȡ���ֽ�
	void withdraw(const Date &date, double amount, const std::string &desc);
	//������Ϣ��ÿ��1��1�յ���һ�θú���
	void settle(const Date &date);
	//��ʾ�˻���Ϣ
	void show() const;
};

#endif //__ACCOUNT_H__
