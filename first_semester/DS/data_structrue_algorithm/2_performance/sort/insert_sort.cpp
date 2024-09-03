#include<iostream>
using namespace std;

void insert(int a[],int n,int x)
{
    int i;
    //对n-1长度的数组中插入元素x使得数组仍然有序,此时长度为n
    for(i=n-1;i>=0&&x<a[i];i--)
    {
        a[i+1]=a[i];
    }
    a[i+1]=x;
}

void insert_sort(int a[],int n)
{
    //从第二个元素开始插入
    for(int i=1;i<n;i++)
    {
        insert(a,i,a[i]);
    }
}

int main()
{
     int a[5]={1,3,4,5,2};
   // 1 3 4 5 2
    
    int len=sizeof(a)/sizeof(a[0]);
    insert_sort(a,len);
    for(int i=0;i<len;i++)
    cout<<a[i]<<" ";
    return 0;
}