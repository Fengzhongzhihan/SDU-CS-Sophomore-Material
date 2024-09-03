//account.h
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__
#include "date.h"
#include "accumulator.h"
#include <string>

class Account { //�˻���
private:
	std::string id;	//�ʺ�
	double balance;	//���
	static double total; //�����˻����ܽ��
protected:
	//����������õĹ��캯����idΪ�˻�
	Account(const Date &date, const std::string &id);
	//��¼һ���ʣ�dateΪ���ڣ�amountΪ��descΪ˵��
	void record(const Date &date, double amount, const std::string &desc);
	//���������Ϣ
	void error(const std::string &msg) const;
public:
	const std::string &getId() const { return id; }
	double getBalance() const { return balance; }
	static double getTotal() { return total; }
	//��ʾ�˻���Ϣ
	void show() const;
};

class SavingsAccount : public Account { //�����˻���
private:
	Accumulator acc;	//����������Ϣ���ۼ���
	double rate;		//����������
public:
	//���캯��
	SavingsAccount(const Date &date, const std::string &id, double rate);
	double getRate() const { return rate; }
	//�����ֽ�
	void deposit(const Date &date, double amount, const std::string &desc);
	//ȡ���ֽ�
	void withdraw(const Date &date, double amount, const std::string &desc);
	//������Ϣ��ÿ��1��1�յ���һ�θú���
	void settle(const Date &date);
};

class CreditAccount : public Account { //�����˻���
private:
	Accumulator acc;	//����������Ϣ���ۼ���
	double credit;		//���ö��
	double rate;		//Ƿ���������
	double fee;			//���ÿ����

	double getDebt() const {	//���Ƿ���
		double balance = getBalance();
		return (balance < 0 ? balance : 0);
	}
public:
	//���캯��
	CreditAccount(const Date &date, const std::string &id, double credit, double rate, double fee);
	double getCredit() const { return credit; }
	double getRate() const { return rate; }
	double getFee() const { return fee; }
	double getAvailableCredit() const {	//��ÿ�������
		if (getBalance() < 0) 
			return credit + getBalance();
		else
			return credit;
	}
	//�����ֽ�
	void deposit(const Date &date, double amount, const std::string &desc);
	//ȡ���ֽ�
	void withdraw(const Date &date, double amount, const std::string &desc);
	//������Ϣ����ѣ�ÿ��1�յ���һ�θú���
	void settle(const Date &date);

	void show() const;
};

#endif //__ACCOUNT_H__
