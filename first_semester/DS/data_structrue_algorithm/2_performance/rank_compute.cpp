#include<iostream>
#include<cstring>
using namespace std;

//名次定义:比它小的元素个数+左边出现的相同元素个数
//计算名次
void rank_compute(int a[],int n,int r[])
{
    
    for(int i=1;i<n;i++)
        for(int j=0;j<i;j++)
        if(a[j]<=a[i])r[i]++;
        else r[j]++;
}
//按照名次排序
void rank_sort(int a[],int n,int r[])
{
    //新开辟一个数组
    int *u=new int [n];
    for(int i=0;i<n;i++)
    u[r[i]]=a[i];

    for(int i=0;i<n;i++)
    a[i]=u[i];

    delete[] u;
}

//不适用额外数组进行排序
void rank_sort_without_u(int a[],int n,int r[])
{
    for(int i=0;i<n;i++)
    while(r[i]!=i)
    {
        int t=r[i];
        swap(a[i],a[t]);
        swap(r[i],r[t]);
    }
}
int main()
{
    
    int a[]{1,3,5,3,9};
    int n=sizeof(a)/sizeof(a[0]);
    int r[n]={0};
    rank_compute(a,n,r);
    //打印
    for(auto k:a)
    cout<<k<<" ";
    cout<<endl;
    // for(auto k:r)
    // cout<<k<<" ";
    // cout<<endl;

    // rank_sort(a,n,r);
    // for(auto k:a)
    // cout<<k<<" ";
    // cout<<endl;

    rank_sort_without_u(a,n,r);
    for(auto k:a)
    cout<<k<<" ";
    cout<<endl;

    return 0;
}