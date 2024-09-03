//
// Created by Lenovo on 2024-04-22.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 10;
int n ,m;
int h1[N], e1[N], ne1[N], idx1; // 正图
int h2[N], e2[N], ne2[N], idx2; // 反图
int c[N], dfn[N], dcount, scount; // 后序
bool st[N], isIndegree[N];
void add1(int a, int b) {
    e1[idx1] = b;
    ne1[idx1] = h1[a];
    h1[a] = idx1++;
}

void add2(int a, int b) {
    e2[idx2] = b;
    ne2[idx2] = h2[a];
    h2[a] = idx2++;
}
//找出后序列
void dfs1(int x) {
    st[x] = true;
    for (int i = h1[x]; i != -1; i = ne1[i]) {
        int j = e1[i];
        if (!st[j]) {
            dfs1(j);
        }
    }
    dfn[dcount++] = x; // 后序列
}
//找出对应的强连通分量
void dfs2(int x) {
    c[x] = scount;
    for (int i = h2[x]; i != -1; i = ne2[i]) {
        int j = e2[i];
        if (!c[j]) {
            dfs2(j);
        }
    }
}

void kosaraju() {
    //第一遍dfs
    for (int i = 1; i <= n; i++) {
        if (!st[i]) {
            dfs1(i);
        }
    }
    //第二遍
    for (int i = n - 1; i >= 0 ; i--) {
        int p = dfn[i];
        if (!c[p]) {
            ++scount;
            dfs2(p);
        }
    }
}
int main() {
    cin >> n >> m;
    memset(h1, -1 ,sizeof(h1));
    memset(h2, -1 ,sizeof(h2));
    for (int i = 0 ; i < m ; i++) {
        int a, b;
        cin >> a >> b;
        add1(a, b); // 正图
        add2(b, a); // 反图
    }

    kosaraju();
    memset(isIndegree, true, sizeof(isIndegree));
    //遍历每条边, 找出压缩点后入度为0的点
    for (int i = 1; i <= n; i++) {
        for (int j = h1[i]; j != -1 ; j = ne1[j]) {
            int k = e1[j];
            if (c[i] != c[k]) { // k不为入度为0的点
                isIndegree[c[k]] = false;
            }
        }
    }

    int res = 0;
    for (int i = 1 ; i <= scount; i++) {
        if (isIndegree[i]) { // 如果入度为0
            res++;
        }
    }

    cout << res;
    return 0;
}