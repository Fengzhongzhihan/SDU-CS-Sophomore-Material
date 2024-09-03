#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=3e5+10;
const int M=2*N;
int n,m;
int idx;
//并查集
int p[N];

struct Edge
{
    int v1,v2,w;
}Edges[M];

int find(int x)
{
    if(p[x]!=x)
        p[x]=find(p[x]);
    return p[x];
}

bool cmp(Edge a,Edge b)
{
    return a.w<b.w;
}

long long  cruskal()
{
    long long  res=0;
    int cnt=0;
    for(int i=1;i<=n;i++)
        p[i]=i;
    
    sort(Edges,Edges+idx,cmp);

    for(int i=0;i<idx;i++)
    {
        auto k=Edges[i];
        int a=k.v1,b=k.v2,c=k.w;

        a=find(a);b=find(b);

        if(a!=b)
        {
            p[a]=b;
            res+=c;
        }
    }
    return res;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    int a,b,c;
    while(m--)
    {
        cin>>a>>b>>c;
        Edges[idx++]=Edge{a,b,c};
    }

    cout<<cruskal()<<" ";
}