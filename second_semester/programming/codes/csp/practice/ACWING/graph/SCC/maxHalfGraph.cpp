//
// Created by Lenovo on 2024-06-17.
//
#include "bits/stdc++.h"
using namespace std;
#define int long long
const int N = 2e6 + 10;
int e[N], ne[N], h[N], hs[N], hd[N], idx1, idx2;
int n, m, mod;
//int dfn[N], id[N], dcount, scount; bool st[N];
//int idSize[N];
int stk[N],top,times;
bool in_stk[N];
int dfn[N],low[N];
int id[N],scc_cnt,Size[N];
int f[N],g[N];
void add1(int a, int b) {
    e[idx1] = b, ne[idx1] = h[a], h[a] = idx1++;
}
void add2(int a, int b) {
    e[idx2] = b, ne[idx2] = hs[a], hs[a] = idx2++;
}

void dfs1(int x) {
    st[x] = true;
    for (int i = )
    {
         if !st
         dfs1
    }
    dfn[dcount++] = x;
}

void dfs2(int x) {
    id[x] = scount;
    idSize[scount]++;
    for (int i = hs[x]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!id[j]) {
            dfs2(j);
        }
    }
}
//
//void dfs1(int x) {
//    st[x] = true;
//    for (int i = h[x]; i != -1; i = ne[i]) {
//        int j = e[i];
//        if (!st[j]) {
//            dfs1(j);
//        }
//    }
//    dfn[dcount++] = x;
//}
//
//void dfs2(int x) {
//    id[x] = scount;
//    idSize[scount]++;
//    for (int i = hs[x]; i != -1; i = ne[i]) {
//        int j = e[i];
//        if (!id[j]) {
//            dfs2(j);
//        }
//    }
//}
//
//void kosaraju() {
//    for (int i = 1; i <= n; i++) {
//        if (!st[i]) {
//            dfs1(i);
//        }
//    }
//    for (int i = n - 1; i >= 0; i--) {
//        int p = dfn[i];
//        if (!id[p]) {
//            scount++;
//            dfs2(p);
//        }
//    }
//}

void tarjan(int u)
{
    dfn[u] = low[u] = ++ times ;
    stk[++ top] = u,in_stk[u] =true;
    for(int i =h[u]; ~i;i = ne[i])
    {
        int j = e[i];
        if(!dfn[j])
        {
            tarjan(j);
            low[u] = min(low[u],low[j]);
        }
        else if(in_stk[j]) low[u] = min(low[u] , dfn[j]);
    }

    if(dfn[u] == low[u])
    {
        scc_cnt ++;
        int y;
        do{
            y = stk[top --];
            in_stk[y] = false;
            id[y] = scc_cnt;
            Size[scc_cnt] ++;
        }while(y != u);
    }
}

signed main() {
    cin >> n >> m >> mod;
    memset(h, -1, sizeof h);
    memset(hs, -1, sizeof hs);
    memset(hd, -1, sizeof hd);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%lld%lld", &a, &b);
        add1(h, a, b);
    }
    for(int i = 1;i <= n;i ++)
        if(!dfn[i]) tarjan(i);
    unordered_set <int> S;
    for(int u = 1;u <= n;u ++)
    {
        for(int i = h[u]; ~i;i = ne[i])
        {
            int j = e[i];
            int a = id[u],b = id[j];
            int hash = a * 1000000ll + b;
            if(a != b && !S.count(hash))
            {
                add(hd,a,b);
                S.insert(hash);
            }
        }
    }


    for(int i = scc_cnt; i ;i --)
    {
        if(! f[i])
        {
            f[i] = Size[i];
            g[i] = 1;
        }
        for(int j = hd[i]; ~j ; j = ne[j])
        {
            int k = e[j];
            if(f[k] < f[i] + Size[k])
            {
                f[k] = f[i] + Size[k];
                g[k] = g[i];
            }
            else if(f[k] == f[i] + Size[k])
                g[k] = (g[k] + g[i]) % mod;
        }
    }

    int maxn = 0 ,sum = 0;
    for(int i = 1;i <= scc_cnt;i ++)
        if(f[i] > maxn)
        {
            maxn = f[i];
            sum = g[i];
        }
        else if(f[i] == maxn) sum = (sum + g[i]) % mod;

    cout << maxn << endl << sum << endl;
    return 0;
}