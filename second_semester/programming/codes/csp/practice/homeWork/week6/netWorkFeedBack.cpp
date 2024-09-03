//
// Created by Lenovo on 2024-04-03.
//
#include "bits/stdc++.h"
using namespace  std;
const int N = 1e5 + 10, M = 2 * N;
int n;
int h[N],e[M],ne[M], idx;
bool st[N];
queue <int > q;
int p1 , p2;
void add (int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
//输入一个顶点, 返回所能到达的最远顶点
int bfs (int x, int * dist) {
    int d = 0, p = 0;
    ::memset(st, false , sizeof(st));
    q.push(x);
    st[x] = true;  // 标记已经访问过
    while (q.size()) {
        auto t = q.front();
        q.pop();
        int dis = dist[t], val = t;
        //如果距离比已记录的最大距离大, 则更新
        if (dis > d) {
            p = val;
            d = dis;
        }
        for (int i = h[val]; i != -1; i = ne[i]) {
            int j = e[i];
            if (!st[j]) {
                st[j] = true;
                dist[j] = dis + 1;
                q.push(j);
            }
        }
    }
    return p;
}

int main() {
    cin >> n;
    memset(h, -1, sizeof(h));
    //双向边
    for (int i = 0 ; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b); add(b, a);
    }
    //dist1 dist2分别记录到各个节点到叶节点1, 叶节点2的最远距离.
    int dist[N] = {0}, dist1[N] = {0}, dist2[N] = {0};
    p1 = bfs(1, dist); // 先找到p1
    p2 = bfs(p1, dist1); // 从p1出发, 到每个点的最短距离
    bfs(p2, dist2); // 从p2出发, 到每个点的最短距离

    for (int i = 1; i <= n ;i++) {
        cout << max(dist1[i], dist2[i]) << " "; // 输出到两个叶节点的最大值, 也就是到任意一个点的最大值
    }
}