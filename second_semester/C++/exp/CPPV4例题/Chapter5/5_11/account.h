//account.h
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class SavingsAccount { //�����˻���
private:
	int id;				//�˺�
	double balance;		//���
	double rate;		//����������
	int lastDate;		//�ϴα������ʱ��
	double accumulation;	//�����ۼ�֮��
	static double total;	//�����˻����ܽ��

	//��¼һ���ʣ�dateΪ���ڣ�amountΪ��descΪ˵��
	void record(int date, double amount);
	//��õ�ָ������Ϊֹ�Ĵ������ۻ�ֵ
	double accumulate(int date) const {
		return accumulation + balance * (date - lastDate);
	}
public:
	//���캯��
	SavingsAccount(int date, int id, double rate);
	int getId() const { return id; }
	double getBalance() const { return balance; }
	double getRate() const { return rate; }
	static double getTotal() { return total; }

	//�����ֽ�
	void deposit(int date, double amount);
	//ȡ���ֽ�
	void withdraw(int date, double amount);
	//������Ϣ��ÿ��1��1�յ���һ�θú���
	void settle(int date);
	//��ʾ�˻���Ϣ
	void show() const;
};

#endif //__ACCOUNT_H__
