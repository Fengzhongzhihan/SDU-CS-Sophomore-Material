#include"linkedGraph.h"
#include"unweightedEdge.h"
#include<cstring>
int n,m,s,t;
const int N=100010;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>s>>t;
    LinkedGraph mGraph(n);
    int op,u,v;
    while(m--)
    {
        cin>>op>>u>>v;
        //增加一条边
        if(op==0)
        {
            mGraph.insertEdge(new UnWeightedEdge(u,v));
        }
        else 
        {
            mGraph.eraseEdge(u,v);
        }
    }

    int c[n+1]={0};
    //输出连通分量
    cout<<mGraph.lableComponents(c)<<endl;

    //输出所有连通子图最小点的标号
    bool st[n+1]={false};
    for(int i=1;i<=n;i++)
    {
        if(st[c[i]]==false)
        {
            cout<<i<<" ";
            st[c[i]]=true;
        }
    }
    cout<<endl;

    //输出从s点开始的dfs序列长度
    for(int i=0;i<=n;i++)
        c[i]=0;
    cout<<mGraph.ldfs(s,c)<<endl;

    //输出从s点开始的dfs序列
    for(int i=0;i<=n;i++)
        c[i]=0;
    mGraph.rdfs(s,c);
    cout<<endl;

    //输出从t点开始的bfs序列长度
     for(int i=0;i<=n;i++)
        c[i]=0;
    cout<<mGraph.lbfs(t,c)<<endl;

    //输出从t点开始的bfs序列

    for(int i=0;i<=n;i++)
        c[i]=0;
    mGraph.rbfs(t,c);
    cout<<endl;

    //输出最短路径
    for(int i=0;i<=n;i++)
        c[i]=0;
    int path[n+1]={0};
    
    cout<<mGraph.findMinPath(s,t,path,c);
}