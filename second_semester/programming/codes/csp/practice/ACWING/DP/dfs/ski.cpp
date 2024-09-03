//
// Created by Lenovo on 2024-06-03.
//
#include "bits/stdc++.h"
using namespace std;
int n, m;
const int N = 310;
int g[N][N];
int f[N][N];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int res = 0;
int dp(int x, int y) {
    if (f[x][y] != -1) {
        return f[x][y];
    }
    f[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int a = x + dx[i], b = y + dy[i];
        if (a >= 1 && a <= n && b >= 1 && b <= m && g[a][b] < g[x][y]) {
            f[x][y] = max(f[x][y], dp(a, b) + 1);
        }
    }
    return f[x][y];
}

int main() {
    cin >> n >> m ;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    memset(f, -1, sizeof(f));

    for (int i = 1; i <= n ; i++ ) {
        for (int j = 1; j <= m ; j++) {
            res = max(res, dp(i, j));
        }
    }
    cout <<res;
    return 0;
}