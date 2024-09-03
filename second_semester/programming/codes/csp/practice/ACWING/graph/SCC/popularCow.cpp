//
// Created by Lenovo on 2024-06-17.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 10;
int e[N], ne[N], h[N], hs[N],  idx;
int n, m;
int dfn[N], id[N], dcount, scount; bool st[N];
int idSize[N];
int dout[N] = {0}, cnt = 0;
void add(int h[], int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs1(int x) {
    st[x] = true;
    for (int i = h[x]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!st[j]) {
            dfs1(j);
        }
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

void kosaraju() {
    for (int i = 1; i <= n; i++) {
        if (!st[i]) {
            dfs1(i);
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        int p = dfn[i];
        if (!id[p]) {
            scount++;
            dfs2(p);
        }
    }
}
int main() {
    cin >> n >> m;
    memset(h, -1, sizeof h);
    memset(hs, -1, sizeof hs);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        add(h, a, b);
        add(hs, b, a);
    }
    kosaraju();
    //找到出度为0的SCC数量
    for (int i = 1; i <= n; i++) {
        for (int j = h[i]; j != -1; j = ne[j]) {
            int k = e[j];
            if (id[i] != id[k]) {
                dout[id[i]]++;
            }
        }
    }
    int zeros = 0;
    for (int i = 1 ; i <= scount; i++) {
        if (dout[i] == 0) {
            zeros ++;
            cnt = idSize[i];
            if (zeros > 1) {
                cnt = 0;
                break;
            }
        }
    }
    cout << cnt;
}