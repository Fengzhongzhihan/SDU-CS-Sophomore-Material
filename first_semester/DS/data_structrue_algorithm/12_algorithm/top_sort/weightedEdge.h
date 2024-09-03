#pragma once
#include<iostream>
#include"edge.h"
using namespace std;

template<class T>
class WeightedEdge: public Edge<T>
{
    public:
        int vertex1() const
        {
            return v1;
        }
        int vertex2() const
        {
            return v2;
        }
        T weight() const
        {
            return w;
        }
        WeightedEdge(int v1,int v2,T theWeight)
        {
            this->v1=v1;
            this->v2=v2;
            w=theWeight;
        }

    protected:
        T w;
        int v1,v2;
};