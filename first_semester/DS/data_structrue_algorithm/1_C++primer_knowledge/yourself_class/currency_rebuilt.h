#pragma once
#include<iostream>
using namespace std;
enum signType{PLUS,MINUS};
typedef unsigned long ul;
typedef unsigned int ui;
class Currency
{
    //加入友元的写法
    friend ostream & operator<<(ostream& out,const Currency &x);
public:
    Currency (signType thesign,ul thedollars=0,ui cents=0);
    Currency(){};
    ~Currency(){}
    //注意,此时的函数都不包含具体变量名,只有数据类型
    void setValue(signType,ul,ui );
    void setValue(double);

    //返回符号,美元和美分
    signType getSign()const 
    {
        if(my_amount<0)return MINUS;
        else return PLUS;
    }

    ul getDollars()const
    {
        if(my_amount<0) return (-my_amount)/100;
        return my_amount/100;
    }

    ui getCents()const 
    {
        if(my_amount<0) return -my_amount-getDollars()*100;
        else return my_amount-getDollars()*100;
    }
    //操作符重载
    Currency operator+ (const Currency&)const ;
    Currency& operator+=(const Currency&x)
    {
        my_amount+=x.my_amount;return *this;
    }

    //输出
    void output(ostream&)const ;
private:
   long my_amount;
};