//
// Created by Lenovo on 2024-04-22.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 10;
int t, n ,m;
int h1[N], e1[N], w1[N], ne1[N], idx1;
int h2[N], e2[N], w2[N], ne2[N], idx2;
int dis[N];
bool st[N];

void add1(int a, int b, int c) {
    e1[idx1] = b;
    w1[idx1] = c;
    ne1[idx1] = h1[a];
    h1[a] = idx1++;
}

void add2(int a, int b, int c) {
    e2[idx2] = b;
    w2[idx2] = c;
    ne2[idx2] = h2[a];
    h2[a] = idx2++;
}

void spfa(int op) {
    if (op == 1) {
        //对h1跑spfa
        queue<int> q;
        q.push(1);
        dis[1] = 0;
        st[1] = true;
        while (q.size()) {
            auto k = q.front();
            q.pop();
            st[k] = false; // 更新状态, 此时点不为成功松弛的点
            for (int i = h1[k] ; i != -1; i = ne1[i]) {
                int j = e1[i];
                if (dis[j] > dis[k] + w1[i]) {
                    dis[j] = dis[k] + w1[i];
                    if (!st[j]) {
                        st[j] = true;
                        q.push(j);
                    }
                }
            }
        }
    }
    else {
        //对h2跑spfa
        queue<int> q;
        q.push(1);
        dis[1] = 0;
        while (q.size()) {
            auto k = q.front();
            q.pop();
            st[k] = false; // 更新状态, 此时点不为成功松弛的点
            for (int i = h2[k] ; i != -1; i = ne2[i]) {
                int j = e2[i];
                if (dis[j] > dis[k] + w1[i]) {
                    dis[j] = dis[k] + w1[i];
                    if (!st[j]) {
                        st[j] = true;
                        q.push(j);
                    }
                }
            }
        }
    }
}


int main() {
    cin >> t;
    while(t--) {
        int ans = 0;
        cin >> n >> m;
        //初始化
        memset(h1, -1, sizeof(h1));
        memset(h2, -1, sizeof(h2));
        for (int i = 0 ; i < n ; i++) {
            e1[i] = w1[i] = e2[i] = w2[i] = ne1[i] = ne2[i] = 0;
        }
        memset(dis, 0x3f3f3f3f, sizeof(dis));
        memset(st, false, sizeof(st));
        idx1 = idx2 = 0;

        for (int i = 0 ; i < m ; i++) {
            int a, b , c;
            cin >> a >> b >> c;
            add1(a, b, c);
            add2(b, a, c); // 负图
        }

        spfa(1); // 正图进行求最短路
        for (int i = 1; i <= n; i++) {
            ans += dis[i];
        }
//        cout << ans << endl;

        memset(dis, 0x3f3f3f3f, sizeof(dis));
        memset(st, false, sizeof(st));
        spfa(2);
        for (int i = 1; i <= n; i++) {
            ans += dis[i];
        }

        cout << ans << endl;
    }
}