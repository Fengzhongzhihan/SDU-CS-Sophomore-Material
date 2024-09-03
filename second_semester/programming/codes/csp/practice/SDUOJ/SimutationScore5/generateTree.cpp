//
// Created by Lenovo on 2024-06-07.
//
#include "bits/stdc++.h"
using namespace std;
#define  int long long
const int N = 1e6 + 10, M = 2 * N;
int e[M], ne[M], w[M], h[N], idx;
bool st[N];
int n, m;
int res = 0;
int dist[N];
typedef pair<int ,int >PII;
void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;

}

void bfs() {
    queue<PII> q;// x: 编号， y : 到根结点距离
    q.push({1, 0});
    memset(dist, 0x3f3f3f3f, sizeof dist);
    dist[1] = 0;
    st[1] = true;
    while (q.size()) {
        int sz = q.size();
        vector<int> tmp;
        int edge = q.front().second;
        //遍历当前层的所有节点
        for (int k = 0 ; k < sz; k++) {
            auto t = q.front();
            //遍历当前新加入的所有节点
            int u = t.first;
            q.pop();
            for (int i = h[u]; i != -1; i = ne[i]) {
                int j = e[i];
                dist[j] = min(dist[j], w[i]);
                if (!st[j]) {//如果还没加入队列， 则加入队列
                    st[j] = true;
                    q.push({j, edge + 1});
                    tmp.push_back(j);
                }
            }
        }
        //此时下一层的节点已经全部加入队列
        for (auto t : tmp) {
            res += dist[t] * (edge + 1);
        }
    }
}


signed main() {
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 0 ; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }

    bfs();
    cout << res;
}