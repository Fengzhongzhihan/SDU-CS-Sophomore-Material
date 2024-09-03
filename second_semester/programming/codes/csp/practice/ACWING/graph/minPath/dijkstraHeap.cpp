//
// Created by Lenovo on 2024-06-10.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 10;
int e[N], ne[N], h[N], w[N], idx;
int dist[N]; bool st[N];
int n, m;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;

void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void dijkstra() {
    memset(dist, 0x3f3f3f3f, sizeof dist);
    dist[1] = 0;
    heap.push({0, 1});
    while (heap.size()) {
        auto t = heap.top();
        heap.pop();
        int ver = t.second, dis = t.first;
        if (st[ver]) {
            continue;
        }
        st[ver] = true;
        for (int i = h[ver]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[ver] + w[i]) {
                dist[j] = dist[ver] + w[i];
                heap.push({dist[j], j});//松弛成功, 则加入堆中
            }
        }
    }

}

int main() {
    cin >> n >> m;
    memset (h, -1, sizeof h);
    for (int i = 0 ; i< m ; i++) {
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
}