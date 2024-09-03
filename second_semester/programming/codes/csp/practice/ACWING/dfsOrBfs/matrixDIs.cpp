//
// Created by Lenovo on 2024-06-05.
//
#include "bits/stdc++.h"
using namespace std;
int n, m;
const int N = 1010;
char g[N][N];
int d[N][N];
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

void bfs() {
    //虚拟源点
    queue<pair<int ,int >>q;
    memset(d, -1, sizeof d);
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            if (g[i][j] == '1') {
                q.push({i, j});
                d[i][j] = 0;
            }
        }
    }

    while (q.size()) {
        auto t = q.front();
        q.pop();
        int x = t.first, y = t.second;
        for (int i = 0 ; i < 4 ; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a >= n || b < 0 || b >= m) continue;
            if (d[a][b] == -1) {
                d[a][b] = d[x][y] + 1;
                q.push({a, b});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            cin >> g[i][j];
        }
    }

    bfs();
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
}