#pragma once
#include<iostream>
using namespace std;
template <class T>
class LinearList
{
    public: 
    //注释掉纯虚函数的定义，因为纯虚函数不能有函数体
    virtual ~LinearList(){};
    //判断为空
    virtual bool empty()const =0;
    //返回元素个数
    virtual int size()const =0;
    //返回第theIndex个元素
    virtual T get(int theIndex)const =0;
    //返回元素x的索引
    virtual int indexOf(const T& x)const =0;
    //删除第theIndex个元素
    virtual void erase(int theIndex)=0;
    //插入x
    virtual void insert(int theIndex,const T &x)=0;
    //输出
    virtual void output(ostream& out)const=0;
};