//
// Created by Lenovo on 2024-06-17.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 10;
int e[N], ne[N], h[N], w[N], idx;
int dist[N]; bool st[N]; int cnt[N];
int n, m, k;
void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

bool spfa() {
    memset(dist, 0x3f3f3f3f, sizeof dist);
    memset(cnt, 0, sizeof cnt);
    memset(st, 0, sizeof st);
    queue<int> q;
    for (int i =  1; i <= n; i++) {
        q.push(i);
        st[i] = true;
    }
    while (q.size()) {
        int t = q.front();
        q.pop();
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n) {
                    return true;
                }
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return false;
}

int main() {
    int T; cin >> T;
    while (T--) {
        cin >> n >> m >> k;
        memset(h, -1, sizeof h);
        idx = 0;
        for (int i = 0 ; i < m ; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            add(a, b, c);
            add(b, a, c);
        }
        for (int i = 0 ; i < k ; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            add(a, b, -c);
        }
        if (spfa()) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}