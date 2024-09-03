#include<iostream>
using namespace std;
const int N=100010;

int main()
{
    char str[N];
    bool isused[N];
    int n,m;
    int r20[N];
    int st[N];
    scanf("%d%d",&n,&m);
    getchar();
    int l,r;

    for(int i=0;i<n;i++)
        scanf("%c",&str[i]);
    
    getchar();
    while(m--)
    {
        int min=N;
        scanf("%d%d",&l,&r);
        
        //统计字母的最少出现次数
        for(int i=l;i<=r;i++)
        {
            if(!isused[i])
                st[str[i]]++;
            isused[i]=true;
        }

        for(int i=l;i<=r;i++)
        {
            if(st[str[i]]<min)
                min=st[str[i]];
        }

        cout<<min<<endl;
    }
}