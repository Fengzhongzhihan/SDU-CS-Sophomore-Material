//
// Created by Lenovo on 2024-06-17.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 10;
int n, cnt, res = 0;
int p[N];
struct edge{
    int a, b, w;
}edges[N];

int find(int x) {
    if (p[x] != x) return find(p[x]);
    return p[x];
}

bool compare(edge a, edge b) {
    return a.w < b.w;
}

void kruscal() {
    for (int i = 0 ; i < cnt; i++) {
        int a= edges[i].a, b = edges[i].b, w = edges[i].w;
        int pa = find(a), pb = find(b);
        if (pa != pb) {
            p[pa] = pb;
            res += w;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            int x ; cin >> x;
            if (i < j && x) {
                edges[cnt++] = {i, j, x};
            }
        }
    }
    for (int i = 1; i <=  n; i++) {
        p[i] = i;
    }
    sort(edges, edges + cnt, compare);
    kruscal();
    cout << res;
}