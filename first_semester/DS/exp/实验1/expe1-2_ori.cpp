#include<iostream>
using namespace std;
int n;
int v_index=0;
const int N=100010;

int factorial(int n)
{
    if(n==1)return 1;
    return (n*factorial(n-1));
}

void dfs(int u,int arr[],bool st[],int value[],int sup[])
{
    if(u==n)
    {   
         //求出其价值
        int t_sum=0;
        for(int i=0;i<u;i++)
        {
            t_sum+=(sup[i])^(i+1);
        }
        value[v_index++]=t_sum;
    }
    else
    {
        for(int i=0;i<n;i++)
        // 遍历每一个数组中的元素
        if(!st[arr[i]])
        {
            st[arr[i]]=true;
            sup[u]=arr[i];
            dfs(u+1,arr,st,value,sup);
            // 注意此时需要复位
            st[arr[i]]=false;
        }
    }
}

int main()
{
    cin>>n;
    int arr[n],sup[n];
    bool st[N];
    int value[factorial(n)];
    for(int i=0;i<n;i++)cin>>arr[i];

    // 求出各个排列价值
    dfs(0,arr,st,value,sup);


    // 求出最终结果
    int ans=value[0];
    for(int i=1;i<v_index;i++)
    {
        ans|=(value[i]);
    }
    cout<<ans;
    return 0;
}