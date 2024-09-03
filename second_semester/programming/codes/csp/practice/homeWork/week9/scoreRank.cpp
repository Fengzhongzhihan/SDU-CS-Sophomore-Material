//
// Created by Lenovo on 2024-04-25.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 10;
int n, m;
int h[N], e[N], ne[N], idx;
int inDegree[N];


void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
    inDegree[b]++;
}

void topSort() {
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1 ; i <= n ; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    while (q.size()) {
        auto t = q.top();//取出一个点
        q.pop();
        cout << t<< " ";
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            inDegree[j]--;
            if (inDegree[j] == 0) {
                q.push(j);
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