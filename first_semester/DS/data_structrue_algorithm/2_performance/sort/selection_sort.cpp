#include<iostream>
using namespace std;

//找到0-n中最大值的索引
int indexofmax(int a[],int n)
{
    if(n<=0)return -1;
    int indexofmax=0;
    for(int i=0;i<n;i++)
        if(a[i]>a[indexofmax])
            indexofmax=i;
    return indexofmax;
}

void selection_sort(int a[],int n)
{
    for(int i=n-1;i>=1;i--)
    {      // 注意,此时枚举最大值一定要包含自己,因为自己有可能就是最大的
        swap(a[i],a[indexofmax(a,i+1)]);
    }
}

void improve_selection_sort(int a[],int n)
{       bool sort=false;//是否有序,无序为false,有序为true
    for(int i=n-1;i>=1&&!sort;i--)
    {      
        sort=true;
        int indexofmax=0;
        // 如果一直在交换,则设为true
        for(int j=1;j<i+1;j++)
        if(a[j]>a[indexofmax])
        {
            indexofmax=j;
        }
        else sort=false;
        swap(a[indexofmax],a[i]);
    }
}

int main()
{
    int a[]={1,3,4,5,2};
   // 1 3 4 5 2
    
    int len=sizeof(a)/sizeof(a[0]);
    improve_selection_sort(a,len);
    for(auto k:a)
    cout<<k<<" ";
}