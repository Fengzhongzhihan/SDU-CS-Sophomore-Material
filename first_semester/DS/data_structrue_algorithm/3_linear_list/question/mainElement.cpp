#include<iostream>
using namespace std;
int n;
const int N=100010;
int cnt[N];
bool st[N];
int getMainElement(int a[],int len)
{
    for(int i=0;i<len;i++)
    {
        int x=a[i];
        if(!st[x])
        {
            for(int j=0;j<len;j++)
            {
                if(a[j]==x)cnt[x]++;
            }
            if(cnt[x]>len/2)
            {
                return x;
                break;
            }
            st[x]=true;
        }
    }
    return -1;
}

int main()
{
    cin>>n;
    int a[N];
    for(int i=0;i<n;i++)cin>>a[i];
    cout<<getMainElement(a,n)<<endl;
    return 0;
}