//
// Created by Lenovo on 2024-06-05.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 510;
char g[N][N];
int d[N][N];
int n, m, t;

void bfs() {
    deque<pair<int ,int >> q;
    memset(d, 0x3f3f3f3f, sizeof d);
    q.push_back({0, 0});
    d[0][0] = 0;
    int dx[] = {1, 1, -1 ,-1 }, dy[] = {1, -1, -1, 1};
    int ix[] = {-1, -1, 0, 0}, iy[] = {-1, 0, 0 ,-1};
    char cs[] = "\\/\\/";
    while (q.size()) {
        auto t = q.front();
        q.pop_front();
        int x = t.first, y = t.second;
        for (int i = 0 ; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a > n || b < 0 || b > m) continue;
            int ca = a + ix[i], cb = b + iy[i];
            if (ca < 0 || ca > n || cb < 0 || cb > m) continue;
            int w = (g[ca][cb] != cs[i]);
            int dis = d[x][y] + w;
            if (dis < d[a][b]) {
                d[a][b] = dis;
                if (w == 0) {
                    q.push_front({a, b});
                } else {
                    q.push_back({a, b});
                }
            }
        }
    }
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                cin >> g[i][j];
            }
        }
        bfs();
        if (d[n][m]== 0x3f3f3f3f) {
            cout << "NO SOLUTION" << endl;
        } else {
            cout << d[n][m] << endl;
        }
    }
    return 0;
}