//
// Created by Lenovo on 2024-04-26.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 10;
int h[N], ne[N], e[N], w[N], idx;
int s[N];  //前缀和
int n, m;
int dis[N], cnt[N]; // 判断负环
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}

bool spfa() {
    memset(st, false, sizeof(st));
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    queue<int>q;
    q.push(0);
    dis[0] = 0;
    while(q.size()) {
        auto t = q.front();
        q.pop();
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dis[j] > dis[t] + w[i]) {
                dis[j] = dis[t] + w[i];
                cnt[j] = cnt[t] + 1;
                // n + 1个点, 最短路边长 >= n + 1有负环
                if (cnt[j] > n) { // 松弛的次数 > n + 1, 无解, 有负环则返回false
                    return false;
                }
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    memset(h, -1, sizeof(h));
    //初始化

    //初始化
    for (int i = 1; i <= n; i++) {
        //sum[i] - sum[i - 1] <= 1
        //sum[i] - sum[i - 1] >= 0 sum[i - 1] - sum[i] <= 0
        //求最大值, 找最短路
        //sum[i] - sum[i - 1] <= 1
        add(i - 1, i, 1);
        add(i, i - 1, 0);
    } // 有 n + 1个点, 包含0点
    while(m--) {
        int k, a, b, c;
        cin >> k >> a >> b >> c;
        if (k == 1) {
            // s[b] - s[a - 1] <= c
            add(a - 1, b, c);
        }
        else if (k == 2) {
            // s[b] - s[a - 1] >= c
            // s[a - 1] - s[b] <= -c
            add(b, a - 1, -c);
        }
        else if (k == 3) {
            // s[b] - s[a - 1] < c
            // s[b] - s[a - 1] <= c - 1
            add(a - 1, b, c - 1);
        }
        else if (k == 4) {
            // s[b] - s[a - 1] > c
            // s[b] - s[a - 1] >= c + 1
            // s[a - 1] - s[b] <= -c - 1
            add(b, a - 1, -c - 1);
        }
        else {
            // s[b] - s[a - 1] == c
            // s[b] - s[a - 1] <= c
            // s[b] - s[a - 1] >= c // s[a - 1] - s[b] <= -c
            add(a - 1, b, c);
            add(b, a - 1, -c);
        }
    }
    //求解最短路, 其中dis[n]代表sum[n], 即一共种酸奶的个数
    if (spfa()) {
        cout << dis[n] << endl;
    }
    else {
        cout << "impossible" << endl;
    }
}