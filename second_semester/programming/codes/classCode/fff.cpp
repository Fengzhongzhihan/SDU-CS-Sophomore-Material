#include<iostream>
#include<cstring>
using namespace std;
const int N= 1e6 + 10;
const int M=2*N;
const int INF=0x3f3f3f3f;
int d[N];

int h[N],e[M],ne[M],w[M],idx;
bool st[N];
int n,m;

void add(int a,int b,int c)
{
    e[idx]=b;
    ne[idx]=h[a];
    w[idx]=c;
    h[a]=idx++;
}

int prim()
{
    memset (d, INF, sizeof(d));
    int res = 0;
    d[1] = 0;
    //选出最小值
   for (int i = 0; i < n ; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++)
        if (!st[j] && (t == -1 || d[t] > d[j])) {
            t = j;
        }
        
        st[t] = true;
        //如果不是连通图
        if (d[t] == INF) {
            return INF;
        }
        res += d[t];
        //更新
        for (int k = h[t]; k != -1; k = ne[k]) {
            int j = e[k];
            d[j] = min (d[j], w[k]);
        }
   }
   
   return res;
}

int main()
{

    memset(h,-1,sizeof(h));
    cin>>n>>m;
    int i,j,w;

    while(m--)
    {
        cin>>i>>j>>w;
        add(i,j,w);
        add(j,i,w);
    }

    int t=prim();
    if(t>=INF)
        cout<<"impossible"<<endl;
    else 
        cout<<t;
}
