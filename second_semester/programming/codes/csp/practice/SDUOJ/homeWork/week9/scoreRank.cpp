//
// Created by Lenovo on 2024-04-25.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 10;
int n, m;
int h[N], e[N], ne[N], idx;
int inDegree[N];

struct info{
    int rk, ID;
};

struct compare{
    bool operator () (const info& a, const info& b) const {
        if (a.rk == b.rk) {
            return a.ID > b.ID;
        }
        return a.rk > b.rk;
    }
};

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
    inDegree[b]++;
}

void topSort() {
    priority_queue<info, vector<info>, compare> q;
    for (int i = 1 ; i <= n ; i++) {
        if (inDegree[i] == 0) {
            q.push({1, i});
        }
    }
    while (q.size()) {
        auto t = q.top();//取出一个点
        q.pop();
        cout << t.ID << " ";
        for (int i = h[t.ID]; i != -1; i = ne[i]) {
            int j = e[i];
            inDegree[j]--;
            if (inDegree[j] == 0) {
                q.push({t.rk, j});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    memset(h, -1, sizeof (h));
    while (m--) {
        int a, b;
        cin >> a >> b; // a学号 > b学号
        add(a, b);
    }

    topSort();
    return 0;
}