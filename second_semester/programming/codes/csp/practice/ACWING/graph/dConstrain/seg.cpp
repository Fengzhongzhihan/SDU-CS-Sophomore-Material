//
// Created by Lenovo on 2024-06-19.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 50010, M = N * 3;
int h[N], e[M], ne[M], w[M], idx;
void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}
int dist[N]; bool st[N];
int s[N]; // s[i]表示从1~i中选择数的个数
int n, m;

void spfa() {
    memset(dist, -0x3f3f3f3f, sizeof dist);
    memset(st, 0, sizeof st);
    queue<int> q;
    q.push(0), dist[0] = 0, st[0] = true;
    while (q.size()) {
        int t = q.front();q.pop();
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] < dist[t] + w[i]) {
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
    cin >> n;
    memset(h, -1, sizeof h);
    //s[i] - s[i - 1] <= 1且s[i] - s[i -1] >= 0
    // s[i - 1] - s[i] >= -1
    for (int i = 1; i <= 50001; i++) {
        add(i - 1, i, 0);
        add(i, i - 1, -1);
    }
    //求最小值, 跑最长路
    for(int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a++, b++; //1~50001
        //从a~b中选择的数不少于C个
        //S[b] - S[a - 1] >= c
        add(a - 1, b, c);
    }

    spfa();
    cout << dist[50001] << endl;
    return 0;
}