#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5 + 10;
int n,m;
int e[N],ne[N],w[N],h[N],idx;
int d[N];
bool st[N];//表示是否在队列中
queue<int>q;

void add(int a,int b,int c)
{
    e[idx]=b;
    ne[idx]=h[a];
    w[idx]=c;
    h[a]=idx++;
}

void spfa()
{
    memset(d, 0x3f3f3f3f, sizeof(d));
    q.push(1);
    d[1] = 0;
    while (q.size()) {
        auto t = q.front();
        q.pop();
        st[t]  = false;
        for (int i = h[t] ; i != -1; i = ne[i]) {
            int j = e[i];
            if (d[j] > d[t] + w[i]) {
                d[j] = d[t] + w[i];
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    memset(h,-1,sizeof(h));
    while(m--)
    {
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
    }

    spfa();
    if(d[n] == 0x3f3f3f3f) cout<<"impossible";
    else cout<<d[n];
    return 0;
}