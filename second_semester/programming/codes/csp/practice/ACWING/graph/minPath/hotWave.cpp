//
// Created by Lenovo on 2024-06-17.
//
#include "bits/stdc++.h"
using namespace std;
#define int long long
const int N = 1e5 + 10;
int e[N], ne[N], h[N], w[N], idx;
int dist[N];
bool st[N];
int n, m, ss, ee;

void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void spfa() {
    memset(dist, 0x3f3f3f3f, sizeof dist);
    dist[ss] = 0;
    queue<int> q;
    q.push(ss);
    while (q.size()) {
        int t = q.front();
        q.pop();
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
}

signed main() {
    cin >> n >> m >> ss >> ee;
    memset(h, -1, sizeof h);
    for (int i = 0; i  < m ; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    spfa();
    cout << dist[ee];
}