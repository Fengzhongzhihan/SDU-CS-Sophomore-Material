#pragma once
#include<iostream>
using namespace std;
enum signType{PLUS,MINUS};
typedef unsigned long ul;
typedef unsigned int ui;
class Currency
{
public:
    Currency (signType thesign,ul thedollars=0,ui cents=0);
    Currency(){};
    ~Currency(){}
    //注意,此时的函数都不包含具体变量名,只有数据类型
    void setValue(signType,ul,ui );
    void setValue(double);

    //返回符号,美元和美分
    signType getSign() const {return sign;}
    ul getDollars()const {return dollars;}
    ui getCents()const {return cents;}

    //两个加函数
    Currency add(const Currency&) const ;
    Currency& increment(const Currency&);

    //输出
    void output()const ;

    //(1)输入
    void input();
    //(2)减法
    double subtract(double x)const ;
    //(3)%x
    Currency percent(double x)const;
    //(4)乘法
    Currency multiply(double x)const;
    //(5)除法
    Currency divide(double x)const ;
private:
    signType sign;
    ul dollars=0;
    ui cents=0;
};