//4_9.cpp
#include <iostream>
#include <cmath>
using namespace std;

class SavingsAccount { //�����˻���
private:
	int id;				//�˺�
	double balance;		//���
	double rate;		//����������
	int lastDate;		//�ϴα������ʱ��
	double accumulation;	//�����ۼ�֮��

	//��¼һ���ʣ�dateΪ���ڣ�amountΪ��descΪ˵��
	void record(int date, double amount);
	//��õ�ָ������Ϊֹ�Ĵ������ۻ�ֵ
	double accumulate(int date) const {
		return accumulation + balance * (date - lastDate);
	}
public:
	//���캯��
	SavingsAccount(int date, int id, double rate);
	int getId() { return id; }
	double getBalance() { return balance; }
	double getRate() { return rate; }

	//�����ֽ�
	void deposit(int date, double amount);
	//ȡ���ֽ�
	void withdraw(int date, double amount);
	//������Ϣ��ÿ��1��1�յ���һ�θú���
	void settle(int date);
	//��ʾ�˻���Ϣ
	void show();
};

//SavingsAccount����س�Ա������ʵ��
SavingsAccount::SavingsAccount(int date, int id, double rate)
	: id(id), balance(0), rate(rate), lastDate(date), accumulation(0) {
	cout << date << "\t#" << id << " is created" << endl;
}

void SavingsAccount::record(int date, double amount) {
	accumulation = accumulate(date);
	lastDate = date;
	amount = floor(amount * 100 + 0.5) / 100;	//����С�������λ
	balance += amount;
	cout << date << "\t#" << id << "\t" << amount << "\t" << balance << endl;
}

void SavingsAccount::deposit(int date, double amount) {
	record(date, amount);
}

void SavingsAccount::withdraw(int date, double amount) {
	if (amount > getBalance())
		cout << "Error: not enough money" << endl;
	else
		record(date, -amount);
}

void SavingsAccount::settle(int date) {
	double interest = accumulate(date) * rate / 365;	//������Ϣ
	if (interest != 0)
		record(date, interest);
	accumulation = 0;
}

void SavingsAccount::show() {
	cout << "#" << id << "\tBalance: " << balance;
}

int main() {
	//���������˻�
	SavingsAccount sa0(1, 21325302, 0.015);
	SavingsAccount sa1(1, 58320212, 0.015);

	//������Ŀ
	sa0.deposit(5, 5000);
	sa1.deposit(25, 10000);
	sa0.deposit(45, 5500);
	sa1.withdraw(60, 4000);

	//�������90�쵽�����еļ�Ϣ�գ����������˻�����Ϣ
	sa0.settle(90);
	sa1.settle(90);

	//��������˻���Ϣ
	sa0.show();	cout << endl;
	sa1.show();	cout << endl;
	return 0;
}
