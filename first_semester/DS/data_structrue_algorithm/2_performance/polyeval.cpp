#include<iostream>
using namespace std;
//多项式求值(朴素)
int polyEval(int coeff[],int n,const int &x)
{
    int y=1;int value=coeff[0];
    for(int i=1;i<=n;i++)
    {
        y*=x;
        value+=y*coeff[i];
    }
    return value;
}   

// Horner法则求多项式,每次都少一次乘法
int horner(int coeff[],int n,const int &x)
{
    int value=coeff[n];
    for(int i=1;i<=n;i++)
    {
        value=value*x+coeff[n-i];
    }
    return value;
}
int main()
{
    int a[]={1,2,3};
    cout<<horner(a,2,3)<<endl;
    cout<<polyEval(a,2,3)<<endl;
}