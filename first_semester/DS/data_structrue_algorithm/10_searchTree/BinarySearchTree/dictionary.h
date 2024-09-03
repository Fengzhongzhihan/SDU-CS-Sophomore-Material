#pragma once
#include<iostream>
using namespace std;

template<class K ,class E>
class Dictionary
{
    public:
        virtual ~Dictionary(){}
        virtual bool empty()const=0;
        virtual int size()const=0;
        virtual pair<K,E>* find(const K&)const=0;
        virtual void erase(const K&)=0;
        virtual void insert(const pair<K,E>&)=0;
};