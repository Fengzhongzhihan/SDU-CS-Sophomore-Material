//
// Created by Lenovo on 2024-06-05.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 1010;
int g[N][N];
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int n;
bool vis[N][N];
pair<int, int> last[N][N];

void dfs(int x, int y) {
    if (x != 0 || y != 0) {
        dfs(last[x][y].first, last[x][y].second);
    }
    cout << x << " " << y << endl;
}

void bfs() {
    queue<pair<pair<int ,int >, int>>q;
    q.push({{0,0}, 0});
    while (q.size()) {
        auto t = q.front();
        q.pop();
        int x = t.first.first, y = t.first.second, dis = t.second;
        if (x == n - 1 && y == n - 1) {
            dfs(n - 1, n - 1);
            return;
        }
        for (int k = 0 ; k < 4 ; k++) {
            int a = x + dx[k], b = y + dy[k];
            if (a < 0 || a >= n || b < 0 || b >= n) continue;
            if (g[a][b] == 0 && !vis[a][b]) {
                q.push({{a, b}, dis + 1});
                last[a][b] = {x, y};
                vis[a][b] = true;
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            cin >> g[i][j];
        }
    }
    bfs();
    return 0;
}