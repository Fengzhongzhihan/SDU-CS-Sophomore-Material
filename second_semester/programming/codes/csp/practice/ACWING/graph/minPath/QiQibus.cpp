//
// Created by Lenovo on 2024-06-17.
//
#include "bits/stdc++.h"
using namespace std;
int n, m, s;
const int N = 1e6 + 10;
int e[N], ne[N], h[N], w[N], idx;
int dist[N]; bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void spfa() {
    memset(dist, 0x3f3f3f3f, sizeof dist);
    dist[s] = 0;
    queue<int> q;
    q.push(s);
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

int main() {
    while(cin >> n >> m >> s) {
        memset(h, -1, sizeof h);
        for (int i = 0 ; i < m ; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            add(b, a, c);
        }
        spfa();
        int res = 0x3f3f3f3f;
        int cnt ; cin >> cnt;
        while (cnt--) {
            int x; cin >> x;
            res = min(res, dist[x]);
        }
        if (res == 0x3f3f3f3f) {
            cout << -1 << endl;
        }
        else {
            cout << res << endl;
        }
    }
    return 0;
}