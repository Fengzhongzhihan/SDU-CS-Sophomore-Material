#pragma once
#include<iostream>
using namespace std;

//优先级队列
template<class T>
class MaxPriorityQueue
{
    public:
        virtual ~MaxPriorityQueue(){}
        virtual bool empty()const =0;
        virtual int size()const=0;
        virtual const T& top()=0;
        virtual void pop()=0;
        virtual void push(const T& theElement)=0;
};

