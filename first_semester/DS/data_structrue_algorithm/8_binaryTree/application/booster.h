#pragma once
#include<iostream>
using namespace std;

struct booster
{
    int degradeToLeaf=0;
    int degradeFromParent;
    bool boosterHere=false;

    void output(ostream& out)const
    {
        if(boosterHere)
            out<<"Yes"<<" ";
        else 
            out<<"No"<<" ";
        out<<degradeToLeaf<<" "<<degradeFromParent<<" ";
    }
};

ostream& operator<<(ostream& out,booster x)
{
    x.output(out);return out;
}

