//
// Created by Lenovo on 2024-06-19.
//
#include "bits/stdc++.h"
using namespace std;
int n, res = 0x3f3f3f3f;
const int N = 1e5 + 10;
int e[N], ne[N], h[N], idx, w[N];
int d1[N], d2[N], p1[N], p2[N], up[N];
int mxDis = 0;
void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

//void dfs(int u, int father, int dis) {
//    for (int i = h[u]; i != -1; i = ne[i]) {
//        int j = e[i];
//        if (j == father) continue;
//        dfs(j, u, dis + w[i]);
//    }
//    mxDis = max(mxDis, dis);
//}

//先初始化d1和d2为-1，然后dfs_down，找到每个节点的最长和次长路径
void dfs_down(int u, int father){
    d1[u] = d2[u] = 0;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (j == father) continue;
        dfs_down(j, u);
        int d = d1[j] + w[i];
        if (d > d1[u]) {
            d2[u] = d1[u];
            d1[u] = d;
            p1[u] = j;
        } else if (d > d2[u]) {
            d2[u] = d;
            p2[u] = j;
        }
    }
}
// 从上往下走，找到每个节点的最长路径
void dfs_up(int u, int father){
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (j == father) continue;
        if (p1[u] == j) up[j] = max(up[u], d2[u]) + w[i];
        else up[j] = max(up[u], d1[u]) + w[i];
        dfs_up(j, u);
    }
    res = min(res, max(up[u], d1[u]));
}

int main() {
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 0 ; i < n  - 1 ; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    dfs_down(1, -1);
    dfs_up(1, -1);
    cout << res << endl;
}