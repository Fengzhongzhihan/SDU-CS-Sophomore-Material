#include<iostream>
#include<math.h>
using namespace std;

void bubble_sort(int a[],int n)
{
    for(int i=n-1;i>=1;i--)
    for(int j=0;j<i;j++)
        if(a[j]>a[j+1])swap(a[j],a[j+1]);
}

void improve_bubble_sort(int a[],int n)
{
    bool sort=false;
    for(int i=n-1;i>=1&&!sort;i--)
    {
        sort=true;
        for(int j=0;j<i;j++)
        if(a[j]>a[j+1])
        {
            swap(a[j],a[j+1]);
            sort=false;
        }
    }
}
    int main()
{
    int a[]={1,3,4,5,2};
   // 1 3 4 5 2
    
    int len=sizeof(a)/sizeof(a[0]);
    improve_bubble_sort(a,len);
    for(auto k:a)
    cout<<k<<" ";
}