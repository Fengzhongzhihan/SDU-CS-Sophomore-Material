#include<iostream>
#include<cmath>
using namespace std;

class SavingAccount
{
private:
	int id;                 //账户名
	double balance;         //余额
	double rate;            //年利率
	int lastDate;                            //上次算过利息的最后一天
	double accumulation;
	void record(int date, double amount);    //指定天数的总金额
	double accumulate(int date) const        //accumulation是用来算利息的
	{
		return accumulation + balance * (date - lastDate);           
	}
public :
	SavingAccount(int date, int id, double rate);
	int getId()
	{
		return id;
	}
	double getBalance()
	{
		return balance;
	}
	double getRate()
	{
		return rate;
	}
	void deposit(int date, double amount);
	void withdraw(int date, double amount);
	void settle(int date);
	void show();
};

SavingAccount::SavingAccount(int date, int id, double rate)                //构造函数初始化账户
	:id(id), balance(0), rate(rate), lastDate(date), accumulation(0)
{
	cout << date << "\t #" << id << "\t"<<"is created" << endl;

}

void SavingAccount::record(int date, double amount)   //amount最终实际上是主函数传进来的。record函数起一个变更当前存款的作用
{
	accumulation = accumulate(date);
	lastDate = date;
	amount = floor(amount * 100 + 0.5) / 100;         //四舍五入
	balance += amount;
	cout << date << "\t #" << id << "\t" << amount << "\t" << balance << endl;
}

void SavingAccount::deposit(int date, double amount)
{
	record(date, amount);
}

void SavingAccount::withdraw(int date, double amount)
{
	if (amount > getBalance())
		cout << "Error:not enough money" << endl;
	else
		record(date, -amount);
}

void SavingAccount::settle(int date)
{
	double interest = accumulate(date)*rate / 365;        //按日来结算
	if (interest != 0)
		record(date, interest);
	accumulation = 0;
}

void SavingAccount::show()
{
	cout << "#" << id << "\tBalance:" << balance<<endl;
}

int main()
{
	SavingAccount zhanghu0(1, 100000, 0.015);             //创建两个账户，年利率百分之1.5
	SavingAccount zhanghu1(1, 111111, 0.015); 
	
	zhanghu0.deposit(5, 5000);                      //第五天存进5000
	zhanghu1.deposit(25, 10000);
	zhanghu0.deposit(45, 5500);
	zhanghu1.withdraw(60, 4000);                     //第60天取出4000
	zhanghu0.settle(90);                  //第90天结算
	zhanghu1.settle(90);
	zhanghu0.show();
	zhanghu1.show();

    return 0;
}
