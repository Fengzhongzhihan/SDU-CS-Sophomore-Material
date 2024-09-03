#include<iostream>
int n;
using namespace std;
void delete_s_t(int a[],int s,int t)
{
    int k=0;
    for(int i=0;i<n;i++)
    {
        int x=a[i];
        if(x>=s&&x<=t)
        {
            k++;
        }
        else
        {
           a[i-k]=x;
        }
    }
    n-=k;
}

int main()
{
    cin>>n;
    int a[n],s,t;
    for(int i=0;i<n;i++)cin>>a[i];
    cin>>s>>t;
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    cout<<endl;
    delete_s_t(a,s,t);
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    return 0;
}