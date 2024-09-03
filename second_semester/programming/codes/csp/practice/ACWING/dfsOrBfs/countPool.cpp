//
// Created by Lenovo on 2024-06-05.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 1010;
char g[N][N];
int n, m;
bool vis[N][N];
typedef pair<int, int> PII;
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1}, dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
void bfs(int x, int y) {
    queue<PII>q;
    q.push({x, y});
    while (q.size()) {
        auto t = q.front();
        q.pop();
        for (int i = 0 ; i < 8; i++) {
            int a = t.first + dx[i], b = t.second + dy[i];
            if (a < 0 || a >= n || b < 0 || b >= m) continue;
            if (g[a][b] == 'W' && !vis[a][b]) {
                q.push({a, b});
                vis[a][b] = true;
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
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0 ; j < m ; j++) {
            if (g[i][j] == 'W' && !vis[i][j]) {
                cnt++;
                bfs(i, j);
            }
        }
    }
    cout << cnt;
}