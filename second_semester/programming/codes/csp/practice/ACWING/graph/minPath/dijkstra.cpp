//
// Created by Lenovo on 2024-06-10.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 510, M = 100010;
int g[N][N];
int dist[N];
bool st[N];
int n, m;

void add(int a, int b ,int c) {
    g[a][b] = min(g[a][b], c);
}

void dijkstra() {
    memset(dist, 0x3f3f3f3f, sizeof(dist));
    dist[1] = 0;
    for (int i = 0 ; i < n ; i++) {
        //找到最小距离的点
        int t = -1;
        for (int j = 1; j <= n; j++) {
            if (!st[j] && (t == -1 || dist[j] < dist[t])) {
                t = j;
            }
        }
        //更新旁边的点
        for (int j = 1; j <= n; j++) {
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
        st[t] = true;
    }
}

int main() {
    memset(g, 0x3f3f3f3f, sizeof g);
    cin >> n >> m;
    for (int i = 0 ; i < m ; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    dijkstra();

    if (dist[n] == 0x3f3f3f3f) {
        cout << -1;
    }
    else {
        cout << dist[n];
    }
    return 0;
}