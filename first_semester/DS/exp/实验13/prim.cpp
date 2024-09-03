#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
typedef pair<int,int> PII;
const int N=1e6+10;
int n,m;
int e[N],ne[N],w[N],h[N],idx;
int d[N];
bool st[N];
priority_queue<PII,vector<PII>,greater<PII>> heap;

void add(int a,int b,int c)
{
    e[idx]=b;
    ne[idx]=h[a];
    w[idx]=c;
    h[a]=idx++;
}

long long  prim()
{
    long long  res=0;
    memset(d,0x3f,sizeof(d));
    d[1]=0;

    heap.push({0,1});

    while(!heap.empty())
    {
        auto t=heap.top();
        heap.pop();

        int val=t.second,dis=t.first;
        //取出该结点,包含到集合里面来
        if(!st[val])
        {   
            res+=dis;
            st[val]=true;
            //对于结点的每个边,都进行遍历
            for(int i=h[val];i!=-1;i=ne[i])
            {
                int j=e[i];
                //更新的时候才放入
                if(d[j]>w[i])
                {
                    d[j]=w[i];
                    heap.push({d[j],j});
                }
            }
        }
    }
    
    return res;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    memset(h,-1,sizeof(h));
    while(m--)
    {
        int x,y,z;
        cin>>x>>y>>z;
        {
            add(x,y,z);
            add(y,x,z);
        }
    }
    
    cout<<prim();
    return 0;
}