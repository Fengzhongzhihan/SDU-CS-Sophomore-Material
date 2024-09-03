#pragma once
#include<iostream>
#include"edge.h"
using namespace std;

class UnWeightedEdge: public Edge<bool>
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
        UnWeightedEdge(int v1,int v2)
        {
            this->v1=v1;
            this->v2=v2;
        }
        bool weight()const 
        { 
            return false;
        }

    protected:
        int v1,v2;
};