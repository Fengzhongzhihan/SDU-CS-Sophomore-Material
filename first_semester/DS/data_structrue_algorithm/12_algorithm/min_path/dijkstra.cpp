#include<iostream>
#include<cstring>
using namespace std;
const int N=510;
int g[N][N];
int d[N];
bool st[N];
int n,m;

int dijkstra()
{
    memset(d,0x3f,sizeof(d));
    d[1]=0;
    //循环n-1次
    for(int i=0;i<n;i++)
    {
        //寻找最小点
        int t=-1;
        for(int j=1;j<=n;j++)
        {
	        //没有被遍历过且d[j]<d[t]
            if(!st[j]&&(t==-1||d[t]>d[j]))
            {
                t=j;
            }
        }
        
        //用最小点更新所有点到源点的距离
        for(int j=1;j<=n;j++)
            d[j]=min(d[j],d[t]+g[t][j]);
        st[t]=true;
    }
    
    if(d[n]==0x3f3f3f3f)return -1;
     return d[n];
}

int main()
{
    cin>>n>>m;
    memset(g,0x3f,sizeof(g));
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        g[a][b]=min(g[a][b],c);
    }
    cout<<dijkstra();
    return 0;
}