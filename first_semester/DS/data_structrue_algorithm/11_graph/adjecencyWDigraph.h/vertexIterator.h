#pragma once
#include<iostream>
using namespace std;

template<class T>
class VertexIterator
{
    public:
        virtual ~VertexIterator(){}
        virtual int next()=0;
        virtual int next(T& )=0;
};