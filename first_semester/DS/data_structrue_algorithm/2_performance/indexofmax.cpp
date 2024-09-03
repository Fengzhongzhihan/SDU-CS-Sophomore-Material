#include<iostream>
using namespace std;

//找到最大的数的下标 比较次数n-1
int indexofmax(int a[],int n)
{
    if(n<=0)return 0;
    int index=0;
    for(int i=1;i<n;i++)
        if(a[i]>a[index])
        index=i;
    return index;
}

int main()
{
    int a[]={1,2,3};//1+2x+3x^2
    cout<<a[indexofmax(a,3)]<<endl;
}